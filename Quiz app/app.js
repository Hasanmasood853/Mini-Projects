const questions = [
    {
        question: "What is the capital city of Australia?",
        answers: [
            { text: "Sydney", correct: false },
            { text: "Melbourne", correct: false },
            { text: "Brisbane", correct: false },
            { text: "Canberra", correct: true }
        ]
    },
    {
        question: "Which planet is known as the Red Planet?",
        answers: [
            { text: "Earth", correct: false },
            { text: "Venus", correct: false },
            { text: "Mars", correct: true },
            { text: "Jupiter", correct: false }
        ]
    },
    {
        question: "Who wrote the famous play 'Romeo and Juliet'?",
        answers: [
            { text: "William Shakespeare", correct: true },
            { text: "Charles Dickens", correct: false },
            { text: "Leo Tolstoy", correct: false },
            { text: "Mark Twain", correct: false }
        ]
    },
    {
        question: "Which element has the chemical symbol 'O'?",
        answers: [
            { text: "Oxygen", correct: true },
            { text: "Gold", correct: false },
            { text: "Osmium", correct: false },
            { text: "Oxide", correct: false }
        ]
    },
    {
        question: "In which year did the Titanic sink?",
        answers: [
            { text: "1912", correct: true },
            { text: "1905", correct: false },
            { text: "1918", correct: false },
            { text: "1920", correct: false }
        ]
    }
];

const question = document.querySelector(".question h2");
const answerBtn = document.querySelector(".answer-btn");
const nextBtn = document.getElementById("next-btn");
let currQuesIdx = 0;
let score = 0;
function startQuiz() {
    currQuesIdx = 0;
    score = 0;
    nextBtn.innerHTML = "Next";
    showQuestion();
}

function showQuestion() {
    reset();
    let currQues = questions[currQuesIdx];
    let quesNo = currQuesIdx + 1;
    question.innerHTML = quesNo + ". " + currQues.question;
    currQues.answers.forEach(answer => {
        const button = document.createElement("button");
        button.innerHTML = answer.text;
        button.classList.add("btn");
        answerBtn.appendChild(button);
        if (answer.correct) {
            button.dataset.correct = answer.correct;
        }
        button.addEventListener("click", selectAns)
    })
}
function reset() {
    nextBtn.style.display = "none";
    while (answerBtn.firstChild) {
        answerBtn.removeChild(answerBtn.firstChild);
    }
}
function showScore() {
    reset();
    question.innerHTML = `You Scored ${score} out of ${questions.length}!`;
    nextBtn.innerHTML = "Play Again";
    nextBtn.style.display = "block";
}
function selectAns(e) {
    const selectedBtn = e.target;
    const isCorrect = selectedBtn.dataset.correct === "true";
    if (isCorrect) {
        selectedBtn.classList.add("correct");
        score++;
    } else {
        selectedBtn.classList.add("incorrect")
    }
    Array.from(answerBtn.children).forEach(button => {
        if (button.dataset.correct === "true") {
            button.classList.add("correct");
        }
        button.disabled = true;
    })
    nextBtn.style.display = "block";
}
nextBtn.addEventListener("click", () => {
    if (nextBtn.innerHTML === "Play Again") {
        startQuiz();
        return;
    }

    currQuesIdx++;
    if (currQuesIdx < questions.length) {
        showQuestion();
    } else {
        showScore();
    }
});

startQuiz()