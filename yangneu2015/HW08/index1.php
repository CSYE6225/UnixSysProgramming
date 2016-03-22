<?php
    $arr = scandir("/proc/");
    for($x=0;$x<5000;$x++){
        asort($arr);
        arsort($arr);
    }
    print_r($arr);
    echo "server1";
?>
