<template>
  <div class="card-group">
    <div class="card">
      <div class="card-body">
        <div>
          <NotComponents v-for="thing in things" :key="thing" :thing="thing" />
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import { getDatabase, ref, onValue } from "firebase/database";
import NotComponents from "./NotComponents.vue";

export default {
  name: "Notifications",
  props: ["title"],
  components: {
    NotComponents,
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
      }
      this.things = snapshot.val();
    });
  },
};
</script>