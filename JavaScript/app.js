const express = require('express'); // 모듈 추출
const fs = require('fs');

const app = express(); // 서버 생성

app.get('/image', (request, response) => { 
    fs.readFile('image.jpg', (error, data) => {
        // 이미지 파일 제공
        response.type('image/jpg');
        response.send(data);
    });
});

app.get('/audio', (request, response) => {
    fs.readFile('audio.mp3', (error, data) => {
        // 음악 파일 제공
        response.type('audio/mpeg');
        response.send(data);
    });
});

app.listen(52273, () => { // 서버 실행
    console.log('Server running at http://127.0.0.1:52273');
});