<?php 

include('conexao.php');

//error_reporting(0);
//ini_set(“display_errors”, 0 );
   
   $query = "INSERT INTO tempLog (quant_pessoas) VALUES ('".$_GET["valor"]."')"; 
   $exec = $conn->exec($query);
   echo "ok";
?>