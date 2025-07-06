const passBox = document.querySelector("#password");
const genBtn = document.querySelector(".generate button");

const upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const lowerCase = "abcdefghijklmnopqrstuvwxyz";
const number = "0123456789";
const symbols = "!#$%&()*+,-./:;?@[\\]_\{|}";
const allChars = upperCase + lowerCase + number + symbols;

const passLength = 12;
function genPass() {
    let password = "";
    password += upperCase[Math.floor(Math.random() * upperCase.length)];
    password += lowerCase[Math.floor(Math.random() * lowerCase.length)];
    password += number[Math.floor(Math.random() * number.length)];
    password += symbols[Math.floor(Math.random() * symbols.length)];

    while (passLength > password.length) {
        password += allChars[Math.floor(Math.random() * allChars.length)];
    }
    passBox.value = password;
}
function copy() {
    passBox.select();
    document.execCommand("copy");
}