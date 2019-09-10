#include<cstdio>

#define N 1100
int aa;char ch;int getInt(){
	while (ch = getchar(), ch < 48 || ch>57);aa = ch - 48;
	while (ch = getchar(), ch > 47 && ch < 58)aa = aa * 10 + ch - 48;
	return aa;
}


int n;
int data[N][N];
int f[N];
int prime()
{
	int s = 1;
	int i;
	for (i = 1;i <= n;++i)
		f[i] = data[1][i];

	int cost=0;
	int k, j, min;
	for (i = 1;i < n;++i)
	{
		min = 0x3fffff;
		for (j = 1;j <= n;++j)
			if (f[j] > 0 && f[j] < min){
				min = f[j];	k = j;
			}
		for (j = 1;j <= n;++j)
			if (f[j] > 0 && data[k][j] < f[j])
				f[j] = data[k][j];
		cost += min;
	}
	return cost;
}
int main()
{
	n = getInt();
	int i, j;
	for (i = 1;i <= n;++i)
		for (j = 1;j <= n;++j)
			data[i][j] = getInt();

	printf("%d\n",prime());
	return 0;
}