#proc 伪文件系统
proc 是一个伪文件系统，挂载在/proc上面，作为内核数据结构的接口，大部分都是只读的，
但是也有可以修改的部分。

#目录结构

> /proc/[pid]
    对于每一个running进程，都有这样一个文件夹

> /proc/[pid]/auxv


>/proc/[pid]/cmdline
执行这个进程的完整的命令，除非这个进程是僵尸进程（read返回0)

>/proc/[pid]/cwd

进程当前目录的符号链接

>/proc/[pid]/environ
包含了进程的环境，使用'\0'作为分隔符，一般这样来查看
(cat /proc/1/environ; echo) | tr '\000' '\n'

>/proc/[pid]/exe


>/proc/[pid]/fd


>/proc/[pid]/fdinfo


>/proc/[pid]/limits
包含了进程的所有软限制和硬限制

>/proc/[pid]/maps
进程的 mapped memory regions 和他们的访问权限

> address         perms offset  dev   inode   pathname
08048000-08056000 r-xp 00000000 03:0c 64593   /usr/sbin/gpm
08056000-08058000 rw-p 0000d000 03:0c 64593   /usr/sbin/gpm
08058000-0805b000 rwxp 00000000 00:00 0
40000000-40013000 r-xp 00000000 03:0c 4165    /lib/ld-2.2.4.so
40013000-40015000 rw-p 00012000 03:0c 4165    /lib/ld-2.2.4.so
4001f000-40135000 r-xp 00000000 03:0c 45494   /lib/libc-2.2.4.so
40135000-4013e000 rw-p 00115000 03:0c 45494   /lib/libc-2.2.4.so
4013e000-40142000 rw-p 00000000 00:00 0
bffff000-c0000000 rwxp 00000000 00:00 0


>/proc/[pid]/mem
    可以通过open/read/lseek 操作这个文件，达到访问进程内存的目的

>/proc/[pid]/mountinfo

 /proc/[pid]/mounts

 /proc/[pid]/mountstats

  /proc/[pid]/root


  /proc/[pid]/smaps
  对于一个进程的内存统计，对每一个map都有以下字段
08048000-080bc000 r-xp 00000000 03:02 13130      /bin/bash
Size:               464 kB
Rss:                424 kB
Shared_Clean:       424 kB
Shared_Dirty:         0 kB
Private_Clean:        0 kB
Private_Dirty:        0 kB



/proc/[pid]/smaps


>/proc/[pid]/stat
这个包含了进程状态，也是ps命令使用到的信息


>/proc/[pid]/statm
内存的使用情况，按页计算

>/proc/[pid]/status
更方便人阅读

>/proc/[pid]/task
对于每一个线程都有一个子文件夹