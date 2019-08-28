
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
void init_deamon(void)
{
    int pid;
    int i;
    //消除父进程设置的掩码.
    //父进程可能设置了mask是(050)
    umask(0);
    //第一子进程,确保自己不是进程组组长
    if (pid = fork())
        exit(0);
    else if (pid < 0) {
        exit(1);
    }

    //第一子进程成为新的会话组长和进程组长
    //与前台进程分离
    setsid();


    //首先创建一个会话leader进程A，
    //接着用A创建子进程B，然后退出A，
    //之后所有进程从B创建，保证所有以后新创建进程都不是会话 leader进程
    //（这是为了防止终端取得进程控制权而采取的保证措施），
    //但是，由于有一个exit进程A的操作，当A退出时，
    //会对本会话的所有进程发送 SIGHUP信号，默认操作是全部退出，而此时是在创建守护进程过程中，必须防止B收到SIGHUP而退出
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGCHLD, &sa, NULL) < 0) { // 注册子子进程退出忽略信号
        return;
    }

    //避免获得一个控制终端
    //只有会话首进程才能关联一个控制终端
    if (pid = fork())
        exit(0); //是第一子进程，结束第一子进程
    else if (pid < 0)
        exit(1); //fork失败

    //关闭父进程打开的文件,避免系统开销
    for (i = 0; i < getdtablesize(); i++)
        close(i);

   
    //改变工作路径
    //比如在/mnt/mmc启动守护进程，
    //但/mnt/mmc已经没有别的用途，你想将它卸载
    chdir("/");
    return;
}

int main()
{
    return 0;
}