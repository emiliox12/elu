const fs = require('fs');
const path = require('path');
index = 0;
while (index <= 10) {
    var formattedNumber = ("0" + index).slice(-2);
    fs.mkdir(path.join(__dirname, `ex${formattedNumber}`), (err) => {
        if (err) {
            return console.error(err);
        }
        console.log('Directory created successfully!');
    });
  index++
}