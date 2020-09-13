# server 端

1. `get_value`获取配置信息
2. `socket_creat_udp()`获取套接字
   1. `socket(udp)`
   2. `setsockopt()`设置地址重用
   3. 设置非阻塞套接字
   4. `bind()`把本地协议地址绑定给套接字
   5. 返回套接字
3. `pthread_creat()`创建新线程绘制场地
   1. `darw()`
   2. `initfootball()`
4. `epoll_create()`创建三个 epoll 实例主从反应堆
5. 