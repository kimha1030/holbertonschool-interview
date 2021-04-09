#!/usr/bin/node

const request = require('request');
const idFilm = process.argv.slice(2, 3);
const urlFilms = `https://swapi-api.hbtn.io/api/films/${idFilm}`;
const options = {
  url: urlFilms,
  method: 'GET'
};

request(options, async function (err, res, body) {
  if (err) {
    return console.log(err);
  }
  const results = JSON.parse(body).characters;
  for (const i in results) {
    await new Promise((resolve, reject) => {
      request(results[i], (err, res, body) => {
        if (err) {
          return console.log(err);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
