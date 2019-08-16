#epoll
```c
//szie被忽略了但必须大于0
//返回一个epfd
int epoll_create(int size);

//op可以是EPOLL_CTL_ADD,EPOLL_CTL_DEL
//fd是要加入或者删除的，
//event
//返回-1失败
int epoll_ctl(int epfd,int op,int fd,struct epoll_event*event);

//events是指定的接收数组
//maxevents是接受数组的长度
//timeouts是超时毫秒级 
int epoll_wait(int epfd,struct epoll_event*events,int maxevents,int timeouts);



ev.events=EPOLLIN|EPOLLET
ev.data.fd=connfd;
if(epoll_ctl(epfd,EPOLL_CTL_ADD,connfd,&ev)==-1)
{
    exit(-1);
}

struct epoll_event{
    uint32_t events;
    epoll_data_t data;
}
 
```

#select,poll和epoll的区别

##原理
>红黑树+链表

  
epoll在内核中拥有一个虚拟的文件系统和一块cache,当调用 `epoll_create`
时候，在内核会在这个虚拟的文件系统上创建一个fd节点,并在这个cache中创建一棵关联这个fd的红黑树和一个链表。

我们使用epoll_ctl就是在这个红黑树中添加，修改，删除sock_fd,并且通过在系统中断处理中注册一个回调函数，如果这个fd有关注的事件发生，就放在链表中。所以当一个sock_fd有数据到达内核把网卡上的数据copy到内核中，并把sockfd放入链表


epoll_wait会把内核中这个fd关联的链表copy到用户空间


## 边缘触发 edge triggle
只有在缓冲区新增加数据的那一刻才会触发
**边缘触发必须使用非阻塞**
因为每次发消息只会触发一次(不管缓存区是否还留有数据)，所以必须把数据一次性读取出来，否则会影响下一次消息。如果阻塞了的话其他fd的

## 水平触发 level triggle
只要缓冲区有数据就会一直触发
## ET和LT的区别

EPOLLET和非ET的区别就在这一步之差呀~
如果是ET, epitem是不会再进入到readly list,
除非fd再次发生了状态改变, ep_poll_callback被调用.
 如果是非ET, 不管你还有没有有效的事件或者数据,
都会被重新插入到ready list, 再下一次epoll_wait
时, 会立即返回, 并通知给用户空间. 当然如果这个
被监听的fds确实没事件也没数据了, epoll_wait会返回一个0,空转一次.

在源码中，两种模式的区别是一个if判断语句，通过ep_send_events_proc()函数实现，如果没有标上EPOLLET(即默认的LT)且“事件被关注”的fd就会被重新放回了rdllist。那么下次epoll_wait当然会又把rdllist里的fd拿来拷给用户了。

## 步骤
1. 网卡接受数据，将数据存放在内存
2. 当网卡将数据放到内存后，网卡向CPU发送一个中断信号，操作系统便得知有数据到来，通过网卡的中断处理程序去处理数据
3. 进程状态有等待和运行，当进程阻塞的时候会被放入一个等待队列，可执行的进程会被放入一个工作队列。当创建一个socket时候，内核会创建一个socket对象，包含了发送缓存，接受缓存，等待列表。当还没有数据的时候，我们调用recv时候，进程就会被放入该socket对象的等待队列，所有进程会被阻塞，当socket接受到数据时候，操作系统将进程从等待队列中放回工作队列，状态变成运行。这时候recv可以返回数据了。
4. 
#epoll惊群
如果多个进程/线程阻塞在监听同一个监听socket fd的epoll_wait上，当有一个新的连接到来时，所有的进程都会被唤醒。

场景：
主进程创建socket，bind，listen后，将该socket加入到epoll中，然后fork出多个子进程，每个进程都阻塞在epoll_wait上，如果有事件到来，则判断该事件是否是该socket上的事件如果是，说明有新的连接到来了，则进行接受操作。为了简化处理，忽略后续的读写以及对接受返回的新的套接字的处理，直接断开连接

##源码
1. eventpoll
```c
// epoll的核心实现对应于一个epoll描述符  
struct eventpoll {  
    spinlock_t lock;  
    struct mutex mtx;  
    wait_queue_head_t wq; // sys_epoll_wait() 等待在这里  
    // f_op->poll()  使用的, 被其他事件通知机制利用的wait_address  
    wait_queue_head_t poll_wait;  
    //已就绪的需要检查的epitem 列表 
    struct list_head rdllist;  
    //保存所有加入到当前epoll的文件对应的epitem  
    struct rb_root rbr;  
    // 当正在向用户空间复制数据时, 产生的可用文件  
    struct epitem *ovflist;  
    /* The user that created the eventpoll descriptor */  
    struct user_struct *user;  
    struct file *file;  
    //优化循环检查，避免循环检查中重复的遍历
    int visited;  
    struct list_head visited_list_link;  
};
```

