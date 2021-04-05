#!/usr/bin/node

const idFilm = process.argv.slice(2, 3);
const urlFilms = `https://swapi-api.hbtn.io/api/films/${idFilm}`;
const request = require("request");
const options = {
  url: urlFilms,
  method: "GET",
};

request(options, (err, res, body) => {
  if (err) {
    return console.log(err);
  }
  const results = JSON.parse(body).characters;
  for (const i in results) {
    request(results[i], function (err, res, body) {
      if (err) {
        return console.log(err);
      }
      console.log(JSON.parse(body).name);
    });
  }
});
