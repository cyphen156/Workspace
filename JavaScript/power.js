let input  = [    [23, 58.2, -45.3, 31], [42, 3.5], [-92, 31, 23.3], [9], [-33,3]];

let result = 1;

calculater = function () {
    for (let i = 0; i < input.length;i++) {
        if (input[i].length ==1 || input[i].length == 2) {
           result = power(input[i]);
        }
        else {
            result = multiply(input[i]);
        }
        console.log(result);
        result = 1;
    }

}

function power(arr) {
    if (arr.length == 1) {
        result = arr[0] * arr[0];
    }
    else {
        result = arr[0] ** arr[1]
    }
    return result;
}


function multiply(arr) {
    for (let j in arr) {
        result *= arr[j];
    }
    return result;
}

calculater();
