#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <string>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

using namespace std;
std::string curExeName()
{
    char buf[PATH_MAX];
    int ret = readlink("/proc/self/exe", buf, PATH_MAX);
    if (ret < 0 || ret >= PATH_MAX)
        return "";
    string path(buf);
    int pos = path.find_last_of('/');
    if (pos == string::npos)
        return "";
    path = path.substr(pos + 1);
    return path;
}
bool runSingleProc()
{
    string procName = curExeName();
    if (procName.empty()) {
        exit(1);
    }
    string filePath = string("/var/run/") + procName + ".pid";
    int fd = open(filePath.c_str(), O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        printf("open %s error,%s\n", filePath.c_str(), strerror(errno));
        exit(1);
    }

    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_CUR;
    fl.l_len = 0;
    int ret = fcntl(fd, F_SETLK, &fl);
    if (ret < 0) {
        if (errno == EACCES || errno == EAGAIN) {
            printf("%s,alread runing\n", procName.c_str());
            close(fd);
            return false;
        }
    }
    char buf[32] = { '\0' };
    sprintf(buf, "%d", getpid());
    ftruncate(fd, 0);
    lseek(fd, 0, SEEK_SET);
    ret = write(fd, buf, strlen(buf));
    if (ret < 0) {
        printf("write file file,file:%s,error:%s\n", filePath.c_str(), strerror(errno));
        exit(-1);
    }
    // 函数返回时不需要调用close(fd)
    // 不然文件锁将失效
    // 程序退出后kernel会自动close
    return true;
}
int main()
{

    if (!runSingleProc()) {
        return 1;
    }
    for (;;) {
        printf("1\n");
        sleep(5);
    }
    return 0;
}