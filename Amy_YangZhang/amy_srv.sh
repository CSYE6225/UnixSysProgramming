#!/bin/bash

while true;
do
sudo netstat -anp|grep 30927|wc -l;
sudo ps aux|grep 30927|awk '{ print $4,$5}';
sleep 5;
done

#you use static PID 30927. Use PID
