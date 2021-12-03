<template>
  <div>
    <span class="border border-bottom-0"></span>
    <div class="container-fluid">
      <div class="row">
        <div class="col-md">
          <div class="card">
            <div class="card-body">
              <h4 class="card-title text-center">Informação do Ambiente</h4>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <div v-for="firstItem in firstItems" :key="firstItem.id">
                      <OpenItem
                        :title="firstItem.title"
                        :icon="firstItem.icon"
                        :openKey="firstItem.openKey"
                        :unit="firstItem.unit"
                      />
                    </div>
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <div v-for="firstTime in firstTimes" :key="firstTime.id">
                      <OpenTime
                        :title="firstTime.title"
                        :icon="firstTime.icon"
                        :openKey="firstTime.openKey"
                        :unit="firstTime.unit"
                      />
                    </div>
                    <div v-for="secondItem in secondItems" :key="secondItem.id">
                      <OpenItem
                        :title="secondItem.title"
                        :icon="secondItem.icon"
                        :openKey="secondItem.openKey"
                        :unit="secondItem.unit"
                      />
                    </div>
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <div v-for="thirdItem in thirdItems" :key="thirdItem.id">
                      <OpenItem
                        :title="thirdItem.title"
                        :icon="thirdItem.icon"
                        :openKey="thirdItem.openKey"
                        :unit="thirdItem.unit"
                      />
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <span class="border border-bottom-0"></span>
    <div class="container-fluid">
      <div class="row">
        <div class="col-md">
          <div class="card">
            <div class="card-body">
              <h4 class="card-title text-center">Noticias covid-19</h4>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <div v-for="covidItem in covidItems" :key="covidItem.id">
                      <CovidItem
                        :title="covidItem.title"
                        :icon="covidItem.icon"
                        :covidKey="covidItem.covidKey"
                      />
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <span class="border border-bottom-0"></span>
    <div class="container-fluid">
      <div class="row">
        <div class="col-md">
          <div class="card">
            <div class="card-body">
              <h4 class="card-title text-center">
                Zonas de controlo e monitorização
              </h4>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title">Estufa</h5>
                    <ZoneCard :title="'Estufa'" />
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title">Jardim da Piscina</h5>
                    <ZoneCard :title="'JardimPiscina'" />
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import ZoneCard from "./ZoneCard.vue";
import OpenItem from "./OpenItem.vue";
import OpenTime from "./OpenTime.vue";
import uniqueId from "lodash.uniqueid";
import CovidItem from "./CovidItem.vue";

export default {
  name: "GeneralData",
  components: {
    ZoneCard,
    OpenItem,
    OpenTime,
    CovidItem,
  },
  data() {
    return {
      firstItems: [
        {
          id: uniqueId("todo-"),
          title: "Temperatura",
          icon: "fas fa-thermometer-half text-dark",
          openKey: "main.temp",
          unit: "ºC",
        },
        {
          id: uniqueId("todo-"),
          title: "Sensação térmica",
          icon: "fas fa-thermometer-half text-warning",
          openKey: "main.feels_like",
          unit: "ºC",
        },
        {
          id: uniqueId("todo-"),
          title: "Temperatura mínima",
          icon: "fas fa-temperature-low text-primary",
          openKey: "main.temp_min",
          unit: "ºC",
        },
        {
          id: uniqueId("todo-"),
          title: "Temperatura máxima",
          icon: "fas fa-temperature-high text-danger",
          openKey: "main.temp_max",
          unit: "ºC",
        },
      ],
      secondItems: [
        {
          id: uniqueId("todo-"),
          title: "Humidade",
          icon: "fas fa-percentage text-info",
          openKey: "main.humidity",
          unit: "%",
        },
        {
          id: uniqueId("todo-"),
          title: "Nebulosidade",
          icon: "fas fa-cloud text-muted",
          openKey: "clouds.all",
          unit: "%",
        },
      ],
      thirdItems: [
        {
          id: uniqueId("todo-"),
          title: "Velocidade do vento",
          icon: "fas fa-wind text-muted",
          openKey: "wind.speed",
          unit: "km/h",
        },
        {
          id: uniqueId("todo-"),
          title: "Sentido do vento",
          icon: "fas fa-wind text-muted",
          openKey: "wind.deg",
          unit: "º",
        },
        {
          id: uniqueId("todo-"),
          title: "Volume de chuva na última hora",
          icon: "fas fa-cloud-rain text-info",
          openKey: "rain.1h",
          unit: "m3",
        },
        {
          id: uniqueId("todo-"),
          title: "Volume de neve na última hora",
          icon: "fas fa-snowflake text-primary",
          openKey: "snow.1h",
          unit: "m3",
        },
      ],
      firstTimes: [
        {
          id: uniqueId("todo-"),
          title: "Nascer do sol",
          icon: "fas fa-sun text-warning",
          openKey: "sys.sunrise",
          unit: "h"
        },
        {
          id: uniqueId("todo-"),
          title: "Pôr do sol",
          icon: "fas fa-moon text-dark",
          openKey: "sys.sunset",
          unit:"h"
        },
      ],
      covidItems: [
        {
          id: uniqueId("todo-"),
          title: "Total de casos confirmados em Portugal",
          icon: "fas fa-hospital-user text-danger",
          covidKey: "confirmados",
        },
        {
          id: uniqueId("todo-"),
          title: "Casos comfirmados no último dia em Portugal",
          icon: "fas fa-hospital-user text-danger",
          covidKey: "confirmados_novos",
        },
      ],
    };
  },
};
</script>                                                                                                                                               