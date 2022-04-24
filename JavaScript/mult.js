let arr = new Array();
arr = [ 
    { c: [23, 58.2, -45.3, 31] },
    { b: [42, 3.5] },
    { c: [-92, 31, 23.3] },
    { a: [9] },
    { b: [-33.3, 3] }
];

function calculater() {
    for (let i = 0; i < arr.length; i++){
        let result;
        if (Object.keys(arr[i]) == 'c') {
            result = multiply(arr[i]);
        } else {
            result = power(arr[i]);
        }
    }
};

function power (arr) {
    console.log(arr);
    for (let i in arr){
        console.log(arr[i]);
        console.log(i);
    }
}

function multiply (arr) {
    for (let i in arr){
        console.log(arr[i]);
    }
}

calculater();


function power2(arr) {
    let output;
    if (arr.length == 1) {
        putout = arr[0] * arr[0];
    }
    else {
        output = arr[0] ** arr[1]
    }
    return output;
}


function multiply2(arr) {
    let output = 1;
    for (let j in arr) {
        output *= arr[j];
    }
    return output;
}