#du
计算文件所占的空间大小

## 语法
> du [OPTION] ... [FILE] ...
> du [OPTION] ... --files0-from=F


## 描述
计算每一个文件的硬盘使用情况，对文件夹递归计算。

-a
    计算所有的文件，不只文件夹

--apparent-size
    打印表面上的大小，而不是硬盘大小。尽管表面大小一般比硬盘空间小，但是也有可能会大，比如"空洞"文件,

-B,--block-size=SIZE
    使用SIZE-byte blocks

-b,--bytes
    equeivalent to '--apparent-size --block-size=1'

-h
    方便阅读

-c, --total 
    生成一个统计