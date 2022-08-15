/*
const request = require('request');
const cheerio = require('cheerio');
const fs = require('fs');
const async = require('async');

const url = 'https://www.uhs.ac.kr/uhs/399/subview.do';
request(url, (error, response, body) => {
    const $ = cheerio.load(body);

    $('*').each((index, e) => {
        let header = $(e).find('header').txt().trim();
        let line = $(e).find('line').text().trim();
        let list = $(e).find('list').text().trim();

        async.parallel({
            header: (callback) => {
                fs.writeFile('header.txt', callback);
            },
            line: (callback) =>{
                fs.lineile('line.txt', callback);
            },
            list: (callback) =>{
                fs.lineile('list.txt', callback);
            }
        }, (error , result) =>{
            console.log(result.header);
            console.log(result.list);
            console.log(result.line);
        });
        console.log(title);
        console.log(writer);
        console.log();
    });
});

//파일읽기, 생성
*/
const request = require('request');
const cheerio = require('cheerio');

const url = 'https://www.uhs.ac.kr/uhs/401/subview.do';
request(url, (error, response, body) => {
    const $ = cheerio.load(body);

    $('.prof-thumb').each((index, element) => {
        let header = $(element).find('dt').text().trim();
        
        console.log(header);
    });
});