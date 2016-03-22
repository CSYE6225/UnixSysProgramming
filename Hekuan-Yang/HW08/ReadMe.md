Use load.sh to generate request against load balancer.

Use load.php to add load on server

loadBalancerConfig is the way install apache2 as a load balancer

proxyConfig is the load balancer setting in /etc/apache2/sites-enabled/000-default.conf

Print the number of connections 
$sudo netstat -anp | grep apache2 | wc -l 

Print the status of server
$vmstat 
