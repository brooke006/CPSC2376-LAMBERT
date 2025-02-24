#include "treasurehunt.h"
#include <cstdlib>  
#include <ctime>  

using namespace std;

TreasureHunt::TreasureHunt() : movesUsed(0), currentLevel(1), boardSize(3) {
    srand(time(0));
    makeBoard();
}

void printRules() {
    cout << "\n=== Welcome, Traveler! ===\n"
        << "You embark on a journey across different lands.\n"
        << "Each land is locked behind a color puzzle.\n"
        << "Your goal is to flood the land with one color within the allowed moves.\n"
        << "Succeed, and you'll earn a SECRET CODE to proceed!\n"
        << "Fail, and your journey ends here...\n\n";
}

void TreasureHunt::makeBoard() {
    board.clear();
    board.resize(boardSize, vector<CellColor>(boardSize));
    movesLeft = boardSize + 3;
    movesUsed = 0;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = static_cast<CellColor>(rand() % 5);
        }
    }
    currentColor = board[0][0];
}

void TreasureHunt::printBoard() {
    char colorChars[] = { 'R', 'G', 'B', 'Y', 'O' };
    cout << "\n=== Land " << currentLevel << " ===\n";
    cout << "Moves Left: " << movesLeft << " | Moves Used: " << movesUsed << "\n";
    cout << "  ";
    for (int i = 0; i < boardSize; ++i) cout << i << " ";
    cout << "\n";

    for (int i = 0; i < boardSize; ++i) {
        cout << i << " ";
        for (int j = 0; j < boardSize; ++j) {
            cout << colorChars[static_cast<int>(board[i][j])] << " ";
        }
        cout << "\n";
    }
}

void TreasureHunt::floodFill(int x, int y, CellColor oldColor, CellColor newColor) {
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize) return;
    if (board[y][x] != oldColor || board[y][x] == newColor) return;

    board[y][x] = newColor;

    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);
}

void TreasureHunt::changeColor(CellColor newColor) {
    if (newColor == currentColor) return;

    floodFill(0, 0, currentColor, newColor);
    currentColor = newColor;
    movesLeft--;
    movesUsed++;
}

GameState TreasureHunt::gameStatus() {
    CellColor target = board[0][0];
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] != target) return GameState::ONGOING;
        }
    }
    return GameState::PLAYER_WINS;
}

string TreasureHunt::generateSecretCode() {
    const vector<string> funCodes = {
        "$$$", "<3", ";)", "!!!", "XD", "WIN", "GO!", "1234", "BOSS", "SECRET"
    };
    return funCodes[rand() % funCodes.size()];
}

void TreasureHunt::nextLevel() {
    if (boardSize >= 8) {
        cout << "\\o/ Congratulations, Traveler! You conquered all lands! \\o/\n";
        return;
    }

    currentLevel++;
    boardSize++;
    makeBoard();
    secretCode = generateSecretCode();

    cout << "\n*** YOU DISCOVERED A NEW LAND! ***\n";
    cout << "To proceed, enter the secret treasure code: " << secretCode << "\n";

    string inputCode;
    cout << ">> Enter the code to unlock the next land: ";
    cin >> inputCode;

    while (inputCode != secretCode) {
        cout << "X Incorrect! Try again: ";
        cin >> inputCode;
    }

    cout << "^_^ Correct! Welcome to the next land!\n";
    displayReward();
}

void TreasureHunt::displayReward() {
    cout << "\n=== LEVEL COMPLETE! ===\n";
    cout << "\n*~*~*~*~*\n";
    cout << "   <o>   \n";
    cout << "  /|\\   \n";
    cout << "   |     \n";
    cout << "  / \\    \n";
    cout << "  GOLD!  \n";
    cout << "*~*~*~*~*\n";
}

void TreasureHunt::play() {
    while (true) {
        printBoard();
        cout << "Pick a color (R = Red, G = Green, B = Blue, Y = Yellow, O = Orange): ";

        char colorInput;
        cin >> colorInput;

        CellColor chosenColor;
        switch (tolower(colorInput)) {
        case 'r': chosenColor = CellColor::RED; break;
        case 'g': chosenColor = CellColor::GREEN; break;
        case 'b': chosenColor = CellColor::BLUE; break;
        case 'y': chosenColor = CellColor::YELLOW; break;
        case 'o': chosenColor = CellColor::ORANGE; break;
        default:
            cout << "X Invalid color. Try again.\n";
            continue;
        }

        changeColor(chosenColor);

        if (gameStatus() == GameState::PLAYER_WINS) {
            nextLevel();
        }
        else if (movesLeft == 0) {
            cout << "!!! Out of moves! Game Over. !!!\n";
            break;
        }
    }
}
