<template>
  <div class="card-group">
    <div class="card">
      <div class="card-body">
        <div>
          <ThingComponent v-for="thing in things" :key="thing" :thing="thing" />
          <NotAlert v-for="thing in things" :key="thing" :thing="thing"/>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import { getDatabase, ref, onValue } from "firebase/database";
import ThingComponent from "./ThingComponent.vue";
import NotAlert from "./NotAlert.vue"

export default {
  name: "ZoneCard",
  props: ["title"],
  components: {
    ThingComponent,
    NotAlert
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
