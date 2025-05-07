// main.cpp
#include "game.h"
#include <iostream>
#include <string>

int main() {
    Game game;
    bool running = true;

    std::cout << "=== FLOOD-IT GAME ===\n";
    std::cout << "Goal: Flood the entire board with one color before running out of moves.\n";
    std::cout << "Controls: Enter a number 1-5 to select a color.\n";
    std::cout << "  1=Red, 2=Green, 3=Blue, 4=Yellow, 5=Orange\n";
    std::cout << "Press 'R' to restart the current level.\n";
    std::cout << "Press 'Q' to quit.\n\n";

    while (running) {
        // Draw the game
        game.draw();

        // Check game status
        if (game.status() == Game::PLAYER_WINS) {
            std::cout << "\nYou Win! Enter the secret code to proceed: ";
            std::string code;
            std::cin >> code;

            if (code == game.getSecretCode()) {
                std::cout << "Correct! Moving to the next level.\n";
                game.nextLevel();
            }
            else {
                std::cout << "Incorrect code. The secret code was: " << game.getSecretCode() << "\n";
                game.nextLevel(); // Still advance for simplicity
            }
            continue;
        }
        else if (game.status() == Game::GAME_OVER) {
            std::cout << "\nGame Over! You ran out of moves.\n";
            std::cout << "Press 'R' to restart or 'Q' to quit: ";
            char choice;
            std::cin >> choice;

            if (choice == 'r' || choice == 'R') {
                game.reset();
                continue;
            }
            else {
                running = false;
                continue;
            }
        }

        // Get player input
        std::cout << "\nChoose a color (1-5) or 'R' to restart, 'Q' to quit: ";
        char input;
        std::cin >> input;

        if (input == 'q' || input == 'Q') {
            running = false;
        }
        else if (input == 'r' || input == 'R') {
            game.reset();
        }
        else if (input >= '1' && input <= '5') {
            int colorIndex = input - '1';
            game.play(static_cast<Game::CellColor>(colorIndex));
        }
        else {
            std::cout << "Invalid input. Please try again.\n";
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}