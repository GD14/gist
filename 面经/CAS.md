#CAS
Compare And Swap

CAS机制当中使用了3个基本操作数：内存地址V，旧的预期值A，要修改的新值B

```c
__sync_bool_compare_and_swap(&tail_->next, NULL, newVal);
```
#缺点
1. CPU开销大
2. 不能保证代码块的原子性
3. ABA问题