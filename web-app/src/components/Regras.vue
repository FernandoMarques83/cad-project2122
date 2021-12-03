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
                    <h4 class="card-title text-center">Estufa</h4>
                    <Notifications :title="'Estufa'" />
                  </div>
                </div>
                <div class="card">
                  <div class="card-body">
                    <h4 class="card-title text-center">Jardim da Piscina</h4>
                    <Notifications :title="'JardimPiscina'" />
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
