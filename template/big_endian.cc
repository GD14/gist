#include<bits/stdc++.h>
using namespace std;
void check()
{
    union test{
        int i;
        char c;
    };
    test t;
    t.i=1;
    if(t.c==0x01)
        cout<<"little endian"<<endl;
    else cout<<"big endian"<<endl;
}
int main(int argc,char *argv[]){
    check();
    return 0;
}