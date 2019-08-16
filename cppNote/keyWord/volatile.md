#volatile 三个属性
`易失性`
    从汇编层面来看就是，指令不会直接取包含volatile变量的寄存器数据,
    而是重新从内存中读取
`不可优化`
    编译器在优化代码的时候，可能会对变量进行优化，非volatile变量可能会被直接优化掉，
    volatile关键字告诉编译器不要进行太激进的优化，保证包含volatile变量的代码会被执行

`顺序行`
    编译器可能会对指令进行一些优化，调整指令的执行顺序，volatile变量间的执行顺序不会被编译器修改，
    volatile变量和非volatile变量间的执行顺序可能被调整。

#注意点
    因为volatile的这三个特性，咋一看很符合多线程编程的需要，很多人都在多线程的时候使用
    比如:
    
```cpp
bool flag=false;
int num=0;
void * threadFunc1(void*argv)
{
    if(flag==true){
        cout<<num<<endl;
    }
}

void *threadFunc2(void*argv)
{
    ....
    num=1;      //1  
    flag=true;  //2
}
```
在上面的代码中，如果线程输出num，这个num可能不是预期的1.
编译器可能将//1 和 //2 的指令位置交换了
因为volatile的性质，可能想将flag和num设置为volatile变量

```cpp
volatile bool flag=false;
volatile int num=0;
```
使得编译器不会优化这两个变量的顺序。
但是这是不可靠的，因为就算编译器不会优化了，但是不同体系的cpu的内存模型不一样，
cpu也会调整指令的执行顺序。

针对上面的这个问题，应该使用 happen-befor 的方法，可以使用互斥锁+条件变量

