<?php 

include('conexao.php');

error_reporting(0);
ini_set(“display_errors”, 0 );
   
   $query = "INSERT INTO tempLog (temperature, humidity) VALUES ('".$_GET["sensor1"]."','".$_GET["sensor2"]."')"; 
   $exec = $conn->exec($query);
   echo "ok";
?>