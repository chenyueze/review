#!/bin/bash

Time=`date +%Y-%m-%d_%H:%M:%S`

eval `awk -F: -v Sum=0 \
    '{if ($3 >= 1000 && $3 != 65534) {Sum+=1}} \
    END {printf("Sum=%d;", Sum)}' /etc/passwd`


MostActiveUser=`last -w | cut -d " " -f 1 | grep -v wtmp \
    | grep -v reboot | grep -v "^$" | sort | uniq -c | sort -k 1 -n -r \
    | awk -v num=3 '{if (num>0) {printf(" %s", $2); num--}}' \
    | cut -c 2-`

UsersWithRoot=`cat /etc/group | grep sudo | cut -d : -f 4`

UserLogedIn=`w -h | awk '{printf(",%s_%s_%s", $1, $3, $2)}' | cut -c 2-`

echo "${Time} ${Sum} [${MostActiveUser}] [${UsersWithRoot}] [${UserLogedIn}]"
