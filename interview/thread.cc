
#include <bits/stdc++.h>
using namespace std;

mutex m;
int i=0;
condition_variable cv;

void printOne()
{
    cout << "1" << endl;
    {
        unique_lock<mutex> lock(m);
        i += 1;
        cv.notify_all();
    }
}
void printTwo()
{
    unique_lock<mutex> lock(m);
    while (i != 1)
        cv.wait(lock);
    i += 1;
    cout << "2" << endl;
    cv.notify_all();
}
void printThree()
{
    unique_lock<mutex> lock(m);
    while(i!=2)
    cv.wait(lock);
    cout << "3" << endl;
}

int main(int argc, char* argv[])
{
    thread t1(printOne);
    thread t3(printThree);
    thread t2(printTwo);
    t1.detach();
    t2.detach();
    t3.detach();
    return 0;
}