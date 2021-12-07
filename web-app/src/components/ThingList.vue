<template>
  <div class="d-flex">
    <i :class="[thing.icon]"></i>
    <i class="pe-1"></i>
    <strong> {{ thing.name }} </strong>
    <div class="ms-auto">
      <!-- Button trigger modal -->
      <button
        class="btn btn-white"
        type="button"
        data-bs-toggle="modal"
        data-bs-target="#Modal1"
      >
        <i class="fas fa-trash text-dark"></i>

        <!-- Modal -->
        <div
          class="modal fade"
          id="Modal1"
          tabindex="-1"
          aria-labelledby="exampleModalLabel"
          aria-hidden="true"
        >
          <div class="modal-dialog">
            <div class="modal-content">
              <div class="modal-header">
                <h5 class="modal-title text-danger" id="exampleModalLabel">
                  <strong>Atenção!</strong>
                </h5>
                <button
                  type="button"
                  class="btn-close"
                  data-bs-dismiss="modal"
                  aria-label="Ok"
                ></button>
              </div>
              <div class="modal-body">O seu item vai ser elimindado da base de dados! Tem a certeza?</div>
              <div class="modal-footer">
                <button
                  type="button"
                  class="btn btn-secondary"
                  data-bs-dismiss="modal"
                  @click="onClick()"
                >
                  Close
                </button>
              </div>
            </div>
          </div>
        </div>
      </button>
    </div>
  </div>
</template> 

<script>
import { getDatabase, set, ref } from "firebase/database";

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
      
      this.$parent.things.splice(this.$parent.things.indexOf(this.thing),1);
      console.log(this.things);
      set(ref(getDatabase(), this.$parent.title), this.$parent.things);
      console.log("O Seu sensor foi apagado da firabase");
    },
  },
};
</script>