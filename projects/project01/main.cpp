#include <iostream>
#include "treasurehunt.h"

using namespace std;

int main() {
    char choice;
    do {
        printRules();
        TreasureHunt game;
        game.makeBoard();
        game.play();
        cout << "Play again? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');
    cout << "Thanks for playing!\n";
    return 0;
}
