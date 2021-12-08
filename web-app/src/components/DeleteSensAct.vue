<template>
  <div class="card-group">
    <div class="card">
      <div class="card-body">
        <div>
          <ThingList
            v-for="thing in things"
            :key="thing.name"
            :thing="thing"
          />
        </div>
      </div>
    </div>
  </div>
</template>


<script>
import { getDatabase, ref, onValue, set } from "firebase/database";
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
  methods: {
    removeThing(thing) {
     var index = -1;
     console.log(thing.name);
     for (var i =0; i< this.things.length; i++ ){
       if (this.things[i].name == thing.name){
         index =i;
       }
       console.log(this.things[i].name);
       }
      console.log(index);
      this.things.splice(index ,1);

      console.log(this.things);
      set(ref(getDatabase(), this.title), this.things);
      console.log("O Seu sensor foi apagado da firabase");
    },
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