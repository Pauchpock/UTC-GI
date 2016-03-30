<?php
$colors = array('#F4511E','#43A047','#E53935','#1E88E5','#6D4C41','#757575','#5E35B1','#8E24AA');
$uvsColor = array();
$days = array("LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI");

function getOffset($uv) {
    $start = explode(":", $uv['begin']);
    $end = explode(":", $uv['end']);
    $diff_hours = ((int)$end[0]) - ((int)$start[0]);
    $diff_minutes = ((int)$end[1]) - ((int)$start[1]);
    return ($diff_hours * 4) + ($diff_minutes / 15);
}

function shouldDisplayNextLesson($uv,$day,$hour,$minutes) {
    $start = explode(":", $uv['begin']);
    global $days;
    return ($uv['day'] == $days[$day] && ((int)$start[0]) == $hour && ((int)$start[1]) == $minutes);
}


if (isset($_GET) && isset($_GET['login']) && !empty($_GET['login'])) { ?>
    <?php
    $json = file_get_contents("https://webapplis.utc.fr/Edt_ent_rest/myedt/result?login=".$_GET['login']);
    $errorCode = explode(" ", $http_response_header[0])[1];
    if ($errorCode != "200") {
        header("HTTP/1.1 555 API NOT REACHABLE");
        exit;
    }
    $data = json_decode($json, true);
    if (count($data) == 0) {
        header("HTTP/1.1 404 NOT FOUND");
        exit;
    }
    usort($data, function($a, $b) use ($days) {
        return (array_search($a['day'], $days) - array_search($b['day'], $days)) * 2 + ((intval(str_replace(":","",$a['begin'])) - (intval(str_replace(":","",$b['begin']))) < 0) ? -1 : 1);
    });
    ?>
    <table>
    <tr>
        <td></td>
        <td colspan="4">8:00</td>
        <td colspan="4">9:00</td>
        <td colspan="4">10:00</td>
        <td colspan="4">11:00</td>
        <td colspan="4">12:00</td>
        <td colspan="4">13:00</td>
        <td colspan="4">14:00</td>
        <td colspan="4">15:00</td>
        <td colspan="4">16:00</td>
        <td colspan="4">17:00</td>
        <td colspan="4">18:00</td>
        <td colspan="4">19:00</td>
    </tr>
    <?php
    for ($day = 0; $day < count($days); $day++) {
        print "<tr>";
        print "<td>".$days[$day]."</td>";
        $hour = 8; // < 20
        $minutes = 0; // 0, 15, 30, 45, 0...
        do {
            if (count($data) > 0 && shouldDisplayNextLesson($data[0],$day,$hour,$minutes)) {
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
                    print "<br />".$uv['group'];
                print "<br />".$uv['room'];
            }
            else {
                $class = ($minutes == 0 ? " class='hour'" : "");
                print "<td".$class.">";
                if ($minutes == 45)
                    $hour++;
                $minutes = ($minutes + 15) % 60;
            }
            print "</td>";
        } while($hour < 20);
        print "</tr>";
        if ($days[$day] == "VENDREDI" && count($data) == 0) {
            break;
        }
    }
    ?>
    </table>
<?php
}
else { ?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" media="all" href="style.css" />
        <link rel="shortcut icon" href="favicon.ico" />
        <title>Emploi du temps</title>
        <script type="text/javascript" src="script.js"></script>
    </head>
    <body>
        <h1>Emploi du temps</h1>
            <form action="" method="GET" onsubmit="event.preventDefault(); ajax(this);">
              <label for="login">Votre login UTC :</label> <input type="text" id="login" name="login" placeholder="Identifiant" required/> <input type="submit" value="Rechercher" />
            </form>
            <div id="edts"></div>
    </body>
</html>
<?php
}
?>
