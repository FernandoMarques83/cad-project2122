<template>
  <div v-if="thing.type == 'sensor'">
    <div v-if="flag == true">
      <div v-if="value.value < value.min">
        <div
          class="alert alert-primary alert-dismissible fade show"
          role="alert"
        >
          <strong>Alerta !! Valor de {{thing.name}} inferior ao limite mínimo </strong>
          <button
            type="button"
            class="btn-close"
            data-bs-dismiss="alert"
            aria-label="Close"
          ></button>
        </div>
      </div>
      <div v-else-if="value.value > value.max">
        <div
          class="alert alert-danger alert-dismissible fade show"
          role="alert"
        >
          <strong>Alerta !! Valor de {{thing.name}} superior ao limite máximo </strong>
          <button
            type="button"
            class="btn-close"
            data-bs-dismiss="alert"
            aria-label="Close"
          ></button>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import { getDatabase, ref, onValue } from "firebase/database";

export default {
  name: "Alert",
  props: ["thing"],
  data() {
    return {
      value: "",
      flag: "",
    };
  },
  mounted() {
    onValue(ref(getDatabase(), this.thing.notPath), (snapshot) => {
      if (snapshot.exists()) {
        this.flag = snapshot.val();
      }
    });
    onValue(ref(getDatabase(), this.thing.path), (snapshot) => {
      if (snapshot.exists()) {
        this.value = snapshot.val();
      }
    });
  },
};
</script>