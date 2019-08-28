##是否能在构造函数，析构函数中抛出异常？

析构函数中
     1. 不要在析构函数中抛出异常！虽然C++并不禁止析构函数抛出异常，但这样会导致程序过早结束或出现不明确的行为。

     2. 如果某个操作可能会抛出异常，class应提供一个普通函数（而非析构函数），来执行该操作。目的是给客户一个处理错误的机会。

     3. 如果析构函数中异常非抛不可，那就用try catch来将异常吞下，但这样方法并不好，我们提倡有错早些报出来。

构造函数
     1. 构造函数中抛出异常，会导致析构函数不能被调用，但对象本身已申请到的内存资源会被系统释放（已申请到资源的内部成员变量会被系统依次逆序调用其析构函数）。

     2. 因为析构函数不能被调用，所以可能会造成内存泄露或系统资源未被释放。

     3. 构造函数中可以抛出异常，但必须保证在构造函数抛出异常之前，把系统资源释放掉，防止内存泄露。（如何保证？？？使用auto_ptr？？？）

##c++的new的具体实现

分三步
1. 调用operator new(sizeof(A)),得到一个指针
2. 在这个指针地址上调用A:A()
3. 返回指针
   
这里的operator new是可以重载的，比如A:operator new（size_t），如果我们没有重载，默认调用全局的operator new（内部可能是用malloc实现）,不要重载全局的operator new


##glibc中free实现
```c
struct mem_control_block { 
     int is_available; 
     int size; 
};

void free(void *firstbyte) {
     struct mem_control_block *mcb;
/* Backup from the given pointer to find the
  * mem_control_block
  */
    mcb = firstbyte - sizeof(struct mem_control_block);
/* Mark the block as being available */
   mcb->is_available = 1;
/* That''s It!  We''re done. */
   return;
 }
```
##什么是placement new
```cpp
new(p) A()
```
在p这个地址上调用A的构造函数，返回p


##说一下c++多态
c++中多态有两种形式
1. 编译时多态，比如函数重载，在编译的时候就实现了绑定，属于静态绑定
2. 运行时多态，只有在运行时才能实现绑定，属于动态绑定
   