#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H
#include <iostream>
#include <vector>
#include <string>

enum class GameState { ONGOING, PLAYER_WINS, GAME_OVER };
enum class CellColor { RED, GREEN, BLUE, YELLOW, ORANGE };

class TreasureHunt {
private:
    std::vector<std::vector<CellColor>> board;
    int movesLeft;
    int movesUsed;
    CellColor currentColor;
    int boardSize;
    int currentLevel;
    std::string secretCode;

public:
    TreasureHunt();
    void makeBoard();
    void play();
    GameState gameStatus();
    void printBoard();
    void floodFill(int x, int y, CellColor oldColor, CellColor newColor);
    void changeColor(CellColor newColor);
    void nextLevel();
    void displayReward();
    std::string generateSecretCode();
};

void printRules();
#endif // TREASURE_HUNT_H
