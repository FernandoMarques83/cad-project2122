<template>
  <div>
    <div class="d-flex">
      <i :class="[icon]"> </i>
      <i class="pe-1"></i>
      <strong> {{ title }}</strong>
      <div class="ms-auto">
        {{ info.covidKey}}
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  name: "CovidItem",
  props: ["title", "icon", "covidKey"],

  data() {
    return {
      info: "" ,
    };
  },
  mounted() {
    axios
  .get(
    "https://covid19-api.vost.pt/Requests/get_last_update"
  )
  .then((response) => (
    this.info = response.data)
    );
  },

};
</script>
