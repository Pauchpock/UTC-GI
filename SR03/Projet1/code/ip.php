<?php
header('Access-Control-Allow-Origin: *');
$command="/sbin/ifconfig wlp2s0f0 | grep 'inet addr:' | cut -d: -f2 | awk '{ print $1}'";
$localIP = exec ($command);
echo $localIP;
