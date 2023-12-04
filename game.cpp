#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>  
using namespace std;

const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";  
const string MAGENTA = "\033[1;35m";
const string RESET_COLOR = "\033[0m";


void clearScreen() {
    system("cls");
}

void displayBoard(const vector<int>& board, const vector<bool>& revealed) {
    for (size_t i = 0; i < board.size(); ++i) {
        if (revealed[i]) {
            cout << BLUE << board[i] << " " << RESET_COLOR;
        } else {
            cout << YELLOW << "? " << RESET_COLOR;
        }
    }
    cout << endl;
} 

void pressEnterToContinue() {
    cout << "Press Enter"<< BLUE << " to continue"<< RESET_COLOR << "... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("cls");
}

int main() {
    int size;
    cout << "Welcome " << BLUE << "to" << RESET_COLOR << " the Memory Game!" << endl;
    cout << "Enter the size " << BLUE << "of" << RESET_COLOR << " an array ("<< MAGENTA << "6" << RESET_COLOR <<"-"<< MAGENTA << "20" << RESET_COLOR <<"): ";
    cin >> size;

    if (size < 6 || size > 20) {
        cout << "Invalid array size. Exiting the program." << endl;
        return 1;
    }

    vector<int> board;
    for (int i = 1; i <= size / 2; ++i) {
        board.push_back(i);
        board.push_back(i);
    }

    random_shuffle(board.begin(), board.end());

    vector<bool> revealed(board.size(), false);

    int moves = 0;

    while (count(revealed.begin(), revealed.end(), true) < board.size()) {
        clearScreen();

        displayBoard(board, revealed);

        int index1, index2;
        cout << "Enter the index "<< BLUE << "to " << RESET_COLOR << "show: ";
        cin >> index1;

        if (index1 < 1 || index1 > size || revealed[index1 - 1]) {
            cout << "Invalid index. Try again." << endl;
            pressEnterToContinue();
            continue;
        }

        revealed[index1 - 1] = true;

        displayBoard(board, revealed);

        cout << "Enter the second index "<< BLUE << "to" << RESET_COLOR <<" show: ";
        cin >> index2;

        if (index2 < 1 || index2 > size || revealed[index2 - 1]) {
            cout << "Invalid index. Try again." << endl;
            revealed[index1 - 1] = false;  
            pressEnterToContinue();
            continue;
        }

        revealed[index2 - 1] = true;

        if (board[index1 - 1] == board[index2 - 1]) {
            cout << "The cards "<< YELLOW << "match!" << RESET_COLOR << endl;
        } else {
            cout << "The cards "<< BLUE << "do " << YELLOW << "not " << RESET_COLOR << "match. Try again!" << endl;
            pressEnterToContinue();
            revealed[index1 - 1] = false;
            revealed[index2 - 1] = false;
            clearScreen();
        }

        moves++;
    }

    cout << YELLOW << "Game over!"<< RESET_COLOR << " All pairs matched in " << YELLOW << moves << RESET_COLOR <<" moves." << endl;

    return 0;
}
