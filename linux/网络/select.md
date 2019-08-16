##select

```c
//插入一个fd
void FD_SET(int fd,fd_set*set);
//删除一个fd
void FD_CLR(int fd,fd_set*set);
//判断一个fd
int FD_ISSET(int fd,fd_set*set);
//清空bitmap
void FD_ZERO(FD_SET*set);

//wait阻塞
int select(int nfds,fd_set*readfds,fd_set*writefds,fd_set*exceptfds,struct timeval*timeout);


struct timeval{
    long tv_sec;    /*second*/
    long tv_usec;   /*microseconds*/
};
```


##存在的问题
select是最早的I/O多路复用的方法。用结构体struct fd_set来告诉内核要监控哪些fd。通过三个宏定义来插入/删除/查询fd，最后当监控的fd有事件发生的时候，通过轮询的方法检查每一个fd是否发生了事件。
存在的问题是：

1. fd_set的能监控的fd数量受最大文件数限制。

2. 每次调用select前都需要重新初始化fd_set集合，select返回时候，将fd_set从内核空间拷贝到用户空间
3. 轮询的时候效率很慢。