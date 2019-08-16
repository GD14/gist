1. 变量的生明和定义中
2. 在多个文件中共享const对象
```c
    //file1.cpp定义并初始化和一个常量，该常量能被其他文件访问
extern const int bufferSize = function();
//file1.h头文件
extern const int bufferSize; //与file1.cpp中定义的是同一个
```
3. extern 'c'