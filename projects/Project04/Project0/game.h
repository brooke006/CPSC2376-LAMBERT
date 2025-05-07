// game.h
#pragma once
#include <vector>
#include <string>
#include <iostream>

class Game {
public:
    enum CellColor { RED, GREEN, BLUE, YELLOW, ORANGE };
    enum GameState { ONGOING, PLAYER_WINS, GAME_OVER };

    Game(int size = 3);
    void reset();
    void play(CellColor color);
    GameState status() const;
    void nextLevel();
    std::string getSecretCode() const;
    void draw() const; // Console-based drawing

    int getBoardSize() const { return boardSize; }
    int getMovesLeft() const { return movesLeft; }
    CellColor getCurrentColor() const { return currentColor; }

private:
    std::vector<std::vector<CellColor>> board;
    int boardSize;
    int movesLeft;
    std::string secretCode;
    CellColor currentColor;

    void floodFill(int x, int y, CellColor oldColor, CellColor newColor);
    bool isBoardOneColor() const;
    std::string generateSecretCode();
};