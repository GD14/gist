#Multi-Version Concurency control

与MVCC相对的，是基于锁的并发控制，Lock-Based Concurrency Control

MVCC最大的好处：读不加锁，读写不冲突。在读多写少的OLTP应用中，读写不冲突是非常重要的，极大的增加了系统的并发性能，这也是为什么现阶段，几乎所有的RDBMS，都支持了MVCC。
在MVCC并发控制中，读操作可以分成两类：快照读 (snapshot read)与当前读 (current read)。快照读，读取的是记录的可见版本 (有可能是历史版本)，不用加锁。当前读，读取的是记录的最新版本，并且，当前读返回的记录，都会加上锁，保证其他事务不会再并发修改这条记录
##快照读 Snapshot Read

简单的select操作，属于快照读，不加锁。(当然，也有例外，下面会分析)

```sql
select * from table where id=1;
```

##当前读 Current Read
特殊的读操作，插入/更新/删除操作，属于当前读，需要加锁。

```sql
#s锁
select * from table where id=1 lock in share mode;
#x锁
select * from table where id=1 for update;
#x锁
insert into table values(1)
#x锁
update table set age=10 where id=1;
#x锁
delete from table where id=1;
```
为什么插入/更新/删除都被归为当前读呢,

一个update操作的具体操作，当update的sql 被发给mysql之后，mysql server会根据where条件，向Innodb读取第一条满足条件的记录，innodb将第一条记录加锁返回(current read),mysql server 收到这条current read之后，再发起一个update请求，更新这条记录。再读取下一条记录，直到没有满足条件的记录。
同理，Delete操作也一样
Insert操作会稍微有些不同，简单来说，就是Insert操作可能会触发Unique Key的冲突检查，也会进行一个当前读。  