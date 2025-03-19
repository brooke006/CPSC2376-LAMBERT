#include <iostream>
#include "game.h"

using namespace std;

int main() {
    char choice;
    printRules();
    Game game;

    while (true) {
        cout << game;  // Show board before input
        cout << "Choose a color (R/G/B/Y/O or ? to see secret code): ";

        char color;
        cin >> color;

        if (color == '?') {  // Cheat code: Reveal secret code
            cout << "Secret Code: " << game.getSecretCode() << "\n";
            continue;
        }

        game.play(color);

        if (game.status() == PLAYER_WINS) {
            game.nextLevel();
            continue;
        }

        if (game.status() == GAME_OVER) {
            cout << "Game over! You ran out of moves.\n";
            break;
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}


