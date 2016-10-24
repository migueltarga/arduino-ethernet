<html>
   <head>
      <title>Sensor Data</title>
      <meta http-equiv="refresh" content="30">  
   </head>
<body>
   <h1>Sensor Infravermelho</h1>

      <?php                     
    
      include('conexao.php');
      $stmt = $conn->prepare('SELECT * FROM tempLog ORDER BY timeStamp');

      $stmt->execute(array('tempLog'));

		    while($row = $stmt->fetch()) {

        	echo "Data: {$row['timeStamp']} - Valor1: {$row['temperature']} -  Valor2: {$row['humidity']} <br/>";
    }
      ?>
</body>
</html>
