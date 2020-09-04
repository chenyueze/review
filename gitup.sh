#!/bin/zsh 
echo $1
git add .
git -m commit "$1"
git push -u origin master
