#include <bits/stdc++.h>
using namespace std;

void display_board(vector<vector<char>> &board)
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << board[i][j];
            if (j < 3)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 3)
        {
            cout << "--+---+--\n";
        }
    }
    cout << endl;
}

char check_winner(vector<vector<char>> &board)
{
    for (int i = 1; i <= 3; i++)
    {
        if (board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[1][i] != ' ')
        {
            return board[1][i];
        }
        if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
    if (board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[1][3] != ' ')
    {
        return board[1][3];
    }
    return ' ';
}

bool isfull(vector<vector<char>> &board)
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board(4, vector<char>(4, ' '));
    display_board(board);
    char player;
    cout << "Enter your choice(X or O): ";
    cin >> player;
    player = (char)toupper(player);
    while (true)
    {
        int row, column;
        cout << "player " << player << "'s turn(row column): ";
        cin >> row >> column;
        if (row < 1 || row > 3 || column < 1 || column > 3 || board[row][column] != ' ')
        {
            cout << "You took invalid moove." << endl;
            continue;
        }
        board[row][column] = player;
        display_board(board);
        if (check_winner(board) != ' ')
        {
            if (check_winner(board) == player)
            {
                cout << "Player " << player << " is the winner";
                break;
            }
            else
            {
                cout << "Player " << player << " is the winner";
                break;
            }
        }
        if (isfull(board))
        {
            cout << "Game Over !!" << endl;
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}