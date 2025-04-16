#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

bool gameOver;
const int height = 20;
const int width = 20;
int x, y, fruitX, fruitY, score = 0;

enum eDirection
{
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

eDirection dir;
int tailX[100], tailY[100], nTail;

void setup()
{
    gameOver = false;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width; i++) // First row
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1) // Left row and Right row
            {
                cout << "#";
            }
            else if (i == y && j == x)
            {
                cout << "O"; // Snake's head
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F"; // Food position
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (i == tailY[k] && j == tailX[k])
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++) // Last row
    {
        cout << "#";
    }
    cout << endl;
    cout << endl;
    cout << "Score: " << score;
}

// Setting up the controller keys
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        default:
            break;
        }
    }
}

// Main logic of the game
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    int prev2X, prev2Y;
    
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }

    if (x < 0 || x > width || y < 0 || y > height)
    {
        gameOver = true;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (x == tailX[i] && y == tailY[i])
        {
            gameOver = true;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main()
{
    setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        _sleep(40);
    }

    return 0;
}