
##accept惊群
  主进程创建了socket、bind、listen之后，fork()出来多个进程，每个子进程都开始循环处理（accept）这个listen_fd。每个进程都阻塞在accept上，当一个新的连接到来时候，所有的进程都会被唤醒，但是其中只有一个进程会接受成功，其余皆失败，重新休眠
但是这个问题被Linux内核解决了
当多个进程/线程都阻塞在对同一个socket的接受调用上时，当有一个新的连接到来，内核只会唤醒一个进程，其他进程保持休眠，压根就不会被唤醒。

##错误码
当accept被设置为nonblocking的时候，因为在poll和accept之间有一段间隔时间，而这期间peer可能RESET连接了，可能出现一些错误，但是是可以被忽略的:
-   EAGAIN      (连接被废弃了,但是系统不返回错误只是将连接从完成连接的队列移除)
-   EWOULDBLOCK (可能和EAGANT一样)
-   ECONNABORTED    (连接被abort,可能在accept之前收到了RST)
-   EPROTO          (有可能连接被aborted,先收到了RST) 
-   EINTR   (系统中断)
-   EPERM   (权限问题,可能被防火墙进制了)
-   EMFILE  