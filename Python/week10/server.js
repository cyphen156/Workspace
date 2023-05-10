//server 
const express = require('express');
const app = express();
const port = 3000;

//api call
const client_id = '_1lxr4EpON5EFHjttfGV';
const client_secret = 'fXGSpjYenD';

app.get("/search/news", (req, res) => {
    let api_url = 'https://openapi.naver.com/v1/search/blog?query=' + encodeURI(req.query.query); // JSON 결과
    //   var api_url = 'https://openapi.naver.com/v1/search/blog.xml?query=' + encodeURI(req.query.query); // XML 결과
       let request = require('request');
       let options = {
           url: api_url,
           headers: {'X-Naver-Client-Id':client_id, 'X-Naver-Client-Secret': client_secret}
        };
       request.get(options, function (error, response, body) {
         if (!error && response.statusCode == 200) {
           res.writeHead(200, {'Content-Type': 'text/json;charset=utf-8'});
           res.end(body);
         } else {
           res.status(response.statusCode).end();
           console.log('error = ' + response.statusCode);
         }
       });
})

app.listen(port, () => {
    console.log(`server Listen at LocalHost: ${port}`);
})