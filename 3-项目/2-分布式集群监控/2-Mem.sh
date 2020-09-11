#!/bin/bash 
if [[ $# -lt 1 ]]; then
    echo "Usage:$0 DyAver"
fi

Time=`date +%Y-%m-%d_%H:%M:%S`
DyAver=$1

if [[ ${DyAver}x == x ]]; then
    exit 1
fi

MemValues=(`free -m | head -n 2 | tail -n 1 | awk '{printf("%s %s", $2, $3)}'`)

MemUsedPrec=`echo "scale=1; ${MemValues[1]}*100/${MemValues[0]}" | bc`


NowAver=`echo "scale=1; 0.7*${MemUsedPrec}+0.3*${DyAver}" | bc`


echo "${Time} ${MemValues[0]}M ${MemValues[1]}M ${MemUsedPrec}% ${NowAver}%"


