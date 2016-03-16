#!/bin/bash

#The pid of the server program is 18631
while true;
do
#Execute the command to find the number of open connections to the server.
sudo netstat -anp|grep 18631|wc -l;
#Execute the command to find the memory consumption of the server while processing the load.
sudo ps aux|grep 18631|awk '{print$4,$5}';
sleep 5;
done

#you use static PID 18631. Use PID
