
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, const char** argv) {
    int fd = open("a.cc", O_RDONLY);

    if (fd == -1)
	{
		printf("File open failed : %s\n", strerror(errno));
	}


    // 定义读取文件的缓冲区
	char buf[1024];
	
	// 执行fork函数
	pid_t pd = fork();
	// 判断fork是否成功
	if (pd == -1)
	{
		printf("fork failed : %s\n", strerror(errno));
	}

    if(pd>0){

        
		read(fd, buf, sizeof(buf));
        printf("child: %s\n",buf);
        close(fd);
    }else{

        sleep(3);
        read(fd, buf, sizeof(buf));
        printf("parent: %s\n",buf);
		close(fd);	
    }
    return 0;
}