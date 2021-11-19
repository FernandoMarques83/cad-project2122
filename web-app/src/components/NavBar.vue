<template>
<nav class="navbar navbar-expand-sm navbar-dark bg-dark">
    <div class="container-fluid">
        <a class="navbar-brand mb-0 h1" href="#">Controlo e Monitorização Inteligente na Agricultura</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarToggleContent"
            aria-controls="navbarToggleContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse justify-content-end" id="navbarToggleContent">
            <ul class="navbar-nav">
                <li class="nav-item active">
                    <a class="nav-link" href="index.html">Monitorização</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="rules.html">Regras</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="add.html">Adicionar</a>
                </li>
            </ul>
        </div>
    </div>
</nav>
</template>

<script>
export default {
  name: 'NavBar',
}
</script>