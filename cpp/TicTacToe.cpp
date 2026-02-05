#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;
class TicTacToe
{
    int arr[3][3];
    char player, computer;

public:
    TicTacToe(void)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    void displayBoard()
    {
        cout << "   0   1   2 " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i << " ";
            for (int j = 0; j < 3; j++)
            {
                char mark = ' ';
                if (arr[i][j] == 1)
                    mark = 'X';
                else if (arr[i][j] == 2)
                    mark = 'O';

                cout << " " << mark << " ";
                if (j < 2)
                    cout << "|";
            }
            cout << endl;
            if (i < 2)
                cout << "   -----------" << endl;
        }
        cout << endl;
    }
    void singlePlayer()
    {
        int currentPlayer = -1;
        int moveCount = 0;
        bool gameover = false;
        system("cls");
        cout << "==== TIC-TAC-TOE ====" << endl;
        displayBoard();
        cout << "Choose your symbol: (X or O) ";
        cin >> player;
        player = toupper(player);
        while (player != 'X' && player != 'O')
        {
            cout << "Invalid input Enter (X or O): ";
            cin >> player;
            player = toupper(player);
        }
        if (player == 'X')
        {
            computer = 'O';
        }
        else
        {
            computer = 'X';
        }
        char firstPlay;
        cout << "Who you wants to play first: (X or O) ";
        cin >> firstPlay;
        firstPlay = toupper(firstPlay);
        while (firstPlay != 'X' && firstPlay != 'O')
        {
            cout << "Invalid input Enter (X or O): ";
            cin >> firstPlay;
            firstPlay = toupper(firstPlay);
        }
        if (firstPlay == 'X')
        {
            currentPlayer = 1;
        }
        else
        {
            currentPlayer = 2;
        }
        while (!gameover)
        {
            system("cls");
            displayBoard();
            int row, col;
            if ((currentPlayer == 1 && player == 'X') || (currentPlayer == 2 && player == 'O'))
            {
                cout << "Your turn (" << player << ")." << endl;
                bool validMove = false;
                while (!validMove)
                {
                    cout << "Enter row (0-2): ";
                    if (!(cin >> row))
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input. ";
                        continue;
                    }
                    cout << "Enter col (0-2): ";
                    if (!(cin >> col))
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Invalid input. ";
                        continue;
                    }

                    if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && arr[row][col] == 0)
                    {
                        validMove = true;
                    }
                    else
                    {
                        cout << "Invalid position or already filled! Try again." << endl;
                    }
                }
            }
            else
            {
                cout << "Computer is thinking...." << endl;
                do
                {
                    row = rand() % 3;
                    col = rand() % 3;
                } while (arr[row][col] != 0);
            }
            arr[row][col] = currentPlayer;
            moveCount++;
            if (checkWin())
            {
                system("cls");
                displayBoard();
                cout << "Player " << (currentPlayer == 1 ? "X" : "O") << " wins!" << endl;
                gameover = true;
            }
            else if (moveCount == 9)
            {
                system("cls");
                displayBoard();
                cout << "It is a draw" << endl;
                gameover = true;
            }
            else
            {
                if (currentPlayer == 1)
                {
                    currentPlayer = 2;
                }
                else
                {
                    currentPlayer = 1;
                }
            }
            system("pause");
        }
    }
    void multiPlayer()
    {
        int currentPlayer = -1;
        int moveCount = 0;
        bool gameover = false;
        system("cls");
        cout << "==== TIC-TAC-TOE ====\n"
             << endl;
        displayBoard();
        char firstPlay;
        cout << "Who wants to play first: (X or O) ";
        cin >> firstPlay;
        firstPlay = toupper(firstPlay);
        while (firstPlay != 'X' && firstPlay != 'O')
        {
            cout << "Invalid input Enter (X or O): ";
            cin >> firstPlay;
        }
        if (firstPlay == 'X')
            currentPlayer = 1;
        else
            currentPlayer = 2;
        while (!gameover)
        {
            system("cls");
            displayBoard();
            int row = -1, col = -1;
            cout << "Player " << (currentPlayer == 1 ? "X" : "O") << "'s turn." << endl;

            bool validMove = false;
            while (!validMove)
            {
                cout << "Enter row (0-2): ";
                if (!(cin >> row))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid input. ";
                    continue;
                }
                cout << "Enter col (0-2): ";
                if (!(cin >> col))
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Invalid input. ";
                    continue;
                }

                if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && arr[row][col] == 0)
                {
                    validMove = true;
                }
                else
                {
                    cout << "Invalid position or already filled! Try again." << endl;
                }
            }
            arr[row][col] = currentPlayer;
            moveCount++;
            if (checkWin())
            {
                system("cls");
                displayBoard();
                cout << "Player " << (currentPlayer == 1 ? "X" : "O") << " wins!" << endl;
                gameover = true;
            }
            else if (moveCount == 9)
            {
                system("cls");
                displayBoard();
                cout << "It is a draw" << endl;
                gameover = true;
            }
            else
            {
                if (currentPlayer == 1)
                {
                    currentPlayer = 2;
                }
                else
                {
                    currentPlayer = 1;
                }
            }
            system("pause");
        }
    }
    bool checkWin()
    {
        for (int i = 0; i < 3; i++)
        {
            if (arr[i][0] != 0 && (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]))
            {
                return true;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (arr[0][i] != 0 && (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]))
            {
                return true;
            }
        }
        if (arr[1][1] != 0)
        {
            if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))
            {
                return true;
            }
        }
        return false;
    }
};
int gameChoice()
{
    system("cls");
    int gameChoice;
    cout << "==== TIC-TAC-TOE ====" << endl;
    cout << "\n1.Singleplayer\t2.Multiplayer\nHow do you want to play:\nEnter choice:";
    cin >> gameChoice;
    while (cin.fail() || (gameChoice != 1 && gameChoice != 2))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid Choice! Enter again: ";
        cin >> gameChoice;
    }
    return gameChoice;
}
int main()
{
    srand(time(0));
    TicTacToe Game;
    if (gameChoice() == 1)
    {
        Game.singlePlayer();
    }
    else
    {
        Game.multiPlayer();
    };
    return 0;
}