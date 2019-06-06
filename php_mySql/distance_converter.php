<?php


if(isset($_POST['type1']))
{  
    $value = $_POST['distance'];
    $conversion = distanceCon1($value);
    echo $value . " kilometers is ". $conversion . " miles.";
}

else
{
    $value = $_POST['distance'];
    $conversion = distanceCon2($value);
    echo $value . " miles is " . $conversion . " kilometers"; 
}



function distanceCon1($value)
 {
        $conversion = ($value/ 1.600934);
        return $conversion;
}   

    
function distanceCon2($value)
{
         $conversion = ($value / 0.621371);
         return $conversion;
}

?>