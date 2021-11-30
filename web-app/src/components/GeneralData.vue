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
                      <OpenItem :title="'Temperatura'" :icon="'fas fa-temperature-high'" :textColor="'text-dark'" />
                      <OpenItem :title="'Sensação térmica'" :icon="'fas fa-temperature-high'" :textColor="'text-warning'" />
                      <OpenItem :title="'Temperatura máxima'" :icon="'fas fa-temperature-high'" :textColor="'text-danger'" />
                      <OpenItem :title="'Sensação mínima'" :icon="'fas fa-temperature-low'" :textColor="'text-primary'" />
                      <ZoneCard :title="'Estufa'" />
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-sun text-warning"></i>
                        <i class="pe-1"></i>
                        <strong> Nascer do sol </strong>
                        <div id="sunriseTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-moon text-black"></i>
                        <i class="pe-1"></i>
                        <strong> Pôr do sol </strong>
                        <div id="sunsetTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
<<<<<<< HEAD
                        <i class="fas fa-tint text-success pe-1"></i>
=======
                        <i class="fas fa-percentage text-info"></i>
                        <i class="pe-1"></i>
>>>>>>> b9a62eb65709ed90b3ed1deb6cc86b7a72eb9975
                        <strong> Humidade </strong>
                        <div id="fetchedTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-cloud text-info"></i>
                        <i class="pe-1"></i>
                        <strong> Nebulosidade </strong>
                        <div id="fetchedTime" class="ms-auto"></div>
                      </div>
                    </div>
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-wind text-muted"></i>
                        <i class="pe-1"></i>
                        <strong> Velocidade do vento </strong>
                        <div id="sunriseTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-wind text-muted"></i>
                        <i class="pe-1"></i>
                        <strong> Sentido do vento </strong>
                        <div id="sunsetTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-cloud-rain text-info"></i>
                        <i class="pe-1"></i>
                        <strong> Volume de chuva na última hora </strong>
                        <div id="fetchedTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-snowflake text-primary"></i>
                        <i class="pe-1"></i>
                        <strong> Volume de neve na última hora </strong>
                        <div id="fetchedTime" class="ms-auto"></div>
                      </div>
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
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-hospital-user text-danger"></i>
                        <i class="pe-1"></i>
                        <strong>
                          Casos confirmados nos últimos 14 dias em Leiria
                        </strong>
                        <div id="currentTemp" class="ms-auto"></div>
                      </div>
                    </div>
                    <CovidItem :title="'Casos comfirmados no último dia em Leiria'" :icon="'fas fa-hospital-user'" :textColor="'text-danger'" />
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
                    <div class="card">
                      <div class="card-body">
                        <h5 class="card-title text-center">Sensores</h5>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-thermometer-half"></i>
                            <i class="pe-1"></i>
                            <strong> Temperatura </strong>
                            <div id="currentTemp" class="ms-auto"></div>
                          </div>
                        </div>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-percentage text-info"></i>
                            <i class="pe-1"></i>
                            <strong> Humidade do ar </strong>
                            <div id="currentTemp" class="ms-auto"></div>
                          </div>
                        </div>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-percentage text-info"></i>
                            <i class="pe-1"></i>
                            <strong> Humidade do solo </strong>
                            <div id="maxTemp" class="ms-auto"></div>
                          </div>
                        </div>
                      </div>
                    </div>
                    <span class="border border-bottom-0"></span>
                    <div class="card">
                      <div class="card-body">
                        <h5 class="card-title text-center">Atuador</h5>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-fan text-success"></i>
                            <i class="pe-1"></i>
                            <strong> Velocidade da ventoinha </strong>
                            <div id="currentTemp" class="ms-auto"></div>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title">Jardim da Piscina</h5>
                    <div class="card">
                      <div class="card-body">
                        <h5 class="card-title text-center">Sensores</h5>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-thermometer-half"></i>
                            <i class="pe-1"></i>
                            <strong> Temperatura </strong>
                            <div id="currentTemp" class="ms-auto"></div>
                          </div>
                        </div>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-sun text-warning"></i>
                            <i class="pe-1"></i>
                            <strong> Exposição solar </strong>
                            <div id="currentTemp" class="ms-auto"></div>
                          </div>
                        </div>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-percentage text-info"></i>
                            <i class="pe-1"></i>
                            <strong> Humidade do solo </strong>
                            <div id="maxTemp" class="ms-auto"></div>
                          </div>
                        </div>
                      </div>
                    </div>
                    <span class="border border-bottom-0"></span>
                    <div class="card">
                      <div class="card-body">
                        <h5 class="card-title text-center">Atuador</h5>
                        <div>
                          <div class="d-flex">
                            <i class="fas fa-water text-primary"></i>
                            <i class="pe-1"></i>
                            <strong> Irrigadores </strong>
                            <div id="currentTemp" class="ms-auto"></div>
                          </div>
                        </div>
                      </div>
                    </div>
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
import ZoneCard from './ZoneCard.vue'
import OpenItem from './OpenItem.vue'
import CovidItem from './CovidItem.vue'
export default {
  name: "GeneralData",
  components: {
    ZoneCard,
    OpenItem, 
    CovidItem
  },
  data(){
    return{
      sensores: [], 
    }
  }
};
</script>                                                                                                                                               