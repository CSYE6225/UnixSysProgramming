#!/bin/bash

while true;
do
sudo netstat -anp|grep 2688|wc -l;
sudo ps aux|grep 2688|awk '(print$4,$5)'.;

sleep 2;
done

#you use static PID 2688. Use PID
