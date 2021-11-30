<template>
  <div>
    <div class="d-flex">
      <i :class="[thing.icon]"></i>
      <i class="pe-1"></i>
      <strong> {{ thing.name }} </strong>
      <div class="ms-auto">
        <p>{{value}}</p>
      </div>
    </div>
  </div>
  <button v-if="value" class="btn btn-danger" @click="onClick()">Turn Off</button>
  <button v-else class="btn btn-success" @click="onClick()">Turn On</button>

</template> 

<script>
import { getDatabase, ref, set, onValue } from "firebase/database";

export default {
  name: "ThingComponent",
  props: ["thing"],
  data(){
    return{
      value: ''
    }
  },
  methods: {
    onClick(){
      set(ref(getDatabase(), this.thing.path), !this.value)
    }
  },
  mounted() {
    onValue(ref(getDatabase(), this.thing.path), (snapshot) => {
      if (snapshot.exists()) {
        this.value = snapshot.val();
      }
    });
  },
};
</script>