<template>
  <div>
    <h4 class="text-center">Remover Sensores / Atuadores</h4>
    <div class="container-fluid mt-3">
      <div class="mt-2 row g-2">
        <div class="col-md-6">
          <div class="card">
            <div class="card-body">
              <h5 class="card-title">Estufa</h5>
              <DeleteSensAct :title="'Estufa'" />
            </div>
          </div>
        </div>
        <div class="col-md-6">
          <div class="card">
            <div class="card-body">
              <h5 class="card-title">Jardim da Piscina</h5>
              <DeleteSensAct :title="'JardimPiscina'" />
            </div>
          </div>
        </div>
      </div>
    </div>

    <h4 class="text-center">Adicionar Sensores / Atuadores</h4>
    <div class="container-fluid mt-3">
      <div class="mt-2 row g-2">
        <div class="col-md-6">
          <div class="card">
            <div class="card-body">
              <h5 class="card-title">Estufa</h5>
             <CreateSensAct :title="'Estufa'"/>
            </div>
          </div>
            </div>
          <div class="col-md-6">
            <div class="card">
              <div class="card-body">
                <h5 class="card-title">Jardim da Piscina</h5> 
               <CreateSensAct :title="'JardimPiscina'"/>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
</template>


<script>
import DeleteSensAct from "./DeleteSensAct.vue";
import CreateSensAct from "./CreateSensAct.vue";

export default {
  name: "Add",
  props: ["title"],
  components: {
    DeleteSensAct,
    CreateSensAct,
  },
};
</script>
