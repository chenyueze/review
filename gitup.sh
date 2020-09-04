#!/bin/zsh 
echo \"$1\"
temp=$1
echo $temp
git add .
git commit -m \"$1\"
git push -u origin master
