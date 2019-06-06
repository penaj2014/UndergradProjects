var report_miles = function (kilometers, miles) {
    document.getElementById("result").innerHTML =
        
        kilometers + " Kilometer(s) = " + miles + " mile(s)";
};

var report_kilometers = function (miles, kilometers) {
    document.getElementById("result").innerHTML =
        
        miles + " Miles(s) = " + kilometers + " Kilometers(s)";
};

window.document.getElementById("k_to_m").onclick = function () {
    var m = document.getElementById("distance").value;
    report_miles(m, m / 1.600934);
};

window.document.getElementById("m_to_k").onclick = function () {
    var k = document.getElementById("distance").value;
    report_kilometers(k, k / 0.621371);
};