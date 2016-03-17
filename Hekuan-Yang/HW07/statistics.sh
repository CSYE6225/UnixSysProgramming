#!/bin/bash

# print table title
echo "Open_Connections %MEM VSZ";
while true;
do
 
# Get the PID of live_socket_srv.o 

        PID_SRV=`ps aux |grep live_socket_srv|grep -v 'grep'|awk '{print $2}'`;
        
        # Find the number of open connections to the server
        
        echo -n `sudo netstat -anp|grep ${PID_SRV} |wc -l`
        echo -n " "
        
        # Print memory consumption of the server while processing the load
        echo `sudo ps aux|grep ${PID_SRV}|grep -v 'grep'|awk '{print $4,$5}'`
        
        sleep 5;
done
