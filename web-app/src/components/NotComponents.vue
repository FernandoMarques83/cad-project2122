<template>
  <div v-if="thing.type == 'sensor'">
    <div class="d-flex">
      <div v-if="value == true">
        <i class="far fa-flag text-success"></i>
      </div>
      <div v-else-if="value == false">
        <i class="far fa-flag text-danger"></i>
      </div>
      <i class="pe-1"></i>
      <strong> Notificação para a {{ thing.name }} </strong>
      <div class="ms-auto">
        <button v-if="value" class="btn btn-outline-danger" @click="onClick()">
          Turn Off
        </button>
        <button v-else class="btn btn-outline-success" @click="onClick()">
          Turn On
        </button>
      </div>
    </div>
  </div>
</template> 

<script>
import { getDatabase, ref, set, onValue } from "firebase/database";

export default {
  name: "ThingComponent",
  props: ["thing"],
  data() {
    return {
      value: "",
    };
  },
  methods: {
    onClick() {
      set(ref(getDatabase(), this.thing.notPath), !this.value);
    }
  },
  mounted() {
    onValue(ref(getDatabase(), this.thing.notPath), (snapshot) => {
      if (snapshot.exists()) {
        this.value = snapshot.val();
      }
    });
  },
};
</script>