<template>
  <div>
    <button
      class="btn btn-white"
      type="button"
      data-bs-toggle="modal"
      :data-bs-target="'#Modal2' + title"
    >
      <i class="fas fa-folder-plus fa-2x" style="color: #008000"></i>
      <!-- Modal -->
      <div
        class="modal fade"
        :id="'Modal2' + title"
        tabindex="-1"
        aria-labelledby="ModalLabel"
        aria-hidden="true"
      >
        <div class="modal-dialog">
          <div class="modal-content">
            <div class="modal-header">
              <h5 class="modal-title text-success" id="ModalLabel">
                <strong>Messagem</strong>
              </h5>
              <button
                type="button"
                class="btn-close"
                data-bs-dismiss="modal"
                aria-label="Close"
              ></button>
            </div>
            <div class="modal-body">
              O seu item será adicionado na base de dados! Pretende continuar?
            </div>
            <div class="modal-footer">
              <button
                type="button"
                class="btn btn-secondary"
                data-bs-dismiss="modal"
              >
                Cancel
              </button>
              <button
                type="button"
                class="btn btn-primary"
                data-bs-dismiss="modal"
                @click="onClick()"
              >
                Ok
              </button>
            </div>
          </div>
        </div>
      </div>
    </button>
    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default">Icone</span>
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="thing.icon"
      />
    </div>

    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default">Nome</span>
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="thing.name"
      />
    </div>

    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default"
        >Notificação</span
      >
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="thing.notPath"
      />
    </div>

    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default"
        >Caminho</span
      >
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="thing.path"
      />
    </div>

    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default">Tipo</span>
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="thing.type"
      />
    </div>

    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default"
        >Variável</span
      >
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="thing.var"
      />
    </div>
  </div>
</template>


<script>
import { getDatabase, set, ref, onValue } from "firebase/database/";

export default {
  name: "CreateSensAct",
  props: ["title"],
  components: {},
  data() {
    return {
      things: [],
      thing: {
       icon: "",
        name: "",
        notPath: "",
        path: "",
        type: "",
        var: "",
      },
    };
  },

  methods: {
    onClick() {
      console.log("Item adicionado");

      this.things.push(this.thing);
      set(ref(getDatabase(), this.title), this.things);

      this.thing = {
        icon: "",
        name: "",
        notPath: "",
        path: "",
        type: "",
        var: "",
      };
    },
  },
  mounted() {
    onValue(ref(getDatabase(), this.title), (snapshot) => {
      if (snapshot.exists()) {
        this.things = snapshot.val();
      } else {
        this.things = [];
      }
    });
  },
};
</script>