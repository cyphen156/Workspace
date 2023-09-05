<template>
    <div>
        <p> {{ counter }}</p>
        <p v-if="counter <= 5">5보다 작습니다.</p>
        <p v-else-if="counter > 5 && counter <= 10">5초과 10이하입니다.</p>
        <p v-else>10을 초과했습니다.</p>
        <button @click="counter++"></button>
    </div>
    <div style="width: 200px">
        <ol>
            <li v-for="item in items" :key="item">{{ item }}</li>
        </ol>
    </div>
</template>

<script setup>
import { ref, reactive } from 'vue';

const counter = ref(0);
const items = reactive(['item1', 'item2', 'item3', 'item4', 'item5'])
</script>