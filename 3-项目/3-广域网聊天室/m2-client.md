# client 端

1. `get_value()`获取配置信息
2. `socket_connect()`建立连接
   1. `sockfd()`创建套接字
   2. `connect()`建立连接
3. `chat_recv()`配合服务端处理登录前检测
4. `fork()`创建子进程
   1. `pid == 0`子进程中处理发送数据
      1. `whlie()`处理特殊信息并`chat_send()`发送
   2. 父进程
      1. `freopen()`打开记录文件写聊天记录
      2. `fflish()`刷新缓冲区