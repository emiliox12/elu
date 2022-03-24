const express = require('express')
const path = require('path')
const basicAuth = require('express-basic-auth')
const songs = require('./data.json')
const app = express()
var router = express.Router()

router.use(basicAuth({
    users: { 'admin': 'admin' }
}));

app.get('/', function (req, res) {
  var song = songs[Math.floor(Math.random()*songs.length)];
  res.send(song)
})

app.get('/birth_date', function (req, res) {
  res.send(new Date('December 12, 1915'))
})

app.get('/birth_city', function (req, res) {
  res.send('Hoboken, New Jersey, U.S.')
})

app.get('/wives', function (req, res) {
  res.send('Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx')
})

app.get('/picture', function (req, res) {
  var options = {
    root: path.join(__dirname),
    dotfiles: 'deny',
    headers: {
      'x-timestamp': Date.now(),
      'x-sent': true
    }
  }
  var fileName = "frank.jpg";
  res.sendFile(fileName, options)
})

app.get('/public', function (req, res) {
  console.log("Everybody can see this page")
})

router.get('/protected', function (req, res) {
  console.log("Welcome, authenticated client")
})

app.use(router);
app.listen(3000)

