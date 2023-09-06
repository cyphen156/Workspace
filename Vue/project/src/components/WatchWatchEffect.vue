<template>
    <p>{{ count_0 }}</p>
    <button @click="count_0++">Options API 카운트 증가</button>
    <p>{{ count_1 }}</p>
    <button @click="count_1++">comoposition API 1st 카운트 증가</button>
    <p>{{ count_2 }}</p>
    <button @click="count_2++">composition API 2nd 카운트 증가</button>
    <p>{{ state }}</p>
    <button @click="onStop()">watchEffect 중지</button>
</template>

<script>
import { ref, watch, watchEffect } from 'vue';

export default {
    //Options API
    data() {
        return {
            count_0: 0,
        }
    },
    watch: {
        // use fast arrow (not recommended)
        // count_0: (cur, prev) => {
        //     console.log('options API watch : ' + prev + '==>' + cur);
        // }, 

        // use function (ES6 recommended) 
        // watch나 watchEffect에서 arrow function을 사용하면 this의 컨텍스트가 상실될 수 있습니다. 
        // this가 undefined이거나 전역 객체에 바인딩될 수 있기 때문에 Vue는 이를 권장하지 않습니다.
        count_0: function(cur, prev) {
            console.log('options API watch : ' + prev + '==>' + cur);
        },
    },
    // Composition Api
    setup() {
        const count_1 = ref(0)
        const count_2 = ref(0)
        const state = ref('실행중')

        // 단일 데이터 감지
        watch(count_1, (cur, prev) => {
            console.log('Composition API watch : ' + prev + ' ==> ' + cur);
        }, {
            immediate: true,
        })
        // 다중 데이터 감지
        watch([count_1, count_2], (cur, prev) => {
            console.log('Composition API Multi watch : ' + prev + ' ==> ' + cur);
        })

        const stop = watchEffect(
            () => {
              console.log('Composition API watchEffect Called ' + count_2.value);
            },{
                flush: 'post',
            }
        )

        const onStop = () => {
          state.value = '중지';
          stop();
        }

        return {
            count_1,
            count_2,
            state,
            onStop,
        }
    }
}
</script>