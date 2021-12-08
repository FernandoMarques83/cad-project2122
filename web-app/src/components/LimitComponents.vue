<template>
  <div class="card">
    <div class="card-body">
      <div v-if="thing.type == 'sensor'">
        <div class="d-flex">
          <i class="fas fa-arrow-down text-primary"></i>
          <i class="pe-1"></i>
          <strong> Limiar inferior da {{ thing.name }} </strong>
          <div class="ms-auto">
            <div class="row justify-content-md-center">
              <div class="col-md-auto">Atual: {{ limits.min }}</div>
              <div class="col-6">
                <input
                  type="text"
                  class="form-control"
                  size="sm"
                  v-model="min"
                  placeholder="Insira o valor"
                  :maxlength="enterLimit()"
                  @keyup.enter="onEnter(0)"
                />
              </div>
            </div>
          </div>
        </div>
        <div class="d-flex">
          <i class="fas fa-arrow-up text-danger"></i>
          <i class="pe-1"></i>
          <strong> Limite superior da {{ thing.name }} </strong>
          <div class="ms-auto">
            <div class="row justify-content-md-center">
              <div class="col-md-auto">Atual: {{ limits.max }}</div>
              <div class="col-6">
                <input
                  type="text"
                  class="form-control"
                  size="sm"
                  v-model="max"
                  placeholder="Insira o valor"
                  :maxlength="enterLimit()"
                  @keyup.enter="onEnter(1)"
                />
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template> 

<script>
import { getDatabase, ref, set, onValue } from "firebase/database";

export default {
  name: "LimitComponents",
  props: ["thing"],
  data() {
    return {
      limits: "",
      min: "",
      minV: "",
      max: "",
      maxV: "",
    };
  },
  methods: {
    onEnter(m) {
      if (m == 0) {
        this.minV = this.min;
        this.min = "";
        set(ref(getDatabase(), this.thing.path + "/min"), this.minV);
      } else if (m == 1) {
        this.maxV = this.max;
        this.max = "";
        set(ref(getDatabase(), this.thing.path + "/max"), this.maxV);
      }
    },
    enterLimit(){
      if (this.thing.path == "/sensor5"){
        return 4;
      }
      else{
        return 2;
      }
    },
  },
  mounted() {
    onValue(ref(getDatabase(), this.thing.path), (snapshot) => {
      if (snapshot.exists()) {
        this.limits = snapshot.val();
      }
    });
  },
};
</script>