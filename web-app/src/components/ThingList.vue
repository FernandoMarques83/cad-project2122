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
        :data-bs-target="'#Modal1'+ getThingID()"
      >
        <i class="fas fa-trash text-dark"></i>

        <!-- Modal -->
        <div
          class="modal fade"
          :id="'Modal1'+ getThingID()"
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
                  class="btn btn-primary"
                  data-bs-dismiss="modal"
                  @click="onClick()"
                >
                  Confirm
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


export default {
  name: "ThingList",
  props: ["thing"],
  data() {
    return {
 
     
    };
  },
  methods: {
    onClick() {
      console.log(this.thing.name);
      
      this.$parent.removeThing(this.thing);
    },
    getThingID(){
      return this.thing.path.replaceAll("/","");
    }
  },
};
</script>