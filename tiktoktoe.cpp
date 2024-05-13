#include <iostream>
#include <limits> 

using namespace std;

void printBoard();
int checkWin();

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    int player = 1, input, status = -1;
    printBoard();

    while (status == -1) {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        cout << "Please enter a number for Player " << player << ": ";
        cin >> input;
        
        if (input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O') {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        board[input] = mark;
        printBoard();

        int result = checkWin();

        if (result == 1) {
            cout << "Player " << player << " is the winner!" << endl;
            return 0;
        } else if (result == 0) {
            cout << "It's a draw!" << endl;
            return 0;
        }

        player++;
    }

    return 0;
}

void printBoard() {
    system("cls");
    cout << "=== TIC TAC TOE ===\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "  \n";
    cout << "     |     |     \n";
    cout << "\n\n";
}

int checkWin() {
    if (board[1] == board[2] && board[2] == board[3]) {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6]) {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9]) {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9]) {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9]) {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7]) {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 'X' || board[i] == 'O') {
            count++;
        }
    }

    if (count == 9) {
        return 0;
    }
    return -1;
}
