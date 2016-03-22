<?php
    //get the directory list of /proc
    $arr = scandir("/proc/");
    //loop to srot the array $arr ascendingly and descendly
    for($x=0;$x<1000;$x++){
        asort($arr);
        arsort($arr);
    }
    print_r($arr);
    echo "server2";
?>
