const apiKey = "5be7415d44ed2cbe6892363778463e11";
const api = "https://api.openweathermap.org/data/2.5/weather?q=";
const tempValue = document.querySelector(".temp-value");
const tempFahrenheit = document.querySelector(".fahrenheit h1");
const cityName = document.querySelector(".city");
const humidity = document.querySelector(".humidity-value");
const windSpeed = document.querySelector(".wind-value");
const image = document.querySelector(".details img");
const weatherIcons = {
    Clouds: "./images/clouds.png",
    Clear: "./images/clear.png",
    Rain: "./images/rain.png",
    Snow: "./images/snow.png",
    Mist: "./images/mist.png",
    Drizzle: "./images/drizzle.png"

};
const search = document.querySelector(".search input")
const searchBtn = document.querySelector(".search button");
const result = document.querySelector(".result");

searchBtn.addEventListener("click", () => {
    checkWeather(search.value);
});

search.addEventListener("keydown", (e) => {
    if (e.key === "Enter") {
        checkWeather(search.value);
    }
});


const checkWeather = async (city) => {
    const response = await fetch(api + city.toLowerCase() + `&appid=${apiKey}&units=metric`);
    const data = await response.json();
    console.log(data);

    if (data.cod === 200) {
        result.style.display = "block";
        tempValue.innerHTML = Math.round(data.main.temp) + "°C";
        humidity.innerHTML = data.main.humidity + "%";
        windSpeed.innerHTML = data.wind.speed + "km/h";
        cityName.innerHTML = data.name.toUpperCase();
        const tempFahren = Math.round((data.main.temp * 9) / 5 + 32);
        tempFahrenheit.innerHTML = tempFahren + "°F";

        const weatherMain = data.weather[0]?.main;
        image.src = weatherIcons[weatherMain] || "./images/clear.png";
    } else {
        result.style.display = "none";
        alert("City not found!");
    }
};