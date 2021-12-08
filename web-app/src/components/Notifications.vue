<template>
  <div class="card-group">
    <div class="card">
      <div class="card-body">
        <div>
          <NotComponents v-for="thing in things" :key="thing" :thing="thing" />
        </div>
      </div>
      <div class="card-body">
        <h5 class="card-title text-center">Definição de limiares</h5>
        <div>
          <LimitComponents
            v-for="thing in things"
            :key="thing"
            :thing="thing"
          />
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import { getDatabase, ref, onValue } from "firebase/database";
import NotComponents from "./NotComponents.vue";
import LimitComponents from "./LimitComponents.vue";

export default {
  name: "Notifications",
  props: ["title"],
  components: {
    NotComponents,
    LimitComponents,
  },
  data() {
    return {
      things: [],
    };
  },
  mounted() {
    onValue(ref(getDatabase(), this.title), (snapshot) => {
      if (snapshot.exists()) {
        this.things = snapshot.val();
      }
    });
  },
};
</script>