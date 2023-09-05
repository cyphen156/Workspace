<template>
    <div id="app">
      <button class="purple" @click="incrementCounter">
        {{ counter }}
      </button>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        counter: 0,
      };
    },
    methods: {
      incrementCounter() {
        this.counter++;
      },
    },
  };
  </script>
  
  <style>
  .purple {
    background-color: purple;
    color: white;
  }
  </style>
  