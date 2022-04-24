let arr = new Array();
arr = [
    {
        c: [27, 32, 56, 77], 
    }, {
        d: [33, 22, 56]
    }
];

function calculater() {
    for (let i = 0; i < arr.length; i++){
        if (Object.keys(arr[i]) == 'c') {
            power(arr[i]);
        }
    }
};

function power (arr) {
    for (let i in arr){
        console.log(arr[i]);
        
    }
}

function multiply (params) {

}
calculater();
