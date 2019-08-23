#include <bits/stdc++.h>

using namespace std;

//永远不要在构造函数中调用虚函数
//1.在基类构造函数中调用虚函数，调用的是基类的函数，
//此时子类还未构造完成，如果编译器允许调用子类的虚函数就可能出现问题
//2.
class base {
public:
    base()
    {
        foo();
    }
    virtual void foo()
    {
        cout << "base" << endl;
    }
};

class driver : public base {
public:
    driver()
    {
        foo();
    }
    virtual void foo()
    {
        cout << "driver" << endl;
    }
};
int main(int argc, char* argv[])
{
    driver d;
    return 0;
}