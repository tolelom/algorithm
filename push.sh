#!/bin/bash

if [ -z "$1" ]; then
    msg="solve: update"
elif [ -z "$2" ]; then
    msg="solve: $1"
else
    msg="solve: $1 ($2)"
fi

git add -A
git commit -m "$msg"
git push
