let userScore = 0;
let compScore = 0;

const choices = document.querySelectorAll(".choice");
const result = document.querySelector("#msg");
const msgContainer = document.querySelector(".msg-container")
const userScorePara = document.querySelector("#userscore");
const compScorePara = document.querySelector("#compscore");
const drawGame = () => {
    result.innerHTML = "Game was Drawn";
    msgContainer.style.backgroundColor = "black";
};
const showWinner = (userWin, userChoice, compChoice) => {
    if (userWin) {
        userScore++;
        userScorePara.innerText = userScore;
        result.innerHTML = `Congrats! You Win your ${userChoice} beats  ${compChoice}`;
        msgContainer.style.backgroundColor = "green";
    } else {
        compScore++;
        compScorePara.innerText = compScore;
        result.innerHTML = `Sorry! you are loser ${compChoice} beats your ${userChoice}`;
        msgContainer.style.backgroundColor = "red";
    }
}
const genCompChoice = () => {
    const options = ["rock", "paper", "scissors"];
    const randIdx = Math.floor(Math.random() * 3);
    return options[randIdx];
}

const playGame = (userChoice) => {
    // Generate computer choice
    const compChoice = genCompChoice();
    if (userChoice === compChoice) {
        drawGame();
    } else {
        let userWin = true;
        if (userChoice === "rock") {
            userWin = compChoice === "paper" ? false : true;
        } else if (userChoice === "paper") {
            userWin = compChoice === "scissors" ? false : true;
        } else (userChoice === "scissors")
        {
            userWin = compChoice === "rock" ? false : true;
        }
        showWinner(userWin, userChoice, compChoice);
    }
    finalResult();
}

choices.forEach((choice) => {
    choice.addEventListener("click", () => {
        const userChoice = choice.getAttribute("id");
        playGame(userChoice);
    });
});
const finalResult = () => {
    if (userScore === 5) {
        setTimeout(() => {
            alert(`You won! Your score is ${userScore}, Computer score is ${compScore}`);
            resetScores();
        }, 100);
    } else if (compScore === 5) {
        setTimeout(() => {
            alert(`You lost! Your score is ${userScore}, Computer score is ${compScore}`);
            resetScores();
        }, 100);
    }
};

const resetScores = () => {
    userScore = 0;
    compScore = 0;
    compScorePara.innerText = 0;
    userScorePara.innerText = 0;
}