2. epitem
```c
// 对应于一个加入到epoll的文件  
struct epitem {  
    // 挂载到eventpoll 的红黑树节点  
    struct rb_node rbn;  
    // 挂载到eventpoll.rdllist 的节点  
    struct list_head rdllink;  
    // 连接到ovflist 的指针  
    struct epitem *next;  
    /* 文件描述符信息fd + file, 红黑树的key */  
    struct epoll_filefd ffd;  
    /* Number of active wait queue attached to poll operations */  
    int nwait;  
    // 当前文件的等待队列(eppoll_entry)列表  
    // 同一个文件上可能会监视多种事件,  
    // 这些事件可能属于不同的wait_queue中  
    // (取决于对应文件类型的实现),  
    // 所以需要使用链表  
    struct list_head pwqlist;  
    // 当前epitem 的所有者  
    struct eventpoll *ep;  
    /* List header used to link this item to the &quot;struct file&quot; items list */  
    struct list_head fllink;  
    /* epoll_ctl 传入的用户数据 */  
    struct epoll_event event;  
};
```

3. eppoll_entry
```c
// 与一个文件上的一个wait_queue_head 相关联，因为同一文件可能有多个等待的事件，
//这些事件可能使用不同的等待队列  
struct eppoll_entry {  
    // List struct epitem.pwqlist  
    struct list_head llink;  
    // 所有者  
    struct epitem *base;  
    // 添加到wait_queue 中的节点  
    wait_queue_t wait;  
    // 文件wait_queue 头  
    wait_queue_head_t *whead;  
}; 
```


epoll_create()

```
//先进行判断size是否>=0，若是则直接调用epoll_create1
SYSCALL_DEFINE1(epoll_create, int, size)
{
        if (size <= 0)
                return -EINVAL;
        return sys_epoll_create1(0);
}
```

epoll_create1()

```c
/* 这才是真正的epoll_create啊~~ */
SYSCALL_DEFINE1(epoll_create1, int, flags)
{
    int error;
    struct eventpoll *ep = NULL;//主描述符
    /* Check the EPOLL_* constant for consistency.  */
    /* 这句没啥用处... */
    BUILD_BUG_ON(EPOLL_CLOEXEC != O_CLOEXEC);
    /* 对于epoll来讲, 目前唯一有效的FLAG就是CLOEXEC */
    if (flags & ~EPOLL_CLOEXEC)
        return -EINVAL;
    /*
     * Create the internal data structure ("struct eventpoll").
     */
    /* 分配一个struct eventpoll, 分配和初始化细节我们随后深聊~ */
    error = ep_alloc(&ep);
    if (error < 0)
        return error;
    /*
     * Creates all the items needed to setup an eventpoll file. That is,
     * a file structure and a free file descriptor.
     */
    /* 这里是创建一个匿名fd, 说起来就话长了...长话短说:
     * epollfd本身并不存在一个真正的文件与之对应, 所以内核需要创建一个
     * "虚拟"的文件, 并为之分配真正的struct file结构, 而且有真正的fd.
     * 这里2个参数比较关键:
     * eventpoll_fops, fops就是file operations, 就是当你对这个文件(这里是虚拟的)进行操作(比如读)时,
     * fops里面的函数指针指向真正的操作实现, 类似C++里面虚函数和子类的概念.
     * epoll只实现了poll和release(就是close)操作, 其它文件系统操作都有VFS全权处理了.
     * ep, ep就是struct epollevent, 它会作为一个私有数据保存在struct file的private指针里面.
     * 其实说白了, 就是为了能通过fd找到struct file, 通过struct file能找到eventpoll结构.
     * 如果懂一点Linux下字符设备驱动开发, 这里应该是很好理解的,
     * 推荐阅读 <Linux device driver 3rd>
     */
    error = anon_inode_getfd("[eventpoll]", &eventpoll_fops, ep,
                 O_RDWR | (flags & O_CLOEXEC));
    if (error < 0)
        ep_free(ep);
    return error;
}
```