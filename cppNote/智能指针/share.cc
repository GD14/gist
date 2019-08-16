#include <bits/stdc++.h>
using namespace std;

template <typename T>
class shared_pointer {
private:
    T* ptr_;
    int* count;

public:
    shared_pointer(T* p)
        : count(new int(1))
        , ptr_(p)
    {
    }
    shared_pointer(shared_pointer<T>& rhs)
        : count(&(++*rhs.count))
        , ptr_(rhs.ptr_)
    {
    }
    T* operator->()
    {
        return ptr_;
    }
    T& operator*()
    {
        return *ptr_;
    }

    shared_pointer<T>& operator=(shared_pointer<T>& rhs)
    {
        ++*rhs.count;
        if (this->ptr_ && 0 == --*this->count) {
            delete count;
            delete this->ptr_;
        }
        this->ptr_ = rhs->ptr_;
        this->count = rhs->count;
        return *this;
    }

    ~shared_pointer()
    {
        if (--*count == 0) {
            delete count;
            delete ptr_;
        }
    }
};
int main(int argc, char* argv[])
{
    shared_pointer<int> sp(new int(1));
    shared_pointer<int> p2=sp;
    cout<<*p2<<endl;
    return 0;
}