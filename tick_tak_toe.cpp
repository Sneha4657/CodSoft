#include <iostream>
using namespace std;


char board[3][3];


void resetBoard() {
    char cell = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = cell++;
}


void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n";
}


bool checkWin(char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}


bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}


bool makeMove(char player) {
    int move;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;

    
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    
    if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        return false;
    }

    board[row][col] = player;
    return true;
}


void playGame() {
    char currentPlayer = 'X';
    resetBoard();
    displayBoard();

    while (true) {
        if (makeMove(currentPlayer)) {
            displayBoard();

            if (checkWin(currentPlayer)) {
                cout << "🎉 Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                cout << "It's a draw! 🤝\n";
                break;
            }

           
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char playAgain;

    cout << "=== Welcome to Tic-Tac-Toe ===\n";

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! 😄\n";
    return 0;
}
