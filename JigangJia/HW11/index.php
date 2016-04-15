<?php
// Allocate memory per the VM capacity
ini_set('memory_limit', '-1');
// Get a file into an array.  In this example we'll go through HTTP to get
// the HTML source of a URL.
$lines = file('1.log');
// Loop through our array, show HTML source as HTML source; and line numbers too.
sort($lines);
/*
foreach ($lines as $line_num => $line) {
    echo "Line {$line_num} : $line\n";
}*/
echo "Done";
?>
