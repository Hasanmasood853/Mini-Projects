const hrHand = document.getElementById('hour');
const minHand = document.getElementById('minute');
const secHand = document.getElementById('second');


setInterval(() => {
    const now = new Date();
    const hr = now.getHours();
    const min = now.getMinutes();
    const sec = now.getSeconds();

    secHand.style.transform = `rotate(${sec * 6}deg)`;
    minHand.style.transform = `rotate(${min * 6}deg)`;
    hrHand.style.transform = `rotate(${(hr % 12) * 30 + min / 2}deg)`;
})