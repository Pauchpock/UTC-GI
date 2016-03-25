var students = {};

function ajax(form) {
    var login = form[0].value;
    if (students[login]) {
        alert("L'emploi du temps de cet étudiant est déjà affiché.");
        return;
    }
    students[login] = true;
    showLoader(login);

    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open(form.method, form.action+"?"+form[0].name+"="+login, true);
    xmlhttp.onreadystatechange = function () {
        if (xmlhttp.readyState !== XMLHttpRequest.DONE) {
            return;
        }
        if (xmlhttp.status !== 200) {
            switch (xmlhttp.status) {
                case 555:
                    alert("L'API des emplois du temps n'est pas disponible.");
                    break;
                case 404:
                    alert("Aucun emploi du temps trouvé pour ce login.");
                    break;
                default:
                    alert('Erreur inconnue.');
            }
            _close(login);
        }
        else {
            var result = xmlhttp.responseText;
            displayEDT(result, login);
        }
    };
    xmlhttp.send();
}

function toggleVisibility(el) {
    var parent = el.parentNode;
    var table = parent.querySelector("table");
    if (table.classList.contains('hidden')) {
        table.classList.remove('hidden');
    }
    else {
        table.classList.add('hidden');
    }
}

function showLoader(login) {
    var _div = "<div class='edt student"+login+"'><div class='loader_container'><img src='loader.gif' alt='Loading...' /></div></div>";
    var edts = document.getElementById("edts").innerHTML;
    document.getElementById("edts").innerHTML = _div + edts;
}

function displayEDT(table, login) {
    var _div = document.querySelector('.edt.student'+login);
    _div.innerHTML = "<img src='close.png' alt='Close' onclick='_close(\""+login+"\");' class='close' /><h2 onclick='toggleVisibility(this);'>"+login+"</h2>"+table+"</div>";
}

function _close(login) {
    var _class = "student"+login;
    console.log("closing");
    console.log('.edt.'+_class);
    var el = document.querySelector('.edt.'+_class);
    document.getElementById('edts').removeChild(el);
    delete students[login];
}
