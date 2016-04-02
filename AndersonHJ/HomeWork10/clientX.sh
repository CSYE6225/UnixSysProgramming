#!/bin/sh

while true;
do
curl -I http://52.38.123.237/load.php|head -2 >> clientX.log;

sleep 0.05;
done
