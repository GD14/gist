#task_struct
描述进程的信息

```c
struct task_struct{
    volatile long state;
    int exit_state;
}
```
state的取值可能有
|表示|含义|
|---|---|
|TASK_RUNNING|运行|
|TASK_INTERRUPTBLE|可中断的等待状态|
|TASK_UNINTERRUPBLE|不可中断的等待状态|
|TASK_ZOMBIE|僵死|
|TASK_STOPPED|暂停|
|TASK_SWAPPING|换入/换出|


```c
struct task_struct{
    pid_t pid;
    pid_t tgid;
}
```

进程内核栈
```c
struct task_struct{
    void *stack
}
```

```c
struct task_struct{
    unsigned int flags
}
```

##进程亲属
```c
struct task_struct{
    struct task_struct *real_parent;
    struct task_struct *parent;
    struct list_head children;
    struct list_head sibling;
    struct task_struct *group_leader;
}
```


##ptrace系统调用
```c
struct task_struct{
    unsigned int ptrace;
    struct list_head ptraced;
    struct list_head ptrace_entry;
}
```