<template>

  <div>
    <span class="border border-bottom-0"></span>
    <div class="container-fluid">
      <div class="row">
        <div class="col-md">
          <div class="card">
            <div class="card-body">
              <h5 class="card-title text-center">Informação do Ambiente</h5>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-temperature-high text-dark"></i>
                        <i class="pe-1"></i>
                        <strong> Temperatura </strong>
                        <div id="currentTemp" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-temperature-high text-warning"></i>
                        <i class="pe-1"></i>
                        <strong> Sensação térmica </strong>
                        <div id="currentTemp" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-temperature-high text-danger"></i>
                        <i class="pe-1"></i>
                        <strong> Temperatura máxima </strong>
                        <div id="maxTemp" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-temperature-low text-primary"></i>
                        <i class="pe-1"></i>
                        <strong> Temperatura mínima</strong>
                        <div id="minTemp" class="ms-auto"></div>
                      </div>
                    </div>
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
                        <i class="fas fa-percentage text-info"></i>
                        <i class="pe-1"></i>
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
              <h5 class="card-title text-center">Noticias covid-19</h5>
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
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-hospital-user text-danger"></i>
                        <i class="pe-1"></i>
                        <strong>
                          Casos comfirmados no último dia em Leiria
                        </strong>
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
    <span class="border border-bottom-0"></span>
    <div class="container-fluid">
      <div class="row">
        <div class="col-md">
          <div class="card">
            <div class="card-body">
              <h5 class="card-title text-center">
                Zonas de controlo e monitorização
              </h5>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title text-center">Estufa</h5>
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
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title text-center">Jardim da Piscina</h5>
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
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "GeneralData",
  componets:{
      
  }
};
</script>