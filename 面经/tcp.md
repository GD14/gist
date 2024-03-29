##tcp和udp的区别
1. TCP面向连接,进行通信前，双方需要先建立一个 TCP 连接;UDP是无连接的，即发送数据之前不需要建立连接

2. TCP提供可靠的服务。确保数据无差错，不丢失，不重复，且按序到达，原理是使用了序列号、确认应答，超时重传;UDP尽最大努力交付，即不保证可靠交付

3. TCP提供拥塞控制，利用慢启动，快速重传。UDP没有拥塞控制，因此网络出现拥塞不会使源主机的发送速率降低（对实时应用很有用，如IP电话，实时视频会议等）
   
4. TCP面向字节流，(意思tcp有接受和发送缓存，数据会被缓存起来，上层应用按字节消费数据);UDP是面向报文的，每次读取都是一个整的报文大小的数据，超过最大报文的数据会被丢弃，报文之间不会合并。

5. 每一条TCP连接只能是点到点的;UDP支持一对一，一对多，多对一和多对多的交互通信

6. TCP首部开销20字节;UDP的首部开销小，只有8个字节

##TCP和udp的应用场景
**TCP**：
当对网络通讯质量有要求的时候，比如：整个数据要准确无误的传递给对方，这往往用于一些要求可靠的应用，比如HTTP、HTTPS、FTP等传输文件的协议，POP、SMTP等邮件传输的协议。 
在日常生活中，常见使用TCP协议的应用如下：
浏览器，用的HTTP
FlashFXP，用的FTP
Outlook，用的POP、SMTP
Putty，用的Telnet、SSH

**UDP**：
当对网络通讯质量要求不高的时候，要求网络通讯速度能尽量的快，这时就可以使用UDP。 
比如，日常生活中，常见使用UDP协议的应用如下：
QQ语音
QQ视频
TFTP

##OSI七层模型
应用层：HTTP FTP SMTP
表示层：数据的表示，安全和压缩
会话层：
传输层：传输数据的协议端口号，流量控制和差错校验
网络层：进行逻辑地址寻址 ICMP IP ARP RARP
数据链路层：
物理层：

##TCP/IP协议模型
应用层
传输层
IP层次
网络接口层
##tcp流量控制
为了提高效率，tcp发送端一次性可以发送多个报文，接收端可以缓存起来。但是发送端可能发送太块，导致缓冲区满了，
接收放通过窗口大小字段告诉发送端自己的接受缓存还有多大，这样发送端就可以避免发送过多的数据

##tcp拥塞控制
慢启动
刚开始发一个MSS cwnd=1
接下来2个MSS cwnd=2
接下来4个MSS cwnd=5
如果超过阈值的大小，就变成每次加1个MSS
如果发现拥塞了，就将阈值=cwnd/2

重新开始慢启动

快速重传，如果丢包3次，就判断网络拥塞，
##TCP拥塞控制和流量控制区别

相同点：
都会发现丢包
发送方的发送速率都会被降下来

不同点
流量控制丢包是在接收端的缓冲区，而拥塞控制是在路由器的缓冲区。
流量控制针对的是一个连接的双方，拥塞控制针对的是整个网络。
##UDP包大小最大多少

一般情况下以太网的MTU是1500,IP报文头20个字节，

UDP报头8个字节(源端口+目的端口+长度+校验码)
所以理论上可以是1472个字节

但是Internet上标准的MTU是576，因为Internet上的路由器可能会将MTU设为不同的值。如果我们假定MTU为1500来发送数据，而途经的某个网络的MTU值小于1500字节
所以最好控制在576-20-8=548

##在浏览器输入baidu.com会之后发生了什么
1.浏览器将这个域名解析为IP地址，这里需要用到DNS协议，首先主机会查询DNS的缓存，如果没有就给本地的dns服务器发送查询请求，这里主要有两种发生，一种是递归查询，一种是迭代查询。如果使用递归查询，本地服务器继续向其他根服务器发生查询报文，根服务器向顶级服务器查询。

2.与服务器建立TCP连接

3.server上的有web服务器来出处理我们的请求

4.浏览器接到http相应