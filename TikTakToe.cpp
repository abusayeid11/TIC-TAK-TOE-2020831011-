#include<bits/stdc++.h>
using namespace std;

// print the tic-tac-toe board
void displayBoard(const vector<vector<char>>& gameBoard) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << gameBoard[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// If current game state has a winner
char checkWinner(const vector<vector<char>>& gameBoard) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][0] != ' ') {
            return gameBoard[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[0][i] != ' ') {
            return gameBoard[0][i];
        }
    }
    // Check diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[0][0] != ' ') {
        return gameBoard[0][0];
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[0][2] != ' ') {
        return gameBoard[0][2];
    }
    // If no winner
    return ' ';
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& gameBoard) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (gameBoard[i][j] == ' ') {
                return false; // There is an empty cell
            }
        }
    }
    return true; // board is full
}

//player's move with manual input
void playerMove(vector<vector<char>>& gameBoard) {
    int row, col;
    cout << "Enter row and column (1-3): ";
    cin >> row >> col;
    row--; // 0-based indexing
    col--; // 0-based indexing
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == ' ') {
        gameBoard[row][col] = 'X';
    } else {
        cout << "Invalid move. Try again." << endl;
        playerMove(gameBoard);
    }
}

// Function to perform computer's move
void computerMove(vector<vector<char>>& gameBoard) {
    srand(time(0));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (gameBoard[row][col] != ' ');
    gameBoard[row][col] = 'O';
}

int main() {
    vector<vector<char>> gameBoard(3, vector<char>(3, ' ')); // 3*3 2D array to store game blocks

    while (true) {
        displayBoard(gameBoard);
        playerMove(gameBoard);

        if (checkWinner(gameBoard) == 'X') {
            cout << "Congratulations! You win!" << endl;
            break;
        }
        if (isBoardFull(gameBoard)) {
            cout << "It's a draw!" << endl;
            break;
        }
        displayBoard(gameBoard);
        computerMove(gameBoard);

        if (checkWinner(gameBoard) == 'O') {
            cout << "Computer wins!" << endl;
            break;
        }
        if (isBoardFull(gameBoard)) {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
