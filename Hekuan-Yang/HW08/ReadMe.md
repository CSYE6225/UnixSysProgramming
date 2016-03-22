Use load.sh to generate request against load balancer.

Use load.php to add load on server

loadBalancerConfig is the way install apache2 as a load balancer

proxyConfig is the load balancer setting in /etc/apache2/sites-enable/000-default.conf

$sudo netstat -anp | grep apache2 | wc -l print the number of connections 


$vmstat 
