<template>
  <div>
    <span class="border border-bottom-0"></span>
    <div class="container-fluid">
      <div class="row">
        <div class="col-md">
          <div class="card">
            <div class="card-body">
              <h4 class="card-title text-center">Remover Sensores</h4>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-thermometer-half text-dark"></i>
                        <i class="pe-1"></i>
                        <strong> Temperatura </strong>
                        <div id="currentTemp" class="ms-auto">{{ msg }}</div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-percentage text-info"></i>
                        <i class="pe-1"></i>
                        <strong> Humidade do ar </strong>
                        <div id="currentTemp" class="ms-auto"></div>
                        <toggle :title="lampada"></toggle>
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
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-thermometer-half"></i>
                        <i class="pe-1"></i>
                        <strong> Temperatura</strong>
                        <div id="sunriseTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-sun text-warning"></i>
                        <i class="pe-1"></i>
                        <strong> Exposição solar </strong>
                        <div id="sunsetTime" class="ms-auto"></div>
                      </div>
                    </div>
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-percentage text-info"></i>
                        <i class="pe-1"></i>
                        <strong> Humidade do solo </strong>
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
              <h4 class="card-title text-center">Remover Atuadores</h4>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-fan text-success"></i>
                        <i class="pe-1"></i>
                        <strong> Velocidade da ventoinha </strong>
                        <div id="currentTemp" class="ms-auto">{{ msg }}</div>
                      </div>
                    </div>
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <div>
                      <div class="d-flex">
                        <i class="fas fa-water text-primary"></i>
                        <i class="pe-1"></i>
                        <strong> Irrigadores </strong>
                        <div id="sunriseTime" class="ms-auto"></div>
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
              <h4 class="card-title text-center">Adicionar Sensores</h4>
              <div class="card-group">



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
              <h4 class="card-title text-center">Adicionar Atuadores</h4>
              <div class="card-group">



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
  name: "Add",
  components: {},
};
</script>
