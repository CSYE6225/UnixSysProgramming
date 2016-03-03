#!/bin/bash
while true;
do
sudo lsof | grep 5884|wc –l;
sudo ps aux | grep 5884|awk ‘{print $4,$5}’;
done
