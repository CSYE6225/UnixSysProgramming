#!/bin/bash

#the pid of server is 7483
while true;
do
sudo netstat -anp|grep 15440|wc -l;
#get the memory consumption
sudo ps aux|grep  15440|awk '{print$4,$5}';
sleep 3;
done
