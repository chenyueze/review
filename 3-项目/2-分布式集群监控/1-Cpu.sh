#!/bin/bash
TIME=`date +%Y-%m-%d__%H:%M:%S`
LoadAvg=`cut -d ' ' -f 1-3 /proc/loadavg`

CpuTemp=`cat /sys/class/thermal/thermal_zone0/temp`
CpuTemp=`echo "scale=2;${CpuTemp}/1000" | bc`

eval `head -n 1 /proc/stat | awk -v sum1=0 '{for(i=2;i<=11;i++){sum1=sum1+$i} printf("Sum1=%d;Idle1=%d", sum1, $5)}'`
sleep 0.5
eval `head -n 1 /proc/stat | awk -v sum2=0 '{for(i=2;i<=11;i++){sum2=sum2+$i} printf("Sum2=%d;Idle2=%d", sum2, $5)}'`

CpuUsedPerc=`echo "scale=4;(1-(${Idle2}-${Idle1})/(${Sum2}-${Sum1}))*100" | bc`
CpuUsedPerc=`printf "%.2f" ${CpuUsedPerc}`

WarnLevel="normal"
if [[ `echo "${CpuTemp} >= 50" | bc -l` == 1 ]]; then
    WarnLevel="note"
elif [[ `echo "${CpuTemp} >= 70" | bc -l` == 1 ]]; then
    WarnLevel="warning"
fi

echo ${TIME}" "${LoadAvg}" "${CpuUsedPerc}%" "${CpuTemp}" "${WarnLevel}
