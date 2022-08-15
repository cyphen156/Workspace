const express = require('express');
const morgan = require('morgan');

const app = express();

app.use(express.static('public'));
app.use(morgan('combined'));
app.use(express.urlencoded({ extended: false }));

app.listen(8982, () => {
    console.log('Server running at http://127.0.0.1:8982');
})

app.get('/', (request, response) => {
    // response.send(request.body);
    console.log(request.query);

    var query = request.query;
    var id = query.id;
    var name = query.name;
    var quantity = query.quantity;
    var date = query.date;

    const array = [id, name, quantity, date];

    response.send(array);

});