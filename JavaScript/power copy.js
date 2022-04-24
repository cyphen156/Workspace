let array = [273, 52, 103, 57, 271];

let min = Number.MAX_VALUE;
let max = Number.MIN_VALUE;

min = array[0]; // 273

for (let i in array) {
    if (min > array[i])
    min = array[i];
    if (max < array[i])
    max = array[i];
}

console.log(`가장 작은 수: ${min}`);
console.log(`가장 큰 수: ${max}`);