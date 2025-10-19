

const myObj = {
    "name": "jackquees",
    "age": 21,
    "email": "jackques@gmail.com",
    "hobbies": [
        "fishing",
        "playing game",
        "cooking",
        "sleeping",
        "singing"
    ]
}
const myarr = `[
    {
        "name": "jack",
        "age": 21
    },
    {
        "name": "jack",
        "age": 21
    },
    {
        "name": "jack",
        "age": 21
    }
]`

var myJson = JSON.stringify(myObj);
localStorage.setItem("JsonStorage", myJson);

console.log(myJson);

const parse = JSON.parse(myarr);
console.log(parse)

fetch("person.json")
    .then(response => response.json())
    .then(value => console.log(value));