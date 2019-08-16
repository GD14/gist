#include <bits/stdc++.h>
using namespace std;
void printf(char a[100])
{

    cout<<sizeof(a)<<endl;
    cout<<strlen(a)<<endl;
}
int main(int argc, char* argv[])
{
    char a1[] = "abcdef\0gh";
    char a2[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0', 'g', 'h' };
    cout<<sizeof(a1)<<endl;
    cout<<sizeof(a2)<<endl;
    printf(a1);
    return 0;
}