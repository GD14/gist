#include <bits/stdc++.h>
using namespace std;

template <class T>
unsigned int hashCode(const T& a)
{
    static int maxSize = 10000007;
    static int factor = 27;
    auto n = sizeof(a);
    unsigned char* p = (unsigned char*)(&a);
    unsigned int code = 0;
    for (int i = 0; i < n; i++) {
        code = code * factor + *p;
        p = p + 1;
        if (code > maxSize)
            code %= maxSize;
    }
    return code;
}

int main(int argc, char* argv[])
{
    int a = 134;
    cout << hashCode(a) << endl;
    string s = "1123";
    cout << hashCode(s) << endl;
    return 0;
}