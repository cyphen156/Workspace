<template>
    <div>
        <slot>
            default: 0
        </slot>
        <hr/>
        <slot></slot>
        <slot></slot>
        <slot></slot>
        <slot></slot>
        <hr />
        <button 
            id="classId" 
            style="
                align-items: center; 
                color: black;
                width: 100px;
                height: 200px;
                border-radius: 45%;"
            @click="data++"
        >
        </button>
        <br />
        {{ data }}
        <br />
        <slot name="header">
            default: 10
        </slot>
    </div>
</template>

<script setup>
import { ref } from 'vue';

const data = ref(0)
</script>