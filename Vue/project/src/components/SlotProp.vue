<template>
    <ul style="list-style-type: none;">
      <li v-for="(item, i) in items" :key="i">
        <slot :item="item"></slot>
      </li>
    </ul>
  </template>
  
  <script>
  export default {
    data() {
      return {
        items: [1, 2, 3, 4, 5],
      };
    },
  };
  </script>
  