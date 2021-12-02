<template>
  <div class="card">
    <div class="card-body">
      <div v-if="thing.type == 'sensor'">
        <div class="d-flex">
          <i class="fas fa-arrow-down text-primary"></i>
          <i class="pe-1"></i>
          <strong> Limiar inferior da {{ thing.name }} </strong>
          <div class="ms-auto">
            {{ limits.min }}
          </div>
        </div>
        <div class="d-flex">
          <i class="fas fa-arrow-up text-danger"></i>
          <i class="pe-1"></i>
          <strong> Limite superior da {{ thing.name }} </strong>
          <div class="ms-auto">
            {{ limits.max }}
          </div>
        </div>
      </div>
    </div>
  </div>
</template> 

<script>
import { getDatabase, ref, update, onValue } from "firebase/database";

export default {
  name: "LimitComponents",
  props: ["thing"],
  data() {
    return {
      value: "",
      limits: "",
    };
  },
  mounted() {
    onValue(ref(getDatabase(), this.thing.notPath), (snapshot) => {
      if (snapshot.exists()) {
        this.value = snapshot.val();
      }
    });
    onValue(ref(getDatabase(), this.thing.path), (snapshot) => {
      if (snapshot.exists()) {
        this.limits = snapshot.val();
      }
    });
  },
};
</script>