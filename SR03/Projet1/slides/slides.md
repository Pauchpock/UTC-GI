% Projet emploi du temps
% Steve Lagache, Romain Pellerin
% SR03 8 avril 2016

-------------------------------------------

## Cahier des charges

- Emploi du temps
- API de l'UTC
- Afficher 2 emplois du temps en même temps

-------------------------------------------

## Technos

- Front: HTML, CSS, JavaScript
- Back: PHP
- Pas de bibliothèque

-------------------------------------------

## Architecture

<img src="assets/arch.png" alt="Architecture" class="w80" />

-------------------------------------------

## Fonctionnalités

- Messages d'erreur (API indispo, mauvais login)
- Plusieurs emplois du temps **uniques**
- Emplois du temps cachables ou fermables
- Samedi affiché si cours
- *Loading images*

-------------------------------------------

## Mobile

<img src="assets/mobile_framed.png" alt="Architecture" class="w100" />

-------------------------------------------

## Desktop

<br />
DEMO
<br />
<br />
Essayez-moi à :
<br />
<a target="_blank" id="ip_a" href="">http://<span id="ip"></span>:8080</a>

<script>
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET","http://127.0.0.1:8080/ip.php",true);
    xmlhttp.onreadystatechange = function () {
        if (xmlhttp.readyState !== XMLHttpRequest.DONE) {
            return;
        }
        if (xmlhttp.status !== 200) {
            return;
        }
        else {
            hostipInfo = xmlhttp.responseText;
            document.querySelector("#ip").innerHTML = hostipInfo;
            document.querySelector("#ip_a").href = "http://"+hostipInfo+":8080";
        }
    };
    xmlhttp.send();
</script>

-------------------------------------------

Merci

_

Q & A
