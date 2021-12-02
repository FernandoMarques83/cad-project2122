<template>
  <div>
    <span class="border border-bottom-0"></span>
    <div class="container-fluid">
      <div class="row">
        <div class="col-md">
          <div class="card">
            <div class="card-body">
              <h4 class="card-title text-center">Notificações</h4>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title text-center">Estufa</h5>
                    <Notifications :title="'Estufa'" />
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title text-center">Jardim da Piscina</h5>
                    <Notifications :title="'JardimPiscina'" />
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
              <h4 class="card-title text-center">Definição de limiares</h4>
              <div class="card-group">
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title text-center">Estufa</h5>
                    <div class="card-group">
                      <div class="card">
                        <div class="card-body">
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-temperature-low text-primary"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limiar inferior da temperatura
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-temperature-high text-danger"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limite superior da temperatura
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                    <span class="border border-bottom-0"></span>
                    <div class="card-group">
                      <div class="card">
                        <div class="card-body">
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-percentage text-primary"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limiar inferior da humidade do ar
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-percentage text-danger"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limite superior da humidade do ar
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                    <span class="border border-bottom-0"></span>
                    <div class="card-group">
                      <div class="card">
                        <div class="card-body">
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-percentage text-primary"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limiar inferior da humidade do solo
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-percentage text-danger"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limite superior da humidade do solo
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                        </div>
                        
                      </div>
                    </div>
                  </div>
                </div>
                
                <div class="card">
                  <div class="card-body">
                    <h5 class="card-title text-center">Jardim da Piscina</h5>
                    <div class="card-group">
                      <div class="card">
                        <div class="card-body">
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-temperature-low text-primary"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limiar inferior da temperatura
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-temperature-high text-danger"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limite superior da temperatura
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                    <span class="border border-bottom-0"></span>
                    <div class="card-group">
                      <div class="card">
                        <div class="card-body">
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-sun text-primary"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limiar inferior da exposição solar
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-sun text-danger"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limite superior da exposição solar
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                    <span class="border border-bottom-0"></span>
                    <div class="card-group">
                      <div class="card">
                        <div class="card-body">
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-percentage text-primary"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limiar inferior da humidade do solo
                              </strong>
                              <div id="currentTemp" class="ms-auto"></div>
                            </div>
                          </div>
                          <div>
                            <div class="d-flex">
                              <i class="fas fa-percentage text-danger"></i>
                              <i class="pe-1"></i>
                              <strong>
                                Limite superior da humidade do solo
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
        </div>
      </div>
    </div>
  </div>
</template>


<script>
import Notifications  from "./Notifications.vue"
export default {
  name: "Regras",
  components: {
    Notifications
  },
};
</script>
