#!/bin/sh

while true
do
  git add *
  git commit -m `date "+%Y/%m/%d"`
  sleep 300
done

