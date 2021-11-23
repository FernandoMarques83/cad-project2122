$(function () {

    var configurarBotao = function (idBotao, idToggle, idIcon, flag) {

        var changeL = function (toggleClass, iconClass, iconS1, iconS2, iconColor1, iconColor2) {

            iconClass.toggleClass('fa-toggle-off fa-toggle-on');
            toggleClass.toggleClass(iconS1 + ' ' + iconS2);
            toggleClass.toggleClass(iconColor1 + ' ' + iconColor2);

        }

        var idBotao = $("#" + idBotao);
        var idToggle = $("#" + idToggle);
        var idIcon = $("#" + idIcon);

        idBotao.click(function (e) {

            console.log("Here");

            if (flag == 1) {

                changeL(idIcon, idToggle, 'far', 'fas', 'text-dark', 'text-warning');

            }
            else if (flag == 2) {
                changeL(idIcon, idToggle, 'fa-music', 'fa-volume-mute', 'text-primary', 'text-danger');
            }
        });

    }

    var mudaTemperatura = function () {
        var newKT = 21 + (Math.random() * 2) - 1;
        var newLVT = 22 + (Math.random() * 4) - 2;
        newKT = newKT.toFixed(1);
        newLVT = newLVT.toFixed(1);
        idKitchenTemp.html(newKT + ' ' + 'ºC');
        idLivingTemp.html(newLVT + ' ' + 'ºC');
    }

    function timeStamp() {
        var date;
        date = new Date();
        var time = date.getHours() + ":" + date.getMinutes(); + ":" + date.getSeconds();
        var day = date.getDate() + "-" + (date.getMonth() + 1) + "-" + date.getFullYear();
        timeNow.html(time);
        dateNow.html(day);
    }


    var idKitchenTemp = $('#kitchenTemp');
    var idLivingTemp = $('#livingTemp');
    var timeNow = $('#time');
    var dateNow = $('#date');

    var intervalID = setInterval(mudaTemperatura, 2000);
    var interval = setInterval(timeStamp, 1000);
    var timer = setInterval(timer, 1000);

    configurarBotao('kitchenLights', 'iconKL', 'bulbIcon', 1);
    configurarBotao('ceilingLights', 'iconCL', 'bulbIcon2', 1);
    configurarBotao('ambientLights', 'iconAL', 'bulbIcon3', 1);
    configurarBotao('ambientMusic', 'iconAM', 'bulbIcon4', 2);


    apiKey = "c4f0bb5761f8ca78a024fbbee994cd0e";
    var tempId = $('#currentTemp');
    var minTempId = $('#minTemp');
    var maxTempId = $('#maxTemp');
    var humidityId = $('#humidity');
    var sunriseId = $('#sunriseTime');
    var sunsetId = $('#sunsetTime');
    var updateId = $('#fetchedTime');

    
    $.getJSON("http://api.openweathermap.org/data/2.5/weather?units=metric&q=leiria&appid=c4f0bb5761f8ca78a024fbbee994cd0e" + "&appid=" + apiKey, function (data) {

        temp = data["main"]["temp"];
        maxTemp = data["main"]["temp_max"];
        minTemp = data["main"]["temp_min"];
        humidity = data["main"]["humidity"];
        sunRise = unixTime(data["sys"]["sunrise"]);
        sunSet = unixTime(data["sys"]["sunset"]);

        /*console.log("Temperatura " + temp + " Max " + maxTemp + " Min " + minTemp + " Humidity " + humidity); */
        
        tempId.text(temp + " ºC");
        minTempId.text(minTemp + " ºC");
        maxTempId.text(maxTemp + " ºC");
        humidityId.text(humidity + " %");
        sunriseId.text(sunRise);
        sunsetId.text(sunSet);

    })

    $.getJSON("https://covid19-api.vost.pt/Requests/get_last_update", function (data) {

        LastUpdate = data["data"];
        TotalCasosPT = data["confirmados"];
        CasosDiaPT = data["confirmados_novos"];
        console.log("Total de casos " + TotalCasosPT);
        console.log(CasosDiaPT + " casos no dia " + LastUpdate);

    })

    function unixTime(s){

        var date = new Date(s * 1000);
        var hours = date.getHours();
        var minutes = "0" + date.getMinutes();
        var seconds = "0" + date.getSeconds();
        
        return formattedTime = hours + 'h' + minutes.substr(-2) ;
    }
    var time = 0;

    function timer(){
        time += 1;
        updateTime(time)
    }

    function updateTime(t){
        if (t < 60)
        {
            if ( t == 1)
            {
                updateId.text(t + " second ago");
            }
            else
            {
                updateId.text(t + " seconds ago");
            }
        }
        else if ( t < 3600)
        {
            var m = Math.floor(t/60);
            if ( m == 1)
            {
                updateId.text(m + " minute ago");
            }
            else
            {
                updateId.text(m + " minutes ago");
            }
        }
        else 
        {
            var h = Math.floor(t/60/60);
            if ( h == 1)
            {
                updateId.text(h + " hour ago");
            }
            else
            {
                updateId.text(h + " hours ago");
            }
        }
    }
});