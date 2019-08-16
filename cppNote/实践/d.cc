#include <bits/stdc++.h>
class test {
public:
    test(){std::cout<<"xxx"<<std::endl;}
    ~test(){std::cout<<"hhh"<<std::endl;}

private:
};

int main(int argc,char *argv[]){
    test * p=new test();
    test* q=new test;

    p->~test();
    return 0;
}