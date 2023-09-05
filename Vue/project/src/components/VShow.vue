<template>
    <p> {{ counter }}</p>
    <p v-show="counter <= 5">5보다 작습니다.</p>
    <p v-show="counter > 5 && counter <= 10">5초과 10이하입니다.</p>
    <p v-show="counter > 10">10을 초과했습니다.</p>
    <button @click="counter++"></button>
</template>

<script setup>
import { ref } from 'vue';

const counter = ref(0);

</script>