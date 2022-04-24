let input = [
    { c: [23, 58.2, -45.3, 31] },
    { b: [42, 3.5] },
    { c: [-92, 31, 23.3] },
    { a: [9] },
    { b: [-33.3, 3] }
];


let mykeys = Object.keys(input);
function calculator() {
for (let i = 0; i < input.length; i++) {
    if (Object.keys(input[i]) == 'a') {
    console.log((input[i] * input[i]) * 2);
    }
    else if (Object.keys(input[i]) == 'b') {
        for (let i = 0; i <= input[i].length; i++) {
    console.log((input[i][0] ** input[i][1]) * 2);
        }
    }

}
}

calculator();