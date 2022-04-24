let input = [[23, 58.2, -45.3, 31], [42, 3.5], [92, 31, 23.3], [9], [33.3]];

let result; 

function calculator() {
    for (let i = 0; i < input.length; i++) {
        if (input[i].length == 1 || input[i].length == 2) {
            power();
            console.log(result);
        }
        else if (input[i].length >= 3) {
            multiply();
            console.log(result);
        }
    }
}

function power() {
    if (input[i].length == 1) {
        result = input[i][0] * input[i][0];
        return result;
    }
    else if (input[i].length == 2) {
        result = input[i][0] ** input[i][1]
        return result;
    }
}

let output = 1;

function multiply() {
    if (input[i].length >= 3) {
        for (let j = 0; j < input[i].length; j++) {
            output *= input[i][j]
            result = output
        }
        return result;
    }
}

calculator();