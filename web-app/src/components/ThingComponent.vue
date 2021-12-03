<template>
  <div v-if="thing.type == 'sensor'">
    <div class="d-flex">
      <i :class="[thing.icon]"></i>
      <i class="pe-1"></i>
      <strong> {{ thing.name }} </strong>
      <div class="ms-auto">
        {{ value.value }}
        {{ thing.var }}
      </div>
    </div>
  </div>
  <div v-else-if="thing.type == 'actuator'">
    <div class="d-flex">
      <i :class="[thing.icon]"></i>
      <i class="pe-1"></i>
      <strong> {{ thing.name }} </strong>
      <div class="ms-auto">
        <button v-if="value" class="btn btn-danger" @click="onClick()">
          Turn Off
        </button>
        <button v-else class="btn btn-success" @click="onClick()">
          Turn On
        </button>
      </div>
    </div>
  </div>
  <div v-else-if="thing.type == 'slider'">
    <div class="d-flex">
      <i :class="[thing.icon]"></i>
      <i class="pe-1"></i>
      <strong> {{ thing.name }} </strong>
      <p>:</p>
      <i class="pe-1"></i>
      <span v-text="total"></span>
      <div class="ms-auto">
        <input
          v-model="sliderVal"
          type="range"
          min="0"
          max="100"
          step="1"
          @change="onChange()"
        />
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
      sliderVal: "",
    };
  },
  methods: {
    onClick() {
      set(ref(getDatabase(), this.thing.path), !this.value);
    },
    onChange() {
      set(ref(getDatabase(), this.thing.path), this.sliderVal);
      console.log("change!", this.sliderVal);
    },
  },
  computed: {
    total: function () {
      return this.sliderVal;
    },
  },
  mounted() {
    onValue(ref(getDatabase(), this.thing.path), (snapshot) => {
      if (snapshot.exists()) {
        this.value = snapshot.val();
        this.sliderVal = snapshot.val();
      }
    });
  },
};
</script>