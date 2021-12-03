<template>
  <div>
      <p><i class='fas fa-folder-plus fa-2x' style='color:#008000'></i></p>
  <div class="input-group mb-3">
    <span class="input-group-text" id="inputGroup-sizing-default">Nome</span>
    <input
      type="text"
      class="form-control"
      aria-label="Sizing example input"
      aria-describedby="inputGroup-sizing-default"
    />
  </div>

  <div class="input-group mb-3">
    <span class="input-group-text" id="inputGroup-sizing-default">Caminho</span>
    <input
      type="text"
      class="form-control"
      aria-label="Sizing example input"
      aria-describedby="inputGroup-sizing-default"
    />
  </div>

  <div class="input-group mb-3">
    <span class="input-group-text" id="inputGroup-sizing-default">Tipo</span>
    <input
      type="text"
      class="form-control"
      aria-label="Sizing example input"
      aria-describedby="inputGroup-sizing-default"
    />
  </div>

   <div class="input-group mb-3">
    <span class="input-group-text" id="inputGroup-sizing-default">Icone</span>
    <input
      type="text"
      class="form-control"
      aria-label="Sizing example input"
      aria-describedby="inputGroup-sizing-default"
    />
  </div>
  </div>

</template>


<script>
import { getDatabase, ref, onValue } from "firebase/database";

export default {
  name: "CreaeteSensAct",
  props: ["title"],
  components: {
  },
  data() {
    return {
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