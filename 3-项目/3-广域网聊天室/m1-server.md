# server端

##  主函数：

1. `getvalue()`获取端口号（`common/common.c`）
2. `socket_creat()`创建套接字（`common/tcp_server.c`）
   1. `socket()`
   2. `setsockopt()`设置发送接收时限
   3. `bind()`
   4. `listen()`
3. `while()循环处理`
   1. `accept()`等待连接
   2. `chat_recv`处理消息
   3. `check_online()`检查是否在线
   4. `client[sub]`保存用户信息
   5. `pthread_creat()`新建线程调用`work()`函数
   6. `work()`为连接服务
      1. `while()`循环处理
      2. `chat_recv()`处理消息
      3. 退出
      4. 全体信息
      5. 私聊信息
      6. 查询在线人数及名称

