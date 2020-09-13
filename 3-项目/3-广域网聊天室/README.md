# 广域网聊天室

1. `commom.h:getvalue()`   从配置文件读取配置信息 
   1. `fopen`
   2. `getline`
   3. `strstr`
   4. `strncpy`
2. ` color.h ` ：宏定义更改输出颜色
3. 处理`ctl + c`信号:
   1. `signal()`注册 ` SIGINT ` 信号量，调用 logout()函数
4. 

