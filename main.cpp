#include <iostream>
#include <string>
using namespace std;

bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    char board[3][3];
    string line;

    // Read the board
    for (int i = 0; i < 3; i++) {
        cin >> line;
        for (int j = 0; j < 3; j++) {
            board[i][j] = line[j];
        }
    }

    // Count x's and o's
    int countX = 0, countO = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') countX++;
            else if (board[i][j] == 'o') countO++;
        }
    }

    // Check if x or o wins
    bool xWins = checkWin(board, 'x');
    bool oWins = checkWin(board, 'o');

    // Validation checks
    // x goes first, so countX should be equal to countO or countO + 1
    if (countX != countO && countX != countO + 1) {
        cout << "invalid" << endl;
        return 0;
    }

    // Both cannot win at the same time
    if (xWins && oWins) {
        cout << "invalid" << endl;
        return 0;
    }

    // If x wins, the game should have stopped
    // So o shouldn't have made another move after x won
    // This means if x wins, countX should equal countO (o made the last move before x won)
    // Actually, if x wins, it could be x's turn or after x's turn
    // If x wins on x's turn, then countX = countO + 1
    // If x wins, o cannot have played after that
    if (xWins && countX == countO) {
        // x won, but then o played again - invalid
        cout << "invalid" << endl;
        return 0;
    }

    // If o wins, the game should have stopped
    // So x shouldn't have made another move after o won
    // If o wins on o's turn, then countX = countO
    // x cannot play after o wins
    if (oWins && countX != countO) {
        // o won, but then x played again - invalid
        cout << "invalid" << endl;
        return 0;
    }

    // Determine the game state
    if (xWins) {
        cout << "win" << endl;
    } else if (oWins) {
        cout << "lose" << endl;
    } else if (countX + countO == 9) {
        // Board is full
        cout << "tie" << endl;
    } else {
        cout << "ongoing" << endl;
    }

    return 0;
}
