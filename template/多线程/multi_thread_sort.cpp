#include<algorithm>
#include<iostream>
#include<vector>
#include<chrono>
#include<ctime>
#include<unistd.h>
#include<pthread.h>


using namespace std;

#define THREADS 	8 
#define	NUM		4000000L
#define RUNS	(NUM/THREADS)

vector<long> nums(NUM);
vector<long> qnums(NUM);
vector<long> sorted_nums(NUM);
vector<long> tt(NUM);

pthread_barrier_t barrier;

int compareLong(const void* a,const void*b){
	return (*(long*)a-*(long*)b);
}

void* thread_func(void* argc) {
	long idx = (long )argc;
	//qsort(nums+idx, RUNS,sizeof(long),compareLong);
	sort(nums.begin()+idx,nums.begin()+idx+RUNS);
	pthread_barrier_wait(&barrier);
	return ((void*)0);
}


void merge() {
	long id[THREADS];
	for(int i = 0; i < THREADS; ++i)
		id[i] = RUNS * i;
	int cur = 0;
	while(cur != NUM) {
		int index = -1;
		for(int i = 0; i < THREADS; ++i) {
			if(id[i] == (RUNS * (i + 1)))
				continue;
			if(index == -1 || nums[id[i]] < nums[id[index]])
				index = i;
		}
		sorted_nums[cur++] = nums[id[index]++];
	}
}

int main(int argc, char*argv[]) {

	srand((unsigned)time(NULL));
	for(int i = 0; i < NUM; ++i)
		tt[i]=qnums[i]=nums[i] = rand()%NUM;


	pthread_t pids[THREADS];

	pthread_barrier_init(&barrier, NULL, THREADS+ 1);

	auto start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < THREADS; ++i)
		pthread_create(&pids[i], NULL, thread_func, (void*)(i * RUNS));

	pthread_barrier_wait(&barrier);
	merge();
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> tm = end - start;	// 毫秒
	std::cout << "time: " << tm.count() << "ms" << std::endl;

	start = std::chrono::high_resolution_clock::now();
	//qsort(qnums,NUM,sizeof(long),compareLong);
	sort(qnums.begin(),qnums.end());
	end = std::chrono::high_resolution_clock::now();
	tm=end-start;
	std::cout << "time: " << tm.count() << "ms" << std::endl;



	return 0;
}
