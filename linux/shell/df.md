#df
报告文件系统硬盘空间情况

##语法
df [OPTION] ... [FILE]...

##常用方法

显示本地硬盘使用情况
```
[root@isle ~]# df -lh
Filesystem      Size  Used Avail Use% Mounted on
/dev/vda1        40G   24G   14G  64% /
tmpfs           939M     0  939M   0% /dev/shmdu -i
```

显示硬盘inode情况，使用
```
[root@isle ~]# df -i
Filesystem      Inodes  IUsed   IFree IUse% Mounted on
/dev/vda1      2621440 427769 2193671   17% /
tmpfs           240253      1  240252    1% /dev/shmdu -h
```

列出硬盘文件系统使用情况
```
[root@isle ~]# df -T
Filesystem     Type  1K-blocks     Used Available Use% Mounted on
/dev/vda1      ext4   41151808 24937360  14117400  64% /
tmpfs          tmpfs    961012        0    961012   0% /dev/shm
```