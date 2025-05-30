let boxes = document.querySelectorAll(".box");
let resetBtn = document.querySelector("#resetBtn");
let msgContainer = document.querySelector(".msgContainer");
let msg = document.querySelector(".msg");
let newBtn = document.querySelector("#newBtn");

let turnO = true; // player X player O
let count = 0;

let winPatterns = [
    [0, 1, 2], [0, 3, 6],
    [0, 4, 8], [1, 4, 7],
    [2, 5, 8], [2, 4, 6],
    [3, 4, 5], [6, 7, 8],
];

boxes.forEach((box) => {
    box.addEventListener("click", () => {
        if (turnO) {
            box.innerText = "O";
            turnO = false;
        } else {
            box.innerText = "X";
            turnO = true;
        }
        box.disabled = true;
        count++;

        let isWInner = checkWinner();
        if (count === 9 && !isWInner) {
            gameDraw();
        }
    });
});

const gameDraw = () => {
    msg.innerText = "Game is Drawn";
    disabledBtn();
    msgContainer.classList.remove("hide");
}
const resetGame = () => {
    turnO = true;
    enabledBtn();
    msgContainer.classList.add("hide");
};
const disabledBtn = () => {
    for (let box of boxes) {
        box.disabled = true;
    }
};
const enabledBtn = () => {
    for (let box of boxes) {
        box.disabled = false;
        box.innerText = "";
    }
};

const showWinner = (winner) => {
    msg.innerText = `Congratulation the winner is ${winner}`;
    msgContainer.classList.remove("hide");
    msgContainer.style.height = "100vh";
    disabledBtn();
};


const checkWinner = () => {
    for (let pattern of winPatterns) {
        let pos1Val = boxes[pattern[0]].innerText;
        let pos2Val = boxes[pattern[1]].innerText;
        let pos3Val = boxes[pattern[2]].innerText;
        if (pos1Val != "", pos2Val != "", pos3Val != "") {
            if (pos1Val === pos2Val && pos2Val === pos3Val) {
                console.log("winner");
                showWinner(pos1Val);
                return true;
            }
        }
    }
};
resetBtn.addEventListener("click", resetGame);
newBtn.addEventListener("click", resetGame);