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
import { initializeApp } from "firebase/app"

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
const firebaseConfig = {
    apiKey: "AIzaSyBVp7AbG9vujk7RIu-q9fgIuSYkXCAdXHI",
    authDomain: "projeto-dam-4bcc6.firebaseapp.com",
    databaseURL: "https://projeto-dam-4bcc6-default-rtdb.europe-west1.firebasedatabase.app",
    projectId: "projeto-dam-4bcc6",
    storageBucket: "projeto-dam-4bcc6.appspot.com",
    messagingSenderId: "692947282017",
    appId: "1:692947282017:web:5f4e0602833f9858c1a220"
  };

  initializeApp(firebaseConfig);


/* createApp(App).mount('#app') */

// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
//const firebaseConfig = {
//apiKey: "AIzaSyBqart3jUyDqTZtOkJ1nyfASC1lDKrEOrU",
//authDomain: "cad2122-2202576.firebaseapp.com",
//databaseURL: "https://cad2122-2202576-default-rtdb.europe-west1.firebasedatabase.app",
//projectId: "cad2122-2202576",
//storageBucket: "cad2122-2202576.appspot.com",
//messagingSenderId: "243805390102",
//appId: "1:243805390102:web:6fa9ccc014a8b74b923c37"
//};

// Initialize Firebase
initializeApp(firebaseConfig);