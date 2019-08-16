#const_cast

将const变量转非const

```cpp

const int a;
const_cast<int*>(&num)

```
#static_cast
各种隐式转换,比如非const转const，void* 转char *,多态可以向上转型
#dynamic_cast
用于动态类型转换,只能用于含有虚函数的类。用于类层次的向上和向下转化。只能转换指针或引用类型，向下转时候，如果非法返回NULL指针。
原理是虚函数表-1的地方有type_info的指针

#reinterpret_cast
类似于强制转换


