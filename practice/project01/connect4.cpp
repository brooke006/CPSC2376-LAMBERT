#include "connect4.h"

using namespace std;

Connect4::Connect4() : state(GameState::ONGOING), player1Turn(true) {
    makeBoard();
}

// Display game rules
void printRules() {
    cout << "Welcome to Connect Four!\n"
        << "Rules:\n"
        << "1. Players take turns dropping a piece into a column.\n"
        << "2. The first player to connect four pieces in a row (horizontally, vertically, or diagonally) wins.\n"
        << "3. The game ends in a draw if the board fills up.\n\n";
}

// Initialize the board
void Connect4::makeBoard() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            board[i][j] = Cell::EMPTY;
        }
    }
}

// Print the board
void Connect4::printBoard() {
    cout << "  0 1 2 3 4 5 6\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            char symbol = (board[i][j] == Cell::PLAYER_1) ? 'X' :
                (board[i][j] == Cell::PLAYER_2) ? 'O' : '.';
            cout << " " << symbol;
        }
        cout << "\n";
    }
}

// Check if a column is a valid move
bool Connect4::validMove(int col) {
    return col >= 0 && col < 7 && board[0][col] == Cell::EMPTY;
}

// Drop piece into the selected column
void Connect4::dropPiece(int col) {
    for (int i = 5; i >= 0; --i) {
        if (board[i][col] == Cell::EMPTY) {
            board[i][col] = player1Turn ? Cell::PLAYER_1 : Cell::PLAYER_2;
            break;
        }
    }
}

// Check game status
GameState Connect4::gameStatus() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] == Cell::EMPTY) continue;
            Cell current = board[i][j];

            // Horizontal check
            if (j <= 3 && current == board[i][j + 1] && current == board[i][j + 2] && current == board[i][j + 3])
                return current == Cell::PLAYER_1 ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

            // Vertical check
            if (i <= 2 && current == board[i + 1][j] && current == board[i + 2][j] && current == board[i + 3][j])
                return current == Cell::PLAYER_1 ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

            // Diagonal (\) check
            if (i <= 2 && j <= 3 && current == board[i + 1][j + 1] && current == board[i + 2][j + 2] && current == board[i + 3][j + 3])
                return current == Cell::PLAYER_1 ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;

            // Diagonal (/) check
            if (i >= 3 && j <= 3 && current == board[i - 1][j + 1] && current == board[i - 2][j + 2] && current == board[i - 3][j + 3])
                return current == Cell::PLAYER_1 ? GameState::PLAYER_1_WINS : GameState::PLAYER_2_WINS;
        }
    }

    // Check for a draw
    bool full = true;
    for (int j = 0; j < 7; ++j) {
        if (board[0][j] == Cell::EMPTY) {
            full = false;
            break;
        }
    }

    return full ? GameState::DRAW : GameState::ONGOING;
}

// Game loop
void Connect4::play() {
    while (state == GameState::ONGOING) {
        printBoard();
        int col;
        cout << "Player " << (player1Turn ? "1 (X)" : "2 (O)") << ", enter column (0-6): ";
        while (!(cin >> col) || !validMove(col)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid move. Enter a valid column (0-6): ";
        }

        dropPiece(col);
        state = gameStatus();
        player1Turn = !player1Turn;
    }

    printBoard();
    switch (state) {
    case GameState::PLAYER_1_WINS:
        cout << "Player 1 (X) wins!\n";
        break;
    case GameState::PLAYER_2_WINS:
        cout << "Player 2 (O) wins!\n";
        break;
    case GameState::DRAW:
        cout << "The game is a draw!\n";
        break;
    default:
        break;
    }
}
