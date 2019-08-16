

#poll
```c
int poll(struct pollfd*fds,nfds_t nfds,int timeout);
struct pollfd{
    int fd;
    short event;
    short revent;
}
```

#问题
poll 通过pollfd *数组解决了select文件描述符数量受限的问题，并且不需要重复的初始化.但是仍然没有解决需要轮询的问题。

#什么时候可读
当fd是nonblocking时候
    revent&(POLLIN|POLLPRI|POLLRDHUP)

#什么时候写
当fd是nonblocking时候
    revent&(POLLOUT)

#什么时候出错
当fd是