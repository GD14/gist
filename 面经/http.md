#http和https的区别
1. http协议是以名为的方式在网络传输的，而https协议传输的数据是经过TLS加密后的，Https具有更高的安全性
2. https在tcp三次握手之后，还有经历一个ssl的握手阶段，协商加密使用的对此加密密钥
3. https协议协议服务器申请证书，客户端要安装对应的根证书
4. http协议端口是80，https协议端口是443

https的优点
使用了密钥加密，安全性高
https的缺点
握手阶段延时高
加密过程占用cpu资源
需要部署证书

#报头
Request Header:
```
GET /sample.Jsp HTTP/1.1  //请求行
Host: www.uuid.online/  //请求的目标域名和端口号
Origin: http://localhost:8081/  //请求的来源域名和端口号 （跨域请求时，浏览器会自动带上这个头信息）
Referer: https:/localhost:8081/link?query=xxxxx  //请求资源的完整URI
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36 //浏览器信息
Cookie: BAIDUID=FA89F036:FG=1; BD_HOME=1; sugstore=0  //当前域名下的Cookie
Accept: text/html,image/apng  //代表客户端希望接受的数据类型是html或者是png图片类型 
Accept-Encoding: gzip, deflate  //代表客户端能支持gzip和deflate格式的压缩
Accept-Language: zh-CN,zh;q=0.9  //代表客户端可以支持语言zh-CN或者zh(值得一提的是q(0~1)是优先级权重的意思，不写默认为1，这里zh-CN是1，zh是0.9)
Connection: keep-alive  //告诉服务器，客户端需要的tcp连接是一个长连接

```

Response Header:
```
HTTP/1.1 200 OK  // 响应状态行
Date: Mon, 30 Jul 2018 02:50:55 GMT  //服务端发送资源时的服务器时间
Expires: Wed, 31 Dec 1969 23:59:59 GMT //比较过时的一种验证缓存的方式，与浏览器（客户端）的时间比较，超过这个时间就不用缓存（不和服务器进行验证），适合版本比较稳定的网页
Cache-Control:  no-cache  // 现在最多使用的控制缓存的方式，会和服务器进行缓存验证，具体见博文”Cache-Control“
etag: "fb8ba2f80b1d324bb997cbe188f28187-ssl-df"  // 一般是Nginx静态服务器发来的静态文件签名，浏览在没有“Disabled cache”情况下，接收到etag后，同一个url第二次请求就会自动带上“If-None-Match”
Last-Modified: Fri, 27 Jul 2018 11:04:55 GMT //是服务器发来的当前资源最后一次修改的时间，下次请求时，如果服务器上当前资源的修改时间大于这个时间，就返回新的资源内容
Content-Type: text/html; charset=utf-8  //如果返回是流式的数据，我们就必须告诉浏览器这个头，不然浏览器会下载这个页面，同时告诉浏览器是utf8编码，否则可能出现乱码
Content-Encoding: gzip  //告诉客户端，应该采用gzip对资源进行解码
Connection: keep-alive  //告诉客户端服务器的tcp连接也是一个长连接
```

#状态码

- 200   OK
- 201   Created
- 202   Accepted
- 203
- 204

- 300   Multiple Choices
- 301   Moved Permanently
- 302   Found
- 303   See Other
- 304   Not Modified
- 305
- 306
- 307   Temporary Redirect

- 400   Bad Request
- 401   Unauthorized
- 402
- 403   Forbidden
- 404   Not Found
- 405   Method Not Allowd
- 406   Not Acceptable

- 500   Internal Server Error
- 501
- 502
- 503   Service Unavailable
- 504
#断点续传
使用字段range
Range：bytes=5001-10000
表示需要5001到1000的数据
Range: bytes=5000-
表示需要5000之后的数据

Range: bytes=-3000,5000-7000
多范围
#单点登陆
每个web server都有自己的session，在分布式情况下或集群情况下统一session。
比如用户中心，订单系统
##解决办法
把session存储在redis中，统一管理对外提供服务接口，redis可以设置过期时间，对应session失效

1.  登录，根据用户名和密码查询数据库，如存在则生成token保存在redis，token作为key，用户信息作为value，设置过期时间，然后把token保存到cookie，固定key，token作为value；

2.  根据token查询用户信息，根据token作为key查询redis的值，如存在重新设置过期时间（即已登录），不存在即未登录

3.  登出，根据token作为key删除redis的值

#cookie
cookie是一个存储在客户端的字符串属性,可以用它对当前网页的cookie进行读,写,增.删等操作

cookie四个可选属性
1. expires，过期时间，默认情况cookie只在浏览器会话期间存在，退出浏览器就丢失，通过设置过期时间，退出只会也不会丢失。
2. path属性：默认情况下，在同一个目录下跨域调用,例如在http://a.com/p1/1.html设置的
   cookie可以被http:/a.com/p1/2.html调用，但是不能被http://a.com/p2/1.html调用

3. domain:设置从.a.com,则*.a.com都可以访问

4. 安全属性，http默认为false https为true
##局限性
浏览器保存的cookie数量有限，单个web服务器最多只能保存20个左右，大小还有限制


#301和302的区别

两个都是请求重定向，就是用户都可以看到url变成了一个新的，然重新发出请求。

但是两者有区别

##301 适合永久重定向
一种比较常见的场景是域名跳转
比如我们输入http://www.baidu.com
会获得一个301状态吗，然后返回一个location，提示新的地址，浏览器会拿着这个新的地址去访问跳转到https://www.baidu.com。

301请求是可以缓存的

##302 时候临时重定向
一种常用的场景是未登录的用户访问用户中心重定向到登陆页面
访问404页面重新定向到首页。



##nginx 301/302配置

```c
//把来自veryyoung.me的请求301跳到 www.veryyoung.me
if ($host != 'veryyoung.me') {
    rewrite ^/(.*)$ http://www.veryyoung.me/$1 permanent;
}
```

```c
//把来自veryyoung.me的请求302跳到 www.veryyoung.me
if ($host != 'veryyoung.me') {
    rewrite ^/(.*)$ http://www.veryyoung.me/$1 redirect;
}
```
##301重定向和302重定向的区别
　　302重定向只是暂时的重定向，搜索引擎会抓取新的内容而保留旧的地址，因为服务器返回302，所以，搜索搜索引擎认为新的网址是暂时的。

　　而301重定向是永久的重定向，搜索引擎在抓取新的内容的同时也将旧的网址替换为了重定向之后的网址。