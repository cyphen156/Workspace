const express = require('express');
const morgan = require('morgan');

const app = express(); // 서버 생성
app.use(express.static('public'));
app.use(morgan('combined'));
app.use(express.urlencoded({ extended: false }));

app.get('/', (requset, response) => {

    let output = '';
    output += '<form method = "post">';
    output += '<input type = "text" name = "a" />';
    output += '<input type = "text" name = "b" />';
    output += '<input type = "submit" />';
    output += '</form>';

    response.send(output);
});

app.post('/', (request, response) => {
    response.send(request.body);
});

app.listen(52273, () => {
    console.log('Server running at http://127.0.0.1:52273');
});