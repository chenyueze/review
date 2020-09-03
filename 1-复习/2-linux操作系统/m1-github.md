# Linux(unix) 从本地上传文件夹到 github

1. 登录 github

2. 新建仓库（不带默认 readme，易出错误）

3. 参考说明指令

4. 具体指令：

   ```shell
   cd /Users/chuancey/Documents/first #（进入要上传文件的文件夹）
   git init #（初始化）
   git add . #（注意git add .中的“ .”把文件夹所有的文件加入要上传的文件夹中）
   git commit -m 'first commit' #（第一次提交修改）
   git remote add origin https://github.com/chenyueze/xxxxx.git
   #（这是新建仓库的http地址，查看自己的仓库的地址如下图，点击Clone or download按钮，复制即可）
   git push -u origin master#（执行这一步的时候会让你输入git的账号和密码）
   ```

   

