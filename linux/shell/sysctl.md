

```shell
#临时修改某个值
sysctl -w net_ipv4.ip_forward=1
echo 1 > /proc/sys/net/ipv4/ip_forward
#显示所有参数
sysctl -a
#从指定文件加载系统参数
sysctl -p 
```