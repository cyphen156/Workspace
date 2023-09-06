<template>
  <!-- <img alt="Vue logo" src="./assets/logo.png">
  <HelloWorld msg="Welcome to Your Vue.js App"/>
  <SampleButton></SampleButton>
  <VueBind></VueBind>
  <EventListener></EventListener>
  <VShow></VShow>
  <IfFor></IfFor>
  <ComputedFor></ComputedFor>
  <WatchWatchEffect></WatchWatchEffect>
  <SlotExample>
    slot이 5개인가?
  </SlotExample> -->
  <SlotProp>
    <template v-slot="slotProps">
      {{ slotProps.item }}
    </template>  
  </SlotProp>
</template>

<script>
import EventListener from './components/EventListener.vue';
import HelloWorld from './components/HelloWorld.vue';
import IfFor from './components/IfFor.vue';
import VShow from './components/VShow.vue';
import SampleButton from './components/SampleButton.vue';
import VueBind from './components/VueBind.vue';
import ComputedFor from './components/ComputedFor.vue';
import WatchWatchEffect from './components/WatchWatchEffect.vue';
import SlotExample from './components/SlotExample.vue';
import SlotProp from './components/SlotProp.vue';

export default {
  name: 'App',
  components: {
    // HelloWorld,
    // SampleButton,
    // VueBind,
    // EventListener,
    // VShow,
    // IfFor,
    // ComputedFor,
    // WatchWatchEffect,
    // SlotExample,
    SlotProp
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
