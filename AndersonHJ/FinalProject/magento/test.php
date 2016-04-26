<?php

	$integer = $_GET["integer"];
	$i = 2;
	while(($integer%$i)!=0&&$i<$integer){
		$i++;
	}

	if($i==$integer)
		echo "true";
	else
		echo "false";

?>