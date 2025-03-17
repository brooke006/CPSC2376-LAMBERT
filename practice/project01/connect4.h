#ifndef CONNECT4_H
#define CONNECT4_H

#include <iostream>

enum class GameState { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };
enum class Cell { EMPTY, PLAYER_1, PLAYER_2 };

class Connect4 {
private:
    Cell board[6][7];  // 6 rows, 7 columns
    GameState state;
    bool player1Turn;

public:
    Connect4();
    void makeBoard();
    void play();
    GameState gameStatus();
    void printBoard();
    bool validMove(int col);
    void dropPiece(int col);
};

void printRules();

#endif // CONNECT4_H
