<template>
  <div>
    <div class="d-flex">
      <i :class="[icon]"> </i>
      <i class="pe-1"></i>
      <strong> {{title}}</strong>
    </div>
  </div>
</template>

<script>
/*import {getDatabase, ref, onValue} from 'firebase/database'*/

export default {
  name: "OpenItem",
  props: ["title", "icon", "textColor"],

  
};
</script>
