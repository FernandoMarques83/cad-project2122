<template>
  <div>
    <div class="d-flex">
      <i :class="[icon]"> </i>
      <i class="pe-1"></i>
      <strong> {{ title }}</strong>
      <div class="ms-auto">
       {{info}}
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";


export default {
  name: "OpenItem",
  props: ["title", "icon", "openKey"],
  
  data() {
    return {
      info: "" ,
    };
  },
  mounted() {
    axios
  .get(
    "http://api.openweathermap.org/data/2.5/weather?units=metric&q=leiria&appid=c4f0bb5761f8ca78a024fbbee994cd0e&appid=c4f0bb5761f8ca78a024fbbee994cd0e"
  )
  .then((response) => (
    this.info = console.log(response.data.openKey))
    );
  },
};
</script>
