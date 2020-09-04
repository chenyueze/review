#!/bin/zsh 
echo $1
git add .
git commit -m "test"
git push -u origin master
