<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="initial-scale=1.0" />
        <link rel="stylesheet" media="all" href="style.css" />
        <link rel="shortcut icon" href="favicon.ico" />
        <title>Emploi du temps</title>
    </head>
    <body>
        <h1>Emploi du temps</h1>

        <?php

          if (isset($_GET) && isset($_GET['login']) && !empty($_GET['login'])) { ?>
          <!--<img src="loader.gif" alt="Loading..." /><br />-->
            <?php
            $json = file_get_contents("https://webapplis.utc.fr/Edt_ent_rest/myedt/result?login=".$_GET['login']);
            $data = json_decode($json, true);

            $days = array("LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI", "DIMANCHE");

            usort($data, function($a, $b) use ($days) {
                return (array_search($a['day'], $days) - array_search($b['day'], $days)) * 2 + ((intval(str_replace(":","",$a['begin'])) - (intval(str_replace(":","",$b['begin']))) < 0) ? -1 : 1);
            });

            //foreach ($data as $key => $value) {
            //  foreach ($value as $k => $v) {
            //    print $k.": ".$v."<br />";
            //  }
            //  print "<br />";
            //}
            ?>
            <!--<table border=1>
                <tr>
                  <td></td>
                  <td>Lundi</td>
                  <td>Mardi</td>
                  <td>Mercredi</td>
                  <td>Jeudi</td>
                  <td>Vendredi</td>
                  <td>Samedi</td>
                  <td>Dimanche</td>
                </tr>-->
                <?php
                //for ($day = 0; $day < count($days); $day++) {
                //  $hour = 8; // < 20
                //  $minutes = 0; // 0, 15, 30, 45, 0...
                //  // array_shift($data) as we find a matching value
                //  do {
                //    print ""
                //    if ($minutes = 45)
                //      $hour++;
                //    $minutes = ($minutes + 15) % 60;
                //  } while($hour < 20)
                //  <
                //}

                ?>
              <!--</table>-->
            <?php
          }
          else { ?>
            <form action="" method="GET">
              <label for="login">Votre login UTC :</label> <input type="text" id="login" name="login" placeholder="Identifiant" required/> <input type="submit" value="Rechercher" />
            </form>
          <?php }
        ?>
    </body>
</html>
