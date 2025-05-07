// game.cpp
#include "game.h"
#include <cstdlib>
#include <ctime>

Game::Game(int size) : boardSize(size) {
    srand(static_cast<unsigned>(time(0)));
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

void Game::play(CellColor chosenColor) {
    if (chosenColor == currentColor) {
        return; // Already that color
    }

    floodFill(0, 0, currentColor, chosenColor);
    currentColor = chosenColor;
    movesLeft--;
}

Game::GameState Game::status() const {
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
    if (boardSize < 8) boardSize++;
    reset();
}

std::string Game::getSecretCode() const {
    return secretCode;
}

void Game::draw() const {
    // Draw the board in console
    const char colorChars[] = { 'R', 'G', 'B', 'Y', 'O' };

    std::cout << "\nMoves Left: " << movesLeft << "\n";
    for (const auto& row : board) {
        for (CellColor color : row) {
            std::cout << colorChars[color] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nColor options:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << (i + 1) << ". " << colorChars[i] << "\n";
    }
}