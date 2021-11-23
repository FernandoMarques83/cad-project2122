import { createApp } from 'vue'
import App from './App.vue'
import GeneralData from './components/GeneralData'
import Add from './components/Add'
import Regras from './components/Regras'
import 'bootstrap';
import 'bootstrap/dist/css/bootstrap.min.css'
import '@fortawesome/fontawesome-free/js/fontawesome'
import '@fortawesome/fontawesome-free/js/solid'
import '@fortawesome/fontawesome-free/js/regular'

/* Configurar router para navegar entre as páginas da aplicação */
/* vue-router / :HomeComponent  /rules:RulesComponent  /settings :SettingsComponents */

import { createRouter, createWebHashHistory } from 'vue-router'

const router = createRouter({
    history: createWebHashHistory(),
    routes: [
        {
            'path':'/',
            'component': GeneralData
        },
        {
            'path':'/Add',
            'component': Add
        },
        {
            'path':'/Regras',
            'component': Regras
        }
    ]
})

createApp(App).use(router).mount('#app')  /* para usar router */

/* createApp(App).mount('#app') */