#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>&a,int first,int last,int target)
{
    int count=last-first,step,i;
    while(count>0)
    {
        step=count/2;
        i=first+step;
        if(a[i]<target)
        {
            first=++i;
            count-=step+1;
        }else count=step;
    }
    return first;
}
int upper_bound(vector<int>&a,int first, int last,int target)
{
    int count=last-first,step,i;
    while(count>0)
    {
        step=count/2;
        i=first+step;
        if(!(target<a[i]))
        {
            first=++i;
            count-=step+1;
        }else count=step;
    }
    return first;
}
int main(int argc,char *argv[]){


}