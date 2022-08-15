const request = require('request');
const cheerio = require('cheerio');

const url = 'https://www.uhs.ac.kr/uhs/399/subview.do';
request(url, (error, response, body) => {
    const $ = cheerio.load(body);

    $('#menu399_obj5038').each((index, element) => {
        let name = $(element).find('li').text().trim();
        console.log(name);
        console.log('--------------');
    });

    $('.desc').each((index, element) => {
        let name = $(element).find('strong').text().trim();
        console.log(name);
        console.log('--------------');
    });
    $('#menu399_obj5038').each((index, element) => {
        let name = $(element).find('.con-desc').text().trim();
        console.log(name);
    });
});