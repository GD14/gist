#include <bits/stdc++.h>

using namespace std;

template <typename T>
class unique_pointer {
private:
    T* ptr_;

public:
    unique_pointer(T* ptr = nullptr)
        : ptr_(ptr)
    {
    }
    ~unique_pointer()
    {
        delete ptr_;
    }

    unique_pointer(const unique_pointer<T>& rhs) = delete;
    void operator=(const unique_pointer<T>& rsh) = delete;
    T& operator*()
    {
        return *ptr_;
    }
};
int main(int argc, char* argv[])
{

    unique_pointer<int> p(new int(10));
    cout<<*p<<endl;
    return 0;
}