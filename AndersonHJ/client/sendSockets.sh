#!/bin/bash

#The program will execute the socketClient program all the time
while true;
do
./socketClient.o 172.31.18.208 8888
#The internal network ip is 172.31.18.208
#The port is 8888
sleep 1;
done
