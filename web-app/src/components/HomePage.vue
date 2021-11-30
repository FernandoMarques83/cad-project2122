<template>
    <div class="container">
        <ZoneCard :title="'Garden'" />
        <ZoneCard :title="'Jardim'" />
    </div>
</template>

<script>
import ZoneCard from './ZoneCard.vue'
export default {
    name: "HomePage",
    components: {
        ZoneCard
    }
}
</script>
