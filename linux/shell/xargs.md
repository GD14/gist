#xargs
xargs将输入中的数据作为命令的参数，以空格和\n分割

```shell
#利用xargs来格式化,每行最多一个,默认调用echo
cat file| xargs -n1 
cat file| xargs -n1 echo 
```