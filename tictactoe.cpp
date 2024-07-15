#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

void printBoard(const vector<char>& board) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

bool isMovesLeft(const vector<char>& board) {
    for (char cell : board) {
        if (cell == EMPTY) {
            return true;
        }
    }
    return false;
}

int evaluate(const vector<char>& board) {
    // Check rows for victory
    for (int row = 0; row < 3; row++) {
        if (board[row*3] == board[row*3 + 1] && board[row*3 + 1] == board[row*3 + 2]) {
            if (board[row*3] == PLAYER_X)
                return +10;
            else if (board[row*3] == PLAYER_O)
                return -10;
        }
    }

    // Check columns for victory
    for (int col = 0; col < 3; col++) {
        if (board[col] == board[col + 3] && board[col + 3] == board[col + 6]) {
            if (board[col] == PLAYER_X)
                return +10;
            else if (board[col] == PLAYER_O)
                return -10;
        }
    }

    // Check diagonals for victory
    if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] == PLAYER_X)
            return +10;
        else if (board[0] == PLAYER_O)
            return -10;
    }

    if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] == PLAYER_X)
            return +10;
        else if (board[2] == PLAYER_O)
            return -10;
    }

    // If no one has won
    return 0;
}

int minimax(vector<char>& board, int depth, bool isMax) {
    int score = evaluate(board);

    // If Maximizer has won the game
    if (score == 10)
        return score - depth;

    // If Minimizer has won the game
    if (score == -10)
        return score + depth;

    // If there are no more moves and no winner
    if (!isMovesLeft(board))
        return 0;

    // If this is maximizer's move
    if (isMax) {
        int best = INT_MIN;

        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = PLAYER_X;
                best = max(best, minimax(board, depth + 1, !isMax));
                board[i] = EMPTY;
            }
        }
        return best;
    }

    // If this is minimizer's move
    else {
        int best = INT_MAX;

        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = PLAYER_O;
                best = min(best, minimax(board, depth + 1, !isMax));
                board[i] = EMPTY;
            }
        }
        return best;
    }
}

int findBestMove(vector<char>& board) {
    int bestVal = INT_MIN;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == EMPTY) {
            board[i] = PLAYER_X;
            int moveVal = minimax(board, 0, false);
            board[i] = EMPTY;

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

void playerMove(vector<char>& board) {
    int move;
    cout << "Enter your move (1-9): ";
    cin >> move;
    move--;
    if (move >= 0 && move < 9 && board[move] == EMPTY) {
        board[move] = PLAYER_O;
    } else {
        cout << "Invalid move! Try again.\n";
        playerMove(board);
    }
}

int main() {
    vector<char> board(9, EMPTY);
    cout << "Tic-Tac-Toe Game\n";
    cout << "You are O, Computer is X\n";

    while (true) {
        printBoard(board);

        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }

        cout << "Your turn:\n";
        playerMove(board);

        if (evaluate(board) == -10) {
            printBoard(board);
            cout << "You win!\n";
            break;
        }

        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }

        int bestMove = findBestMove(board);
        board[bestMove] = PLAYER_X;
        cout << "Computer's turn:\n";

        if (evaluate(board) == 10) {
            printBoard(board);
            cout << "Computer wins!\n";
            break;
        }
    }

    return 0;
}
