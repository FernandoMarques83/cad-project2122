<template>
    <div class="d-flex">
      <i :class="[thing.icon]"></i>
      <i class="pe-1"></i>
      <strong> {{ thing.name }} </strong>
      <div class="ms-auto">
        <i class="fas fa-trash text-dark"></i> 
      </div>
    </div>
</template> 

<script>
import { getDatabase, ref, set, onValue } from "firebase/database";

export default {
  name: "ThingList",
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