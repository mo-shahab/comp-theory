<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>something</title>
</head>
<body>
    <h1>hewwo wowwd</h1>
    <?php
        echo("something something");
        echo("<h1>something bigger</h1>");
        echo("<hr>");
        echo("<p style=\"font-family: Arial\">there are lot of things to work on and there shall be the work done so that there will be no lazing around and stuff so that
        we can win whatever the thing that is brewing in the puny little delusional brains of ours and whatever that is will be slain by the 
        chivalrous person who does not have anything to do with the thing and there shall be blood and stuff like that this is so cool");


        //variables 
        //all the variables must be started with the $ sign
        $username = 'fred smith';
        echo($username);
        echo("<br>"); 
        $current_user = $username;
        echo("this is after assigning to another variable");
        echo($current_user);
        echo("<br>");

        $count = 10; //integer
        $count1 = 15.04; //floating point  variable
        echo($count);
        //array thingy bro
        $team = array('bill', 'mary', 'mike', 'chris', 'anne');
        echo("<br>");

        //to display the things of the thing man why am i commenting this stuff and all i dont know
        echo($team[4]);
        
        //multidimensional array
        $oxo = array(array('x', '.', 'o'),
                     array('o', 'o', 'x'),
                     array('x', 'o', 'x'));
        echo("<br>");
        echo($oxo[1][2]);

        //operators and stuff
        echo("<br>");
        echo(5+4);
        echo(5*5);
        echo(6-1);
        echo(6/3);
        echo("<br>");
        
        //these are strings
        $info = 'preface variabe with a $ like this: $varuibale';
        echo("<br>");
        echo($info);
        echo("<br>");
        $author = 'bill gates';
        $text = 'measuring programming process by lines of 
        of code is like measuring aircarft building progress by weight
        - $author.';
        echo($text.$author); //so concatenation works but not quite like ho w i want it to work
        echo("<br>");
        $author = 'scott adams';
        $out = <<<_END
        normal people believe that if it aint broke, dont fix it
        engineers believe that if it aint broke, it doesnt have enough
        features yet.
        - $author.
        _END;
        echo("<br>");
        echo($out);

        //php is a vary loosley typed language
        $number = 12345*67890;
        echo("<br>");
        echo(substr($number, 3, 1));
        $pi = "3.1415937";
        $radius = 5;
        echo($pi * ($radius * $radius));

        //constants and stuff man
        define("ROOT_LOCATION", "userlocal/www/");
        $directory = ROOT_LOCATION;
        //predefined constants
        /*
            __LINE__ = the current line number of the file
            __FILE__ = the full path and filename of the file. if used 
                       an include, the name of the included file is returned.
                       in php 4.0.2, __FILE__ always contains an absolute ath with 
                       symbolic links resolvec, whereas in older versions it might 
                       contain a relative path under some circumstances
            __DIR__ = 
            __FUNCTION___ = 
            __CLASS__ = 
            __METHOD__ = 
            __NAMESPACE__ = 
        */
        echo("<br>");
        echo("this is line".__LINE__." of file".__FILE__);
        print "hello world there is something that needs to be bothered and stuff
        must  happen so yeah tell people that they are not the saem";

        //functions and stuff man 
        function longdate($timestamp)
        {
            return date("l F j s Y", $timestamp);
        }
        echo("<br>");
        echo(longdate(time()));
    ?>
</body>
</html>