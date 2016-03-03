#!/bin/bash
while true;
do
sudo netstat -anp | grep 6951 | wc -l;
sudo ps aux | grep 6951| awk '{ print $4,$5}';
sleep 2;
done
