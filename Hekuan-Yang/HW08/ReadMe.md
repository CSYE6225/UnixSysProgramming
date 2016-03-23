Use load.sh to generate request against load balancer.

Use load.php to add load on server

loadBalancerConfig is the way install apache2 as a load balancer

proxyConfig is the load balancer setting in /etc/apache2/sites-enabled/000-default.conf

Print the number of connections 

$sudo netstat -anp | grep apache2 | wc -l 

Print the status of server

$vmstat 3

when 5 clents are running at the same time, the idle mem run into 0 ( provide in the attched screenshots s1&s2)

the max number of connection is 11

use
$ grep 172.31.26.173 /var/log/apache2/access.log|awk '{print $10,$4}' |sed 's/\[//g' | awk -F\: '{print $1"_"$2"_"$3}' | awk '{arr[$2]+=$1}END{for(i in arr) print i,arr[i]/60}'

then it will return transactions per minute.
