#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>  
using namespace std;



void clearScreen() {
    system("cls");
}

void displayBoard(const vector<int>& board, const vector<bool>& revealed) {
    for (size_t i = 0; i < board.size(); ++i) {
        if (revealed[i]) {
            cout << board[i] << " ";
        } else {
            cout << "? ";
        }
    }
    cout << endl;
} 

void pressEnterToContinue() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("cls");
}

int main() {
    int size;
    cout << "Welcome to the Memory Game!" << endl;
    cout << "Enter the size of an array (6-20): ";
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
        cout << "Enter the index to show: ";
        cin >> index1;

        if (index1 < 1 || index1 > size || revealed[index1 - 1]) {
            cout << "Invalid index. Try again." << endl;
            pressEnterToContinue();
            continue;
        }

        revealed[index1 - 1] = true;

        displayBoard(board, revealed);

        cout << "Enter the second index to show: ";
        cin >> index2;

        if (index2 < 1 || index2 > size || revealed[index2 - 1]) {
            cout << "Invalid index. Try again." << endl;
            revealed[index1 - 1] = false;  // Undo the reveal of the first card
            pressEnterToContinue();
            continue;
        }

        revealed[index2 - 1] = true;

        if (board[index1 - 1] == board[index2 - 1]) {
            cout << "The cards match!" << endl;
        } else {
            cout << "The cards do not match. Try again!" << endl;
            pressEnterToContinue();
            revealed[index1 - 1] = false;
            revealed[index2 - 1] = false;
            clearScreen();
        }

        moves++;
    }

    cout << "Game over! All pairs matched in " << moves << " moves." << endl;

    return 0;
}
