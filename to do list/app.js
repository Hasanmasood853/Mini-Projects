const inputBox = document.getElementById("input-box");
const list = document.getElementById("list-container");
function addTask() {
    if (inputBox.value === "") {
        alert("Please write some task in input box")
    } else {
        let li = document.createElement("li");
        li.innerHTML = inputBox.value;
        list.appendChild(li);

        let span = document.createElement("span");
        span.innerHTML = "\u00d7"
        li.appendChild(span);

    }
    inputBox.value = "";
    saveData();
}
inputBox.addEventListener("keypress", function (event) {
    if (event.key === "Enter") {
        addTask();
    }
});
list.addEventListener("click", function (e) {
    if (e.target.tagName === "LI") {
        e.target.classList.toggle("checked")
        saveData();
    } else if (e.target.tagName === "SPAN") {
        e.target.parentElement.remove();
        saveData();
    }
}, false)

function saveData() {
    localStorage.setItem("data", list.innerHTML);
}
function showData() {
    list.innerHTML = localStorage.getItem("data");
}
showData();