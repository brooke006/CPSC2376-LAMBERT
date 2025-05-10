#include "game.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Game::Game(int size) : boardSize(size) {
    srand(static_cast<unsigned>(time(0)));
    reset();
}

void Game::reset() {
    board.clear();
    board.resize(boardSize, std::vector<CellColor>(boardSize));
    movesLeft = boardSize + 3;
    secretCode = generateSecretCode();

    // Generate random board
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
    if (boardSize < 8) boardSize++;
    reset();
}

std::string Game::getSecretCode() const {
    return secretCode;
}

SDL_Color Game::getSDLColor(CellColor color) const {
    switch (color) {
    case RED:    return { 255, 0, 0, 255 };
    case GREEN:  return { 0, 255, 0, 255 };
    case BLUE:   return { 0, 0, 255, 255 };
    case YELLOW: return { 255, 255, 0, 255 };
    case ORANGE: return { 255, 165, 0, 255 };
    default:     return { 255, 255, 255, 255 };
    }
}

void Game::drawBoard(SDL_Renderer* renderer) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            SDL_Rect cell = {
                50 + j * 50,
                50 + i * 50,
                48,
                48
            };

            SDL_Color color = getSDLColor(board[i][j]);
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(renderer, &cell);

            // Draw cell border
            SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
            SDL_RenderDrawRect(renderer, &cell);
        }
    }
}

void Game::drawColorPalette(SDL_Renderer* renderer) {
    for (int i = 0; i < 5; i++) {
        SDL_Rect cell = {
            50 + i * 70,
            350,
            60,
            60
        };

        SDL_Color color = getSDLColor(static_cast<CellColor>(i));
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &cell);

        // Draw border (thicker for current color)
        SDL_SetRenderDrawColor(renderer,
            (currentColor == static_cast<CellColor>(i)) ? 255 : 128,
            (currentColor == static_cast<CellColor>(i)) ? 255 : 128,
            (currentColor == static_cast<CellColor>(i)) ? 255 : 128, 255);
        SDL_RenderDrawRect(renderer, &cell);
        if (currentColor == static_cast<CellColor>(i)) {
            // Draw thicker border for current color
            SDL_Rect outerCell = { cell.x - 1, cell.y - 1, cell.w + 2, cell.h + 2 };
            SDL_RenderDrawRect(renderer, &outerCell);
        }
    }
}

void Game::drawUI(SDL_Renderer* renderer) {
    // Draw moves left indicator
    for (int i = 0; i < movesLeft; i++) {
        SDL_Rect moveRect = { 10 + i * 15, 10, 10, 10 };
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &moveRect);
    }

    // Draw game state
    GameState state = status();
    if (state == PLAYER_WINS) {
        SDL_Rect winRect = { 200, 500, 200, 30 };
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &winRect);
    }
    else if (state == GAME_OVER) {
        SDL_Rect loseRect = { 200, 500, 200, 30 };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &loseRect);
    }
}

void Game::draw(SDL_Renderer* renderer) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw components
    drawBoard(renderer);
    drawColorPalette(renderer);
    drawUI(renderer);
}

bool Game::handleKeyPress(SDL_Keycode key) {
    if (key >= SDLK_1 && key <= SDLK_5) {
        int colorIndex = key - SDLK_1;
        play(static_cast<CellColor>(colorIndex));
        return true;
    }
    return false;
}

bool Game::handleMouseClick(int x, int y) {
    // Check if click is on color palette
    for (int i = 0; i < 5; i++) {
        int paletteX = 50 + i * 70;
        if (x >= paletteX && x <= paletteX + 60 &&
            y >= 350 && y <= 350 + 60) {
            play(static_cast<CellColor>(i));
            return true;
        }
    }
    return false;
}