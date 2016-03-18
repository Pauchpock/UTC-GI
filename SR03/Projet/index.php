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

        $colors = array('blue','yellow','green','red','purple','#7CFC00','magenta','gray','gray');
        $uvsColor = array();

        function getOffset($uv) {
            $start = explode(":", $uv['begin']);
            $end = explode(":", $uv['end']);
            $diff_hours = ((int)$end[0]) - ((int)$start[0]);
            $diff_minutes = ((int)$end[1]) - ((int)$start[1]);
            return ($diff_hours * 4) + ($diff_minutes / 15);
        }

        function shouldDisplayNextLesson($uv,$hour,$minutes) {
            $start = explode(":", $uv['begin']);
            return ((int)$start[0]) == $hour && ((int)$start[1]) == $minutes;
        }


        if (isset($_GET) && isset($_GET['login']) && !empty($_GET['login'])) { ?>
            <!--<img src="loader.gif" alt="Loading..." /><br />-->
            <?php
            $json = file_get_contents("https://webapplis.utc.fr/Edt_ent_rest/myedt/result?login=".$_GET['login']);
            $data = json_decode($json, true);

            $days = array("LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI", "DIMANCHE");

            usort($data, function($a, $b) use ($days) {
                return (array_search($a['day'], $days) - array_search($b['day'], $days)) * 2 + ((intval(str_replace(":","",$a['begin'])) - (intval(str_replace(":","",$b['begin']))) < 0) ? -1 : 1);
            });
            ?>
            <table>
            <?php
            for ($day = 0; $day < count($days); $day++) {
                print "<tr>";
                print "<td>".$days[$day]."</td>";
                $hour = 8; // < 20
                $minutes = 0; // 0, 15, 30, 45, 0...
                do {
                    if (count($data) > 0 && shouldDisplayNextLesson($data[0],$hour,$minutes)) {
                        $uv = array_shift($data);

                        $offset = getOffset($uv);
                        $end = explode(":", $uv['end']);
                        $hour = (int) $end[0];
                        $minutes = (int) $end[1];
                        if (isset($uvsColor[$uv['uv']])) {
                            $color = $uvsColor[$uv['uv']];
                        }
                        else {
                            $color = array_shift($colors);
                            $uvsColor[$uv['uv']] = $color;
                        }
                        print "<td class='lesson' colspan='".$offset."' style='background-color: ".$color."'>";
                        print "<span class='when'>".$uv['begin']." - ".$uv['end']."</span><br />";
                        print $uv['type']. " " .$uv['uv'];
                        if (!empty($uv['group']))
                            print " (".$uv['group'].")";
                        print "<br />".$uv['room'];
                    }
                    else {
                        print "<td>";
                        if ($minutes == 45)
                            $hour++;
                    $minutes = ($minutes + 15) % 60;
                    }
                    print "</td>";
                } while($hour < 20);
                print "</tr>";
            }
            ?>
            </table>
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
