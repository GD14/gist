
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void init_deamon(void)
{
    int pid;
    int i;
    //第一子进程,确保自己不是进程组组长
    if(pid=fork())
        exit(0);
    else if(pid<0)
    {
        exit(1);
    }


    //第一子进程成为新的会话组长和进程组长
    //与前台进程分离
    setsid();
    
    //避免获得一个控制终端
    //只有会话首进程才能关联一个控制终端
    if(pid=fork())
        exit(0);//是第一子进程，结束第一子进程
    else if(pid<0)
        exit(1);//fork失败


    //关闭父进程打开的文件,避免系统开销
    for(i=0;i<getdtablesize();i++)
        close(i);

    //消除父进程设置的掩码.
    //父进程可能设置了mask是(050)
    umask(0);
    //改变工作路径
    //比如在/mnt/mmc启动守护进程，
    //但/mnt/mmc已经没有别的用途，你想将它卸载
    chdir("/");
    return ;
}

int main(){
    return 0;
}