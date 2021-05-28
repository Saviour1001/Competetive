// Reading the file using default
// fs npm package
const fs = require("fs");
csv = fs.readFileSync("MOCK_DATA.csv");

// Convert the data to String and
// split it in an array
var array = csv.toString().split("\r");

let headers = array[0].split(", ");
// console.log(headers);

function csvJSON(csv) {
  csv = csv + " ";
  var lines = csv.split("\n");

  var result = [];

  var headers = lines[0].split(",");

  for (var i = 1; i < lines.length; i++) {
    var obj = {};
    var currentline = lines[i].split(",");

    for (var j = 0; j < headers.length; j++) {
      obj[headers[j]] = currentline[j];
    }

    result.push(obj);
  }

  //return result; //JavaScript object
  return JSON.stringify(result); //JSON
}
// let json = csvJSON(headers);

const json = csvJSON(headers);
const res = json;
for (const key in res) {
  if (obj.hasOwnProperty(key)) {
    console.log(`${key} : ${res[key]}`);
  }
}
