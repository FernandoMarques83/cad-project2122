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


const app = createApp(App).use(router)

app.component('toggle', {
    props: ['title'],
    data() {
        return {
            isOn: false
        }
    },
    methods: {
        toggleClick() {
            this.isOn = !this.isOn
        },
        
    },
    computed: {
        changeLight() {
            return {
                'fas': this.isOn,
                'far': !this.isOn
            }
        }
    },
    template: `
    <i class="fa-lightbulb" :class="changeLight"></i>
    <p>{{ title }}</p>
    <i @click="toggleClick" class="fas" :class="{'fa-toggle-on': isOn, 'fa-toggle-off': !isOn}"></i>`
})

app.mount('#app')  /* para usar router */


/* createApp(App).mount('#app') */