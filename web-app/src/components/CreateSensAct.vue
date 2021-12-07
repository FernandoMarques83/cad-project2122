<template>
  <div>
    <button
      class="btn btn-white"
      type="button"
      data-bs-toggle="modal"
      :data-bs-target="'#Modal2'+title"
    >
      <i class="fas fa-folder-plus fa-2x" style="color: #008000"></i>
      <!-- Modal -->
      <div
        class="modal fade"
        :id="'Modal2'+title"
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
              O seu item será adicionado na base de dados! Pertende continuar?
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
        v-model="icone"
      />
    </div>

    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default">Nome</span>
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="nome"
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
        v-model="not"
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
        v-model="caminho"
      />
    </div>

    <div class="input-group mb-3">
      <span class="input-group-text" id="inputGroup-sizing-default">Tipo</span>
      <input
        type="text"
        class="form-control"
        aria-label="Sizing example input"
        aria-describedby="inputGroup-sizing-default"
        v-model="tipo"
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
        v-model="vari"
      />
    </div>
  </div>
</template>


<script>
import { getDatabase, ref, set, onValue } from "firebase/database/";

export default {
  name: "CreaeteSensAct",
  props: ["title"],
  components: {},
  data() {
    return {
      icon: "",
      nome: "",
      not: "",
      caminho: "",
      tipo: "",
      vari: "",
      ind : 0
    };
  },

  methods: {
    onClick() {
     

      var newItem = {
        icon: this.icone,
        name: this.nome,
        notPath: this.not,
        path: this.caminho,
        type: this.tipo,
        vat: this.vari,
      };
      console.log("Item adicionado");
      console.log(this.icone);
      console.log(this.caminho);
      console.log(this.nome);
      console.log(this.not);
      console.log(this.tipo);
      console.log(this.vari);
      set(ref(getDatabase(), this.title + "/" + this.ind), newItem);
    },
  },
  mounted(){
     onValue(ref(getDatabase(), this.title), (snapshot) => {
        if (snapshot.exists()) {
          console.log(snapshot.val());
        }
        this.things = snapshot.val();
        this.ind = this.things.length;
        
      });

  }
};
</script>