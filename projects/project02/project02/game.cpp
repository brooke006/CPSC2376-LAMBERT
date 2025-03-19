#include "game.h"

Game::Game() {
    srand(time(0));
    boardSize = 3;
    reset();
}

void Game::reset() {
    board.clear();
    board.resize(boardSize, std::vector<CellColor>(boardSize));
    movesLeft = boardSize + 3;
    secretCode = generateSecretCode();

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = static_cast<CellColor>(rand() % 5);
        }
    }
    currentColor = board[0][0];
}

std::string Game::generateSecretCode() {
    const std::vector<std::string> codes = { "WIN", "GO!", "PASS", "READY", "LEVELUP" };
    return codes[rand() % codes.size()];
}

void Game::floodFill(int x, int y, CellColor oldColor, CellColor newColor) {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return;
    if (board[y][x] != oldColor || board[y][x] == newColor) return;

    board[y][x] = newColor;
    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);
}

void Game::play(char choice) {
    choice = std::tolower(choice);

    CellColor chosenColor;
    switch (choice) {
    case 'r': chosenColor = RED; break;
    case 'g': chosenColor = GREEN; break;
    case 'b': chosenColor = BLUE; break;
    case 'y': chosenColor = YELLOW; break;
    case 'o': chosenColor = ORANGE; break;
    default:
        std::cout << "Invalid choice. Choose R/G/B/Y/O.\n";
        return;
    }

    if (chosenColor == currentColor) {
        std::cout << "The board is already that color.\n";
        return;
    }

    floodFill(0, 0, currentColor, chosenColor);
    currentColor = chosenColor;
    movesLeft--;
}

GameState Game::status() const {
    return isBoardOneColor() ? PLAYER_WINS : (movesLeft > 0 ? ONGOING : GAME_OVER);
}

bool Game::isBoardOneColor() const {
    CellColor first = board[0][0];
    for (const auto& row : board) {
        for (CellColor color : row) {
            if (color != first) return false;
        }
    }
    return true;
}

void Game::nextLevel() {
    std::cout << "You completed the level! Enter the secret code to proceed: " << secretCode << "\n";

    std::string inputCode;
    std::cin >> inputCode;

    while (inputCode != secretCode) {
        std::cout << "Incorrect! Try again: ";
        std::cin >> inputCode;
    }

    std::cout << "Correct! Moving to the next level.\n";

    if (boardSize < 8) boardSize++;

    reset();
}

std::string Game::getSecretCode() const {
    return secretCode;
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
    const char colorChars[] = { 'R', 'G', 'B', 'Y', 'O' };

    os << "\nMoves Left: " << game.movesLeft << "\n";
    for (const auto& row : game.board) {
        for (CellColor color : row) {
            os << colorChars[color] << " ";
        }
        os << "\n";
    }
    return os;
}

void printRules() {
    std::cout << "=== HOW TO PLAY ===\n"
        << "Your goal is to flood the board with a single color before you run out of moves.\n"
        << "Choose a color by entering its letter:\n"
        << "   R - Red\n"
        << "   G - Green\n"
        << "   B - Blue\n"
        << "   Y - Yellow\n"
        << "   O - Orange\n"
        << "The color will spread from the top-left corner outward.\n"
        << "If the entire board becomes one color, you win.\n"
        << "If you run out of moves first, the game ends.\n"
        << "Good luck!\n\n";
}


