const dino = document.getElementById("dino");
const obstacle = document.getElementById("obstacle");
const scoreDisplay = document.getElementById("score");
const restartBtn = document.getElementById("restart");

let isJumping = false;
let score = 0;
let gameInterval;
let obstacleMoveInterval;

document.addEventListener("keydown", (e) => {
    if (e.code === "Space" || e.code === "ArrowUp") {
        jump();
    }
});

function jump() {
    if (isJumping) return;
    isJumping = true;
    dino.classList.add("jump");
    setTimeout(() => {
        dino.classList.remove("jump");
        isJumping = false;
    }, 500);
}

function startObstacle() {
    let pos = window.innerWidth;
    obstacle.style.left = "-30px";

    obstacleMoveInterval = setInterval(() => {
        pos -= 10;
        obstacle.style.left = `${pos}px`;

        let dinoRect = dino.getBoundingClientRect();
        let obstacleRect = obstacle.getBoundingClientRect();

        if (
            dinoRect.left < obstacleRect.right &&
            dinoRect.right > obstacleRect.left &&
            dinoRect.top < obstacleRect.bottom &&
            dinoRect.bottom > obstacleRect.top
        ) {
            endGame();
        }

        if (pos < -30) {
            pos = window.innerWidth;
            score += 1;
            scoreDisplay.textContent = "Score: " + score;
        }
    }, 20);
}

function spawnCloud() {
    const cloud = document.createElement("img");
    cloud.src = "assets/cloud.png";
    cloud.alt = "Cloud";
    cloud.classList.add("cloud");
    cloud.style.top = `${Math.random() * 60}px`;

    const cloudContainer = document.getElementById("cloud-container");
    cloudContainer.appendChild(cloud);

    setTimeout(() => {
        cloud.remove();
    }, 20000);
}

setInterval(spawnCloud, 5000);

function endGame() {
    clearInterval(obstacleMoveInterval);
    clearInterval(gameInterval);
    restartBtn.style.display = "block";
    obstacle.style.display = "none";
}

function restartGame() {
    score = 0;
    scoreDisplay.textContent = "Score: 0";
    obstacle.style.display = "block";
    restartBtn.style.display = "none";
    startGame();
}

function startGame() {
    startObstacle();
    gameInterval = setInterval(() => {
        // Score updated during obstacle reset
    }, 100);
}

startGame();
