#!/bin/bash
Time=`date +%Y-%m-%d_%H:%M:%S`
eval `df -m -x tmpfs -T -x devtmpfs | tail -n +2 | \
    awk -v DiskSum=0 -v DiskLeft=0 \
        '{printf("Pname["NR"]=%s;Psum["NR"]=%d;Pleft["NR"]=%d;\
        Puseprec["NR"]=%s;", $7, $3, $4, $6); \
        DiskSum+=$3; DiskLeft+=$5} \
        END {printf("Pnum=%d;DiskSum=%d;DiskLeft=%d;", \
        NR, DiskSum, DiskLeft)}'`

for(( i = 1; i <= ${Pnum}; i++ )); do
    echo "${Time} 1 ${Pname[$i]}  :: ${Psum[$i]} ${Pleft[$i]} ${Puseprec[$i]}"
done

DiskPerc=$[ (1 - ${DiskLeft}/${DiskSum})*100  ]

echo "${Time} 0 disk :: ${DiskSum} ${DiskLeft} ${DiskPerc}"













