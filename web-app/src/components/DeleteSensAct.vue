<template>
  <div class="card-group">
    <div class="card">
      <div class="card-body">
        <div>
          <ThingList v-for="thing in things" :key="thing" :thing="thing" />
        </div>
      </div>
    </div>
  </div>
</template>


<script>
import { getDatabase, ref, onValue } from "firebase/database";
import ThingList from "./ThingList.vue";

export default {
  name: "DeleteSensAct",
  props: ["title"],
  components: {
    ThingList,
  },
  data() {
    return {
      things: [],
    };
  },
  mounted() {
    onValue(ref(getDatabase(), this.title), (snapshot) => {
      if (snapshot.exists()) {
        console.log(snapshot.val());
        this.things = snapshot.val();
      }
    });
  },
};
</script>