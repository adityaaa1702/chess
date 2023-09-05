#include <iostream>
using namespace std;

const int BOARD_SIZE = 8;

bool isValidPosition(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    std::cout << "  a b c d e f g h" << std::endl; // Column labels

    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        std::cout << i + 1 << " "; // Row labels

        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                std::cout << "_" << " ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }

        std::cout << i + 1 << std::endl; // Row labels (again for bottom)
    }

    std::cout << "  a b c d e f g h" << std::endl; // Column labels (again for bottom)
    std::cout << std::endl;

    // Print the legend or key hint
    std::cout << "Piece Legend:" << std::endl;
    std::cout << "R - Rook" << std::endl;
    std::cout << "N - Knight" << std::endl;
    std::cout << "B - Bishop" << std::endl;
    std::cout << "Q - Queen" << std::endl;
    std::cout << "K - King" << std::endl;
    std::cout << "P - Pawn" << std::endl;
}

void markValidMoves(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char piece) {
     if (!isValidPosition(row, col)) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    if (piece == 'R' || piece == 'r') {
        board[row][col] = 'R';

        // Mark valid moves horizontally
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j != col) {
                board[row][j] = '*';
            }
        }

        // Mark valid moves vertically
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i != row) {
                board[i][col] = '*';
            }
        }
    }

    if (piece == 'N' || piece == 'n') {
        // Mark valid moves for the knight
        int moves[8][2] = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {1, -2},  {1, 2},  {2, -1},  {2, 1}
        };

        board[row][col] = 'N';  // Mark the knight's current position with "?"

        // Iterate over all possible knight moves
        for (int i = 0; i < 8; i++) {
            int newRow = row + moves[i][0];
            int newCol = col + moves[i][1];

            // Check if the new position is within the board boundaries
            if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
                board[newRow][newCol] = '*';  // Mark the valid move with "*"
            }
        }
    }

    if (piece == 'Q' || piece == 'q') {
        board[row][col] = 'Q';

        // Mark valid moves horizontally
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j != col) {
                board[row][j] = '*';
            }
        }

        // Mark valid moves vertically
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i != row) {
                board[i][col] = '*';
            }
        }

        // Mark valid moves diagonally (top-left to bottom-right)
        for (int i = row + 1, j = col + 1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
            board[i][j] = '*';
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            board[i][j] = '*';
        }

        // Mark valid moves diagonally (top-right to bottom-left)
        for (int i = row + 1, j = col - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
            board[i][j] = '*';
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < BOARD_SIZE; i--, j++) {
            board[i][j] = '*';
        }
    }

   if (piece == 'P' || piece == 'p') {
     if(row==0){
        cout<<"                 "<<endl;
        cout<<"                 "<<endl;
        cout<<"pawn can't take this position"<<endl;
        cout<<"                 "<<endl;
        cout<<"                 "<<endl;
    }

    else{
    board[row][col] = 'P';

    // Display a message indicating the pawn is selected
    cout << "Pawn selected. This is a very basic program that doesn't show interaction with other pieces." << endl;
   
  // Check if the pawn is on its starting position (2nd row for white, 7th row for black)
    if ((row == 1)) {
        cout << "Pawn is on its starting position. Choose your move (1 for one step, 2 for two steps): ";
        int choice;
        cin >> choice;
        
        // Check if the player wants to move one or two steps
        if (choice == 1) {
            int moveRow = row + 1; // Move one step forward

            // Check if the destination square is within the board bounds and empty
            if (moveRow >= 0 && moveRow < BOARD_SIZE && board[moveRow][col] == ' ') {
                board[moveRow][col] = '*';
            }
        } else if (choice == 2) {
            int doubleMoveRow = row + 2; // Move two steps forward

            // Check if the destination squares are within the board bounds and empty
            if (board[row + 1][col] == ' ' && board[doubleMoveRow][col] == ' ') {
                board[doubleMoveRow][col] = '*';
            }
        } else {
            cout << "Invalid choice. Please choose 1 or 2 for your move." << endl;
        }
    } else {
        // Pawn is not on its starting position, so it can only move one step
        int moveRow = row + 1; // Move one step forward

        // Check if the destination square is within the board bounds and empty
        if (moveRow >= 0 && moveRow < BOARD_SIZE && board[moveRow][col] == ' ') {
            board[moveRow][col] = '*';
        }
    }
    }
}

if (piece == 'K' || piece == 'k') {
    board[row][col] = 'K';

    // Define the possible moves for the king
    int moves[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    // Mark valid moves for the king
    for (int i = 0; i < 8; i++) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];

        // Check if the new position is within the board boundaries
        if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
            if (board[newRow][newCol] == ' ') {
                board[newRow][newCol] = '*';
            }
        }
    }
}
if (piece == 'B' || piece == 'b') {
    board[row][col] = 'B';

    // Mark valid moves diagonally (top left to bottom right)
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == ' ') {
            board[i][j] = '*';
        } else {
            break;
        }
        i--;
        j--;
    }

    // Mark valid moves diagonally (top right to bottom left)
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < BOARD_SIZE) {
        if (board[i][j] == ' ') {
            board[i][j] = '*';
        } else {
            break;
        }
        i--;
        j++;
    }

    // Mark valid moves diagonally (bottom left to top right)
    i = row + 1;
    j = col - 1;
    while (i < BOARD_SIZE && j >= 0) {
        if (board[i][j] == ' ') {
            board[i][j] = '*';
        } else {
            break;
        }
        i++;
        j--;
    }

    // Mark valid moves diagonally (bottom right to top left)
    i = row + 1;
    j = col + 1;
    while (i < BOARD_SIZE && j < BOARD_SIZE) {
        if (board[i][j] == ' ') {
            board[i][j] = '*';
        } else {
            break;
        }
        i++;
        j++;
    }
}


}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];

    cout<<".........................MOVES JUST FOR WHITE PEICES......................."<<endl;
    cout<<"                                  "<<endl;
    cout<<"                                  "<<endl;

    // Initialize the board with empty squares
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Display the empty chessboard
    displayBoard(board);

    while (true) {
        // Get the chess piece and its position as input
        char piece;
        int row, col;

        std::cout << "Enter the chess piece (e.g., 'R' for rook, 'N' for knight): ";
        std::cin >> piece;

        if (piece == 'exit' || piece == 'EXIT') {
            break;  // Exit the loop and terminate the program
        }

        std::cout << "Enter the position of the chess piece (e.g., 'a1', 'e4'): ";
        std::string position;
        std::cin >> position;

        col = position[0] - 'a';
        row = position[1] - '1';

        // Mark valid moves for the given chess piece and position

        markValidMoves(board, row, col, piece);

        // Display the board with valid moves marked and the legend
        displayBoard(board);

        // Reset the board for the next test case
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = ' ';
            }
        }


    }

    // Wait for user input before exiting
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
