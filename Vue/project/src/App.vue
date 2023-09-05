<template>
  <!-- <img alt="Vue logo" src="./assets/logo.png">
  <HelloWorld msg="Welcome to Your Vue.js App"/>
  <SampleButton></SampleButton>
  <VueBind></VueBind>
  <EventListener></EventListener>
  <VShow></VShow>
  <IfFor></IfFor> -->
  <ComputedFor></ComputedFor>
</template>

<script>
import EventListener from './components/EventListener.vue';
import HelloWorld from './components/HelloWorld.vue';
import IfFor from './components/IfFor.vue';
import VShow from './components/VShow.vue';
import SampleButton from './components/SampleButton.vue';
import VueBind from './components/VueBind.vue';
import ComputedFor from './components/ComputedFor.vue';

export default {
  name: 'App',
  components: {
    // HelloWorld,
    // SampleButton,
    // VueBind,
    // EventListener,
    // VShow,
    // IfFor,
    ComputedFor
}
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
