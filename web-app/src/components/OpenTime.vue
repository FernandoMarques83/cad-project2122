<template>
  <div>
    <div class="d-flex">
      <i :class="[icon]"> </i>
      <i class="pe-1"></i>
      <strong> {{ title }}</strong>
      <div class="ms-auto">
        {{ info }}
        {{unit}}
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  name: "OpenTime",
  props: ["title", "icon", "openKey", "unit"],

  data() {
    return {
      info: "",
    };
  },
  methods: {
    getValue(response) {
      const keys = this.openKey.split(".");
      const unix = response[keys[0]][keys[1]];

      var date;
      date = new Date(unix*1000);
      var time = date.getHours() + ":" + date.getMinutes();

      return time;
    },
  },
  mounted() {
    axios
      .get(
        "http://api.openweathermap.org/data/2.5/weather?units=metric&q=leiria&appid=c4f0bb5761f8ca78a024fbbee994cd0e&appid=c4f0bb5761f8ca78a024fbbee994cd0e"
      )
      .then((response) => (this.info = this.getValue(response.data)));
  },
};
</script>
