First, deploy load balancer to balance the request from client.

loadBalancerConfig included command use in install apache2 as load balancer
proxyConfig included balancer setting in /etc/apache2/sites-enabled/000-default.conf


Second, Use load.sh to generate request against load balancer & Use index.php to add load on server.

At the same time,

Print the number of connections through command

$sudo netstat -anp | grep apache2 | wc -l 

and Print the status of server

$vmstat 3 or $top

when number of clients increased to 5, the idle memory run into 0 ( provide in the attched screenshots s1&s2)

at that point, the max number of connection is 11.

on server, use command

$ grep @inetIPofLoadBalancer/var/log/apache2/access.log|awk '{print $10,$4}' |sed 's/\[//g' | awk -F\: '{print $1"_"$2"_"$3}' | awk '{arr[$2]+=$1}END{for(i in arr) print i,arr[i]/60}'

then it will return transactions per minute, details are provided in file named result.
