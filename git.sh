#!/bin/bash

git add .
case $# in
	0)
		git commit -m "提交日期：`date +"%Y-%m-%d %H:%M:%S"`"
		;;
	1)
		git commit -m "$1,提交日期：`date +"%Y-%m-%d %H:%M:%S"`"
		;;
	*)
		echo "命令格式错，退出！"
		;;
esac
git push
