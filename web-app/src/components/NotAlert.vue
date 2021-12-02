<template>
  <div v-if="thing.type == 'sensor'">
    <div v-if="value == true">
      <div class="alert alert-warning alert-dismissible fade show" role="alert">
        <strong>{{ value }}</strong>
        <button
          type="button"
          class="btn-close"
          data-bs-dismiss="alert"
          aria-label="Close"
        ></button>
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
    };
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