#!/bin/bash
Time=`date +%Y-%m-%d_%H:%M:%S`
HostName=`hostname`
OsType=`cat /etc/issue.net | tr " " "_"`
KernelVersion=`uname -r`
LoadAvg=`cut -d " " -f 1-3 /proc/loadavg`
UpTime=`uptime -p | tr -s " " "_"`

eval `df -T -x devtmpfs -x tmpfs -m --total | tail -n 1 | awk \
    '{printf("DiskTotal=%s;DiskUsedP=%d", $3, $6)}'`

DiskWarningLevel="normal"

if [[ ${DiskUsedP} -gt 90 ]]; then
    DiskWarningLevel="warning"
elif [[ ${DiskUsedP} -gt 80 ]]; then
    DiskWarningLevel="note"
fi

MemWainingLevel="normal"

eval `free -m | head -n 2 | tail -n 1 | awk \
    '{printf("MemTotal=%s;MemUsed=%s", $2, $3)}'`

MemUsedP=$[ ${MemUsed}*100/${MemTotal} ]

if [[ ${MemUsedP} -gt 90 ]]; then
    MemWarningLevel="warning"
elif [[ ${MemUsedP} -gt 80 ]]; then
    MemWarningLevel="note"
fi

CpuTemp=`cat /sys/class/thermal/thermal_zone0/temp`
CpuTemp=`echo "scale=2;${CpuTemp}/1000" | bc`

CpuWarningLevel="normal"
if [[ `echo "${CpuTemp} >= 70" | bc -l` -eq 1 ]]; then
    MemWarningLevel="warning"
elif [[ `echo "${CpuTemp} >= 50" | bc -l` -eq 1 ]]; then
    MemWarningLevel="note"
fi


echo "${Time} ${HostName} ${OsType} ${KernelVersion} ${UpTime} ${LoadAvg} ${DiskTotal} ${DiskUsedP}% ${MemTotal} ${MemUsedP}% ${CpuTemp} ${DiskWarningLevel} ${MemWainingLevel} ${CpuWarningLevel}"


