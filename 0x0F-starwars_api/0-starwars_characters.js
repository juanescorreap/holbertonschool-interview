#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const item of characters) {
      const response1 = await new Promise((resolve, reject) => {
        request(item, (error, response1, body1) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(body1).name);
          }
        });
      });
      console.log(response1);
    }
  }
});
