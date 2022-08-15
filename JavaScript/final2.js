const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.listen(8981, () =>{
    console.log('서버생성완료');
});

//미들웨어
app.use(bodyParser.urlencoded({
    extended: false
}));


app.get('/', (request, response) => {
    let output = '';
    output += '<form action="/posts" method="post"><br>';
    output += ' <input type="text" name="상품 ID" /><br>';
    output += ' <input type="text" name=상품 이름: /><br>';
    output += ' <input type="number" name="수량" /><br>';
    output += ' <input type="date" name="주문일" /><br>';
    output += ' <input type="submit", value="상품 입력"/>';
    output += '</form>';

    response.send(output);
});

app.post('/posts', (request, response)=> {
    response.send(request.body);
});

const items = [];

app.post(':/posts', (request, response) =>{
    const body = request.body;

    //변수추출
    const id = body.id;
    const name = body.name;
    const count = body.count;
    const date = body.parse(date);
    //데이터 저장
    const data = {
        id: id,
        name: name,
        count: count,
        Date: date
    };
    items.push(data);

    app.get('8981:/gets', (request, response) =>{
        if (items.length == 0)
            console.log('No data...');
        else{
            window.location();
            response.send(items);
        }
    });
});


app.get('/user/:id', (request, response) =>{
    const id = request.params.id;
    //데이터 조회
    const filtered = users.filter((user) => user.id ==id);

    if (filtered.length ==1)
        response.send(filtered[0]);
    else
        response.status(404).send('there is no such data');
});


//data 수정
app.put('/user/:id', (request, response) =>{
    const id = request.params.id;
    let isExist = false;

    //data Edit
    users.forEach((uesr) =>{
        if (user.id == id){
            isExist = true;
            if (request.body.name)
                users[id].name = request.body.name;
            if (request.body.region)
                users[id].region = request.body.region;
                response.send(user);
        }       
    });

    if (!isExist)
        response.status(404).send('there is no such data');
});