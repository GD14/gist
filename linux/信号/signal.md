
#linux信号
信号的处理由三种方式:
1. 忽略
2. 捕捉
3. 默认动作
默认动作都是结束进程

```c
typedef void(*sighandler_t)(int);

//SIG_IGN
//SIG_DFL
//在多线程中,signal的作用是未定的
//signal是不可移植的，除了上面两个动作
sighandler_t signale(int signum,sighandler_t handler);


int sigaction(int signum,const struct sigaction*act,
struct sigaction*oldact);
```
##SIGKILL
 无法被捕捉，无法被忽略 所以Kill -9 pid一定可以杀死进程
##SIGSTOP
无法被捕捉，无法被忽略
##SIGHUP
1、终端关闭时，该信号被发送到 session 首进程以及作为 job 提交的进程（即用 & 符号提交的进程）

2、session首进程退出时，该信号被发送到该 session 中的前台进程组中的每一个进程，但不会发送给 job  提交的进程。

3、若父进程退出导致进程组成为孤儿进程组，且该进程组中有进程处于停止状态（收到SIGSTOP或SIGTSTP信号），该信号会被发送到该进程组中的每一个进程。

终端关闭的情景如断网或者手动关闭了会话窗口，这时即便你的命令 & 了，仍然会被 SIGHUP 信号中断。
##SIGTERM
请求终止进程，Kill命令缺省发送该信号
大部分程序接收到SIGTERM信号后，会先释放自己的资源，然后在停止。但是也有程序可以在接受到信号量后，做一些其他的事情，并且这些事情是可以配置的。如果程序正在等待IO，可能就不会立马做出相应。也就是说，SIGTERM多半是会被阻塞的、忽略。

和SIGINT的区别，子进程不会收到该信号，子进程的父进程会变成1号进程
##SIGINT
按下CTRL+C之后，发送SIGINT到
和SIGTERM的区别：子进程也会收到这个信号

##SIGCHILD
进程结束时候，SIGCHILD会发送给它的父进程。


##SIGPIPE
向关闭了read的socket/pipe写数据

##SIGALRM
用alarm函数设置的timer超时或者settimer函数设置的interval timer超时




