#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  
#include <ctime>

enum GameState { ONGOING, PLAYER_WINS, GAME_OVER };
enum CellColor { RED, GREEN, BLUE, YELLOW, ORANGE };

class Game {
private:
    std::vector<std::vector<CellColor>> board;
    int movesLeft;
    int boardSize;
    std::string secretCode;
    CellColor currentColor;

    void floodFill(int x, int y, CellColor oldColor, CellColor newColor);
    std::string generateSecretCode();
    bool isBoardOneColor() const;

public:
    Game();
    void reset();
    void play(char choice);
    GameState status() const;
    void nextLevel();
    std::string getSecretCode() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};

void printRules();

#endif // GAME_H
