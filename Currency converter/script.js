const baseUrl = "https://data.fixer.io/api/latest?access_key=3c94e84bd70beab67c6c6b75051be3b8";
const dropDown = document.querySelectorAll(".dropdown select")
const btn = document.querySelector(".btn");
const fromCurr = document.querySelector(".from select");
const toCurr = document.querySelector(".to select");
const msg = document.querySelector(".msg");

for (let select of dropDown) {
    for (currCode in countryList) {
        let newOption = document.createElement("option");
        newOption.innerText = currCode;
        newOption.value = currCode;
        if (select.name === "from" && currCode === "USD") {
            newOption.selected = "Selected";
        } else if (select.name === "to" && currCode === "PKR") {
            newOption.selected = "Selected";
        }
        select.append(newOption);
    }
    select.addEventListener("change", (evt) => {
        updateFlag(evt.target);
    })
}

const updateFlag = (element) => {
    let currCode = element.value;
    let countryCode = countryList[currCode];
    let newSrc = `https://flagsapi.com/${countryCode}/flat/64.png`;
    let img = element.parentElement.querySelector("img");
    img.src = newSrc;
}

btn.addEventListener("click", async (evt) => {
    evt.preventDefault();
    let amount = document.querySelector(".input");
    let amtVal = amount.value;
    if (amtVal === "" || amtVal < 0) {
        amount.value = "1";
        amtVal = 1;
    }

    let response = await fetch(baseUrl);
    let Data = await response.json();

    const from = fromCurr.value.toUpperCase();
    const to = toCurr.value.toUpperCase();

    const fromRate = Data.rates[from];
    const toRate = Data.rates[to];

    if (!fromRate || !toRate) {
        console.log("Invalid currency code or missing data.");
        return;
    }

    const convertedAmount = ((toRate / fromRate) * amtVal).toFixed(2);
    msg.innerText = `${amtVal} ${from} = ${convertedAmount} ${to}`;

})