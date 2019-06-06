<?php
require_once 'db_connect.php';
?>
<!DOCTYPE html>
<html lang="en">

  <head>

    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>Clean Blog - Start Bootstrap Theme</title>

    <!-- Custom fonts for this template -->
    <link href="vendor/font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css">
    <link href='https://fonts.googleapis.com/css?family=Lora:400,700,400italic,700italic' rel='stylesheet' type='text/css'>
    <link href='https://fonts.googleapis.com/css?family=Open+Sans:300italic,400italic,600italic,700italic,800italic,400,300,600,700,800' rel='stylesheet' type='text/css'>

    <!-- Custom styles for this template -->
      <link href="css/clean-blog.css" type = "text/css">
    <link href="css/clean-blog.min.css" type = "text/css">

  </head>

  <body style="background-color:powderblue;">
      
<div align = "middle">
    <!-- Navigation -->
    <nav class="navbar navbar-expand-lg navbar-light fixed-top" id="mainNav">
      <div class="container">
        <a class="navbar-brand" href="../index.html">CLICK HERE TO ENTER ANOTHER VALUE</a>
        
        </div>
    </nav>

    <!-- Page Header -->
    <header class="masthead" style="background-image: url('img/home-bg.jpg')">
      <div class="overlay"></div>
      <div class="container">
        <div class="row">
          <div class="col-lg-8 col-md-10 mx-auto">
          </div>
        </div>
      </div>
    </header>

    <!-- Main Content -->
    <div class="container">
      <div class="row">
        <div class="col-lg-8 col-md-10 mx-auto">
              <h2>
                Top Baby Names (By Gender)
              </h2> 
            
            
            
            
                
<?php
         
$name = $_POST['name'];
$sex =  $_POST['sex']; 
// Add two rows to the table
$sql = "INSERT INTO test (name , sex)
         VALUES ('$name' , '$sex')";
?>
    
      <div id="step-two" class="well">
<?php
if($db->query($sql)) {
    echo '        <div class="alert alert-success">Values inserted successfully.</div>' . PHP_EOL;
} else {
    echo '        <div class="alert alert-danger">Value insertion failed: (' . $db->errno . ') ' . $db->error . '</div>' . PHP_EOL;
    exit();
}
?>
      </div>
<div align = "middle">
<?php
// Get the rows from the table
$sql = "SELECT name, sex,  SUM(count) FROM test  WHERE sex = 'boy' GROUP BY name ORDER BY SUM(count) DESC LIMIT 10";
?>
      <div id="step-three" class="well">
        <h3 style = "color: blue;">Top 10 Boy Names </h3>
<?php
$result = $db->query($sql);
if($result->num_rows > 0) {
    echo '<div class="alert alert-success">' . PHP_EOL;
    while($row = $result->fetch_assoc()) {
        echo "<p> ". $row["name"] . "           curent count: " . $row["SUM(count)"] . "</p>" . PHP_EOL;
    }
    echo ' </div>' . PHP_EOL;
} else {
    echo ' <div class="alert alert-success">No Results</div>' . PHP_EOL;
}
?>
      </div>
<?php
// Get the rows from the table
$sql = "SELECT name, sex,  SUM(count) FROM test  WHERE sex = 'girl' GROUP BY name ORDER BY SUM(count) DESC LIMIT 10";
?>
      <div id="step-three" class="well">
        <h3 style = "color:red;">Top 10 Girl Names</h3>
<?php
$result = $db->query($sql);
if($result->num_rows > 0) {
    echo '<div class="alert alert-success">' . PHP_EOL;
    while($row = $result->fetch_assoc()) {
        echo "<p> ". $row["name"] . "            curent count: " . $row["SUM(count)"] . "</p>" . PHP_EOL;
    }
    echo ' </div>' . PHP_EOL;
} else {
    echo ' <div class="alert alert-success">No Results</div>' . PHP_EOL;
}
?>
      </div>
            </div>
            
            
<?php
// Drop the TEST table now that we're done with it
$sql = "DROP TABLE test";
?>
    
              
            
            
            
            
            <br/>
            <br/>
            <br/>
            <br/>
            
            
          </div>
          <hr>
          </div>
          <hr>
        </div>
   
</div>
    <!-- Bootstrap core JavaScript -->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

  </body>

</html>



