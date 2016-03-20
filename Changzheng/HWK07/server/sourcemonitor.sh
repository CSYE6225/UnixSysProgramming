#!/bin/bash

GetPID() #User #Name
{
   PsUser=ubuntu
   PsName=live
   ps -u $PsUer|grep $PsName|grep -v grep|sed -n 1p | awk '{print $1}'
   pid=`ps -u $PsUer|grep $PsName|grep -v grep|sed -n 1p | awk '{print $1}'`
   return $pid
}

#PID = 'GetPID ubuntu live'
# get pid of server processing
user=ubuntu
proce=live
pid=`ps -u $user | grep $proce | grep -v grep | sed -n 1p | awk '{ print $1}'`
echo $pid
# loop the pid info including process and port number or memory occupancy
count=0
while true
do
#echo "checking" + $count + " times "
echo "checking the $count th times"
procenumber=`sudo lsof |grep $pid | wc -l`
echo "processing : $procenumber"
portnumber=`netstat -anp | grep $pid | wc -l`
echo "prot number : $portnumber"
memory=`ps -o vsz -p $pid | grep -v VSZ`
echo "memerory cost :$memory"
sleep 1
count=`expr $count + 1`
done
