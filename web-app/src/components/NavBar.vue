<template>
  <nav class="navbar navbar-expand-sm navbar-dark bg-dark">
    <div class="container-fluid">
      <router-link class="navbar-brand mb-0 h1" to="/"
        >Controlo e Monitorização Inteligente na Agricultura</router-link
      >
      <button
        class="navbar-toggler"
        type="button"
        data-toggle="collapse"
        data-target="#navbarToggleContent"
        aria-controls="navbarToggleContent"
        aria-expanded="false"
        aria-label="Toggle navigation"
      >
        <span class="navbar-toggler-icon"></span>
      </button>
      <div
        class="collapse navbar-collapse justify-content-end"
        id="navbarToggleContent"
      >
        <ul class="navbar-nav">
          <li class="nav-item active">
            <router-link class="nav-link" :class="isActive('/')" to="/"
              >Monitorização</router-link
            >
          </li>
          <li class="nav-item">
            <router-link
              class="nav-link" :class="isActive('/Regras')"
              to="/Regras"
              >Regras</router-link
            >
          </li>
          <li class="nav-item">
            <router-link class="nav-link" :class="isActive('/Add')" to="/Add"
              >Adicionar</router-link
            >
          </li>
        </ul>
      </div>
    </div>
  </nav>
</template>

<script>
export default {
  name: "NavBar",
  methods: {
    isActive: function (path) {
      if (this.$route.path == path) {
        return ["active"];
      }
      return [];
    }
  }
}
;
</script>