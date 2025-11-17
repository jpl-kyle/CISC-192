// Name: John Pierre Lucas
// Course: CISC 192 - C++ Programming
// Date: 11/16/2025
// Assignment: Project 1: Tic Tac Toe 
#include <iostream>
#include <array>
#include <limits>
using namespace std;

class TicTacToe {
public:
    void displayBoard() const; //display the board
    bool isValidMove(int row, int col);
    void makeMove(int row, int col);
    bool checkWinner();
    bool isDraw();
    void playGame();

    TicTacToe(); // constructor

private:
    string board[3][3];
    int currentPlayer;
};

TicTacToe::TicTacToe() { //initialize board with empty spaces "-"
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = "-";
            }
        }
        currentPlayer = 1; //initialize each board so it starts at player 1.
}

void TicTacToe::displayBoard() const { //print the board
    cout << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
    cout << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
    cout << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}

bool TicTacToe::isValidMove(int row, int column) {
    if (row <0 || row > 2 || column < 0 || column > 2) { //checks if the input is 0-2 (1-3 on the user's behalf).
        cout << "Invalid input! Please provide a different row and column number. (row column): " << endl;
        return false;
    }
    else if (board[row][column] != "-") {  //checks if the input is not empty (with either x or o)
        cout << "That space is already in use! Please provide a different row and column number. (row column): " << endl;
        return false;
    }
    else {
        return true; 
    }
}

void TicTacToe::makeMove(int row, int column) {
    if (currentPlayer == 1) { //alternates turns, sets the string in the given row and column into their respective shapes
        board[row][column] = "x";
        currentPlayer = 2;
    } 
    else { 
        board[row][column] = "o";
        currentPlayer = 1;
    } 
}

bool TicTacToe::checkWinner() {
    for (int row = 0; row < 3; row++) { //horizontal check : if the first object is not empty, and the next two objects are the same, there is a winner
        if (board[row][0] != "-" && board[row][0] == board[row][1] && board[row][1] == board[row][2])
        return true;
    }

    for (int column = 0; column < 3; column++) { //vertical check : if the first object is not empty, and the next two objects are the same, there is a winner
        if (board[0][column] != "-" && board[0][column] == board[1][column] && board[1][column] == board[2][column])
        return true;
    }

    if (board[0][0] != "-" && board[0][0] == board[1][1] && board[1][1] == board[2][2]) { //downward diagonal check
        return true;
    } 

    if (board[0][2] != "-" && board[0][2] == board[1][1] && board[1][1] == board[2][0]) { //upward diagonal check
        return true;
    } 
    return false;
}

bool TicTacToe::isDraw() {
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            if (board[row][column] == "-"){ 
                return false; //if there's any instance of an empty slot, it returns false.
            }
        }
    }
    return true;
}

void TicTacToe::playGame() { //functions as the game, which can be called if you want to play it again.
    int row;
    int column;

    while (true) {
        displayBoard();

        cout << "Player " << currentPlayer << ", please make your move. (row column): " << endl;
        while (true) {
            if (!(cin >> row >> column)) { //check if it's an int. if not, clear it.
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please make your move. (row column): ";
                continue;
            } 
            --row; --column; //convert to 0-index
            if (!isValidMove(row, column)) { // if it's not valid, reprompt.
                continue;
            }
            break;
        }
        makeMove(row, column);// send the move into makeMove


        if (checkWinner() == true) { //I also learned ternary operators from my java class and a BroCode video.
            displayBoard();
            cout << "Player " << (currentPlayer == 1 ? 2 : 1) << " wins!\n";
            break;
        }

        if (isDraw() == true) {
            displayBoard();
            cout << "Draw Game!\n";
            break;
        }
    }
}

int main() { // MAIN
    char choice;

    do { // a loop that keeps creating games whenever you input y or Y, ends program when you input n or N.
        TicTacToe board_obj;
        board_obj.playGame(); // starts a game

        while (true) {
            cout << "Play again? (y/n): "; // once the game ends, look for a valid char input
            
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Play again? (y/n): ";
                continue; // clear any invalid input and ask again.
            }

            switch (choice) {
            case 'y':
            case 'Y':
                break; // break out of the switch-case, indicating a yes.
            case 'n':
            case 'N':
                return 0; // end program
            default:
                cout << "Play again? (y/n): ";
                continue; // default case: if the input wasn't y or n, send them back to the beginning of the while loop.
            }
            break; //breaks out of the while loop, 
        }
    } while (true); //will always be true until main returns 0.
}
