# 分布式集群监控系统

1. CPU 信息获取
   1. 通过 cat 查看 /sys/class/thermal/thermal_zone0/temp、/proc/stat	、/proc/loadavg 等文件来获取系统的 cpu 信息
2. MEM 信息获取
   1. 使用 free、awk 计算
3. DISK 信息获取
   1. 使用 df、awk 循环处理每一个分区
4. USER 信息获取
   1. 使用 last、awk、/etc/group、/etc/passwd 等获取信息
5. 恶意进程检测
   1. 使用ps -aux	查看进程筛选内存或 cpu 占用过 50 的进程，若五秒后依然超过五十标记为恶意进程
6. 系统运行概况
   1. 使用 date、hostname、/etc/issue.net、uname、/proc/loadavg、uptime、df、free、/sys/class/thermal/thermal_zone0/temp等，综合整理系统信息