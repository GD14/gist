
```shell
#修改用户最大进程
ulimit -u 10000
#修改进程最大描述符
ulimit -n 4096

ulimit -d unlimited
ulimit -m unlimited
ulimit -s unlimited
ulimit -t unlimited
ulimit -v unlimited
```