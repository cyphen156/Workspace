<template>
    <div>
        <p>counter + counter2 : {{ counter + counter2 }}</p>
        <button @click="counter++">클릭하면 counter의 숫자가 올라갑니다.</button>
        <button @click="counter2++">클릭하면 counter2의 숫자가 올라갑니다.</button>
    </div>
    <div>
        <p>counter3 + counter4 : {{ counter3 + counter4 }}</p>
        <button @click="onClick3">클릭하면 counter3의 숫자가 올라갑니다.</button>
        <button @click="onClick4">클릭하면 counter4의 숫자가 올라갑니다.</button>    
    </div>
</template>

<script>
import { ref } from 'vue';

export default {
    data() {
        return {
            counter2: 0,
        };
    },
    setup() {
        let counter = ref(0);
        let counter3 = ref(0);
        let counter4 = ref(0);

        const onClick3 = () => {
            counter3.value++;
        };

        const onClick4 = () => {
            counter4.value++;
        };

        return {
            counter,
            counter3,
            counter4,
            onClick3,
            onClick4,
        };
    },
}
</script>