// Game constants
const CANVAS_WIDTH = 600;
const CANVAS_HEIGHT = 400;
const PADDLE_WIDTH = 10;
const PADDLE_HEIGHT = 100;
const BALL_SIZE = 10;
const PADDLE_SPEED = 7;
const BALL_SPEED = 5;

const canvas = document.getElementById("pong-canvas");
const ctx = canvas.getContext("2d");

const player = {
  x: 0,
  y: CANVAS_HEIGHT / 2 - PADDLE_HEIGHT / 2,
  width: PADDLE_WIDTH,
  height: PADDLE_HEIGHT,
  score: 0
};

const ai = {
  x: CANVAS_WIDTH - PADDLE_WIDTH,
  y: CANVAS_HEIGHT / 2 - PADDLE_HEIGHT / 2,
  width: PADDLE_WIDTH,
  height: PADDLE_HEIGHT,
  score: 0
};

const ball = {
  x: CANVAS_WIDTH / 2,
  y: CANVAS_HEIGHT / 2,
  dx: BALL_SPEED * (Math.random() > 0.5 ? 1 : -1),
  dy: BALL_SPEED * (Math.random() > 0.5 ? 1 : -1),
  size: BALL_SIZE
};

const keys = {};

document.addEventListener("keydown", (e) => {
  keys[e.key] = true;
});

document.addEventListener("keyup", (e) => {
  keys[e.key] = false;
});

function movePlayer() {
  if (keys["ArrowUp"]) {
    player.y -= PADDLE_SPEED;
  }
  if (keys["ArrowDown"]) {
    player.y += PADDLE_SPEED;
  }
  player.y = Math.max(0, Math.min(CANVAS_HEIGHT - PADDLE_HEIGHT, player.y));
}

function moveAI() {
  if (ai.y + ai.height / 2 < ball.y) {
    ai.y += PADDLE_SPEED * 0.6;
  } else {
    ai.y -= PADDLE_SPEED * 0.6;
  }
  ai.y = Math.max(0, Math.min(CANVAS_HEIGHT - PADDLE_HEIGHT, ai.y));
}

function moveBall() {
  ball.x += ball.dx;
  ball.y += ball.dy;

  if (ball.y <= 0 || ball.y + BALL_SIZE >= CANVAS_HEIGHT) {
    ball.dy = -ball.dy;
  }

  if (ball.x <= player.x + player.width && ball.y + BALL_SIZE >= player.y && ball.y <= player.y + player.height) {
    ball.dx = -ball.dx;
  }
  if (ball.x + BALL_SIZE >= ai.x && ball.y + BALL_SIZE >= ai.y && ball.y <= ai.y + ai.height) {
    ball.dx = -ball.dx;
  }

  if (ball.x <= 0) {
    ai.score++;
    resetBall();
  }
  if (ball.x + BALL_SIZE >= CANVAS_WIDTH) {
    player.score++;
    resetBall();
  }
}

function resetBall() {
  ball.x = CANVAS_WIDTH / 2;
  ball.y = CANVAS_HEIGHT / 2;
  ball.dx = BALL_SPEED * (Math.random() > 0.5 ? 1 : -1);
  ball.dy = BALL_SPEED * (Math.random() > 0.5 ? 1 : -1);
}

function draw() {
  ctx.fillStyle = "black";
  ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);

  ctx.beginPath();
  ctx.setLineDash([5, 15]);
  ctx.moveTo(CANVAS_WIDTH / 2, 0);
  ctx.lineTo(CANVAS_WIDTH / 2, CANVAS_HEIGHT);
  ctx.strokeStyle = "white";
  ctx.stroke();

  ctx.fillStyle = "white";
  ctx.fillRect(player.x, player.y, player.width, player.height);
  ctx.fillRect(ai.x, ai.y, ai.width, ai.height);

  ctx.fillRect(ball.x, ball.y, ball.size, ball.size);

  ctx.font = "32px monospace";
  ctx.fillText(player.score, CANVAS_WIDTH / 4, 50);
  ctx.fillText(ai.score, (CANVAS_WIDTH / 4) * 3, 50);
}

function gameLoop() {
  movePlayer();
  moveAI();
  moveBall();
  draw();
  requestAnimationFrame(gameLoop);
}

gameLoop();
