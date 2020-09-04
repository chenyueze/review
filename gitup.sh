#!/bin/zsh
echo \[Emma\] : git add .
git add .
echo \[Emma\] : git commit -m \"$1\"
git commit -m \"$1\"
echo \[Emma\] : git push
git push
echo \[Emma\] : over.
#一键上传 github
