# HW-08
-------

### SYSTEM CONFIGURATION
##### Client One - Medium System
-	1 CPU, 3.75GB RAM
- Running Apache Tomcat

##### Client Two - Small SYSTEM
- 1 CPU, 0.6GB RAM
- Running Apache Tomcat

##### Load Balancer - Medium SYSTEM
- 1CPU, 3.75GB RAM
- Running NGINX as Load Balancer (Round Robin)
- NGINX config file ``` nginx.conf ```

-----------
### TEST
##### Both the clients were loaded with two tests and ran for 20 minutes each
- FIRST TEST : a regular GET request that returns back the page
- a GET request with a function to do a bubble sort on 15 random numbers

```

function bubbleSort(a)
{
    var swapped;
    do {
        swapped = false;
        for (var i=0; i < a.length-1; i++) {
            if (a[i] > a[i+1]) {
                var temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

```
----------------
### TEST RESULTS
##### FIRST TEST :
- Both of the applications were running fine for the 20 minutes
- CPU spikes were up to 7% for client one and around 10% for client Two
- Network Operations were up to 4000-5000 in incoming/outgoing packets in both the clients
- Disk Operations were up to 12.5k reads and 9.5k writes per second in both the clients
- None of the systems crashed

##### SECOND TEST
- Both of the applications were running fine for the 20 minutes
- CPU spikes were up to 25% for client one and around 75% for client Two
- Network Operations were up to 6k in incoming/outgoing packets both the clients
- Disk Operations were up to 27.5k reads and 10.5k writes per second
- None of the systems crashed entirely but system two was slow to respond. So every request to system two was taking more time to send a 200 status than if the request was on system one.
###### Possible cause
-	Client 2 had less memory assigned to it than client one and hence when the IO write/read reaches a limit the CPU would take more time to assign those resources back for the program to respond
- Network packets sent and received were approximately the same in the clients even with different configurations

----------------
### TO TEST
- These tests were done with a Round Robin fashion load balancing
- Nginx also provides load balancing strategies such as IP hashing and least connected server and also weight the priority of the server that it should hit first and how many times
- These test conifgs can change load balancing results and help us assign the resources more practically if we have a situation with a large client and a client with less resources
