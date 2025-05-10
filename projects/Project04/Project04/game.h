#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <string>

enum CellColor {
    RED = 0,
    GREEN = 1,
    BLUE = 2,
    YELLOW = 3,
    ORANGE = 4
};

enum GameState {
    ONGOING,
    PLAYER_WINS,
    GAME_OVER
};

class Game {
public:
    Game(int size = 5);
    void reset();
    void play(CellColor chosenColor);
    GameState status() const;
    void nextLevel();
    std::string getSecretCode() const;

    // SDL2 methods
    void draw(SDL_Renderer* renderer);
    bool handleKeyPress(SDL_Keycode key);
    bool handleMouseClick(int x, int y);

    // Getters
    int getMovesLeft() const { return movesLeft; }
    int getBoardSize() const { return boardSize; }

private:
    std::vector<std::vector<CellColor>> board;
    int boardSize;
    int movesLeft;
    std::string secretCode;
    CellColor currentColor;

    // Game logic
    void floodFill(int x, int y, CellColor oldColor, CellColor newColor);
    bool isBoardOneColor() const;
    std::string generateSecretCode();

    // Rendering helpers
    void drawBoard(SDL_Renderer* renderer);
    void drawColorPalette(SDL_Renderer* renderer);
    void drawUI(SDL_Renderer* renderer);
    SDL_Color getSDLColor(CellColor color) const;
};