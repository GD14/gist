
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

##SIGTERM
请求终止进程，Kill命令缺省发送该信号
1.程序立刻停止

##SIGCHILD
进程结束时候，SIGCHILD会发送给它的父进程。

##SIGINT
按下CTRL+C之后，发送SIGINT到

##SIGPIPE
向关闭了read的socket/pipe写数据

##SIGALRM
用alarm函数设置的timer超时或者settimer函数设置的interval timer超时




