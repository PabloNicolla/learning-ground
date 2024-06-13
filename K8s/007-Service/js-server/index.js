const express = require('express');
const app = express();
const port = 3000;

let randomInt = Math.floor(Math.random() * (100 - 1) + 1);

app.get('/', (req, res) => {
  const ip = req.headers['x-forwarded-for'] || req.connection.remoteAddress;
  res.send(`Hello ${randomInt}`);
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}/`);
});
