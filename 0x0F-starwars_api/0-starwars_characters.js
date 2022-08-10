#!/usr/bin/node

const { resolve } = require('path');
const request = require('request');
const url = 'https://swapi.dev/api/films/'
const movieId = process.argv[2];

request(url + movieId, (error, response, body) => {
    if (error) {
        throw error;
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
            console.log(response1)
        }
    }
});