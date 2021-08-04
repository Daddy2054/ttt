#include <iostream>
#include <string>
using namespace std; 
// here is it



void display_board(string board);
string place_marker(string board, char marker, int position);
bool win_check(string board, char marker);
bool space_check(string board, int position);
bool full_board_check(string board);
int player_choice(string board);
int validate_move();
char pick_marker();
bool replay();
void intro();
string board;

int main() {
    while (true) {
        // setup
        intro();
        bool player1_turn = true;
        board = "123456789";
        display_board(board);
        cout << "Player 1 starts.\n";
        char player1_marker = pick_marker();
        char player2_marker;
        if (player1_marker == 'X') {
            player2_marker = 'O';
        }
        else {
            player2_marker = 'X';
        }
        bool game_on = true;
        while (game_on) {
            if (player1_turn) {
                player1_turn = false;
                cout << "Player 1 move:\n";
                board = place_marker(board, player1_marker, player_choice(board));
                display_board(board);
                if (win_check(board, player1_marker)) {
                    cout << "Player 1 WON!!!\n";
                    break;
                }   
                //continue;
            }
            else {
                player1_turn = true;
                cout << "Player 2 move:\n";
                board = place_marker(board, player2_marker, player_choice(board));
                display_board(board);
                if (win_check(board, player2_marker)) {
                    cout << "Player 2 WON!!!\n";
                    break;
                }
            }
            if (full_board_check(board)) {
                cout << "No one won.\n";
                game_on = false;
            }
        }

        if (!replay()) {
            break;
        }
    }
    return 0;
}
// introduction
void intro() {
    cout << "Tic Tac Toe\n \n Welcome in the game!\n";
}

// if replay
bool replay() {
    char again = 'X';
    while (again != 'Y' && again != 'N') {
        cout << "Do You want to play again? 'Y' or 'N': ";
        cin >> again;
    }
    if (again == 'Y') {
        return true;
    }
    else {
        return false;
    }
}

// validate move
int validate_move() {
    int position = 0;
    char choice[] = "0";
    while (true) {
        cout << "Please pick a position 1-9: ";
        cin >> choice;
        int Succeeded = sscanf_s(choice, "%d", &position);
        if (!Succeeded || Succeeded == EOF) {
            position = 0;
        }
        if (position <= 9 && position >= 1) {
            return position;
        }
        else {
            cout << "This is not a valid number\n";
        }
    }
}

// player move
int player_choice(string board) {
    int position;
    while (true) {
        position = validate_move();
        if (space_check(board, position)) {
            return position;
        }
        else {
            cout << "this position is not available\n";
        }
    }
}

//check if board is full
bool full_board_check(string board) {
    int x = 0;
    for (int i = 0; i <= 9; i++) {
        if (board[i] == 'X' || board[i] == 'O') {
            x++;
        }
    }
    if (x == 9) {
        return true;
    }
    else {
        return false;
    }
}

//check if space is free
bool space_check(string board, int position) {
    if (board[position - 1] == 'X' || board[position - 1] == 'O') {
        return false;
    }
    else {
        return true;
    }
}

// check if win
bool win_check(string board, char marker) {
    if (board[0] == marker && board[1] == marker && board[2] == marker ||
        board[3] == marker && board[4] == marker && board[5] == marker ||
        board[6] == marker && board[7] == marker && board[8] == marker ||
        board[0] == marker && board[3] == marker && board[6] == marker ||
        board[1] == marker && board[4] == marker && board[7] == marker ||
        board[2] == marker && board[5] == marker && board[8] == marker ||
        board[0] == marker && board[4] == marker && board[8] == marker ||
        board[2] == marker && board[4] == marker && board[6] == marker
        ) {
        return true;
    }
    else {
        return false;
    }
}

//place a marker
string place_marker(string board, char marker, int position) {
    board[position - 1] = marker;
    return board;
}
// pick a marker
char pick_marker() {
    char marker = 'Y';
    while (marker != 'X' && marker != 'O') {
        cout << "Please pick a marker 'X' or 'O': ";
        cin >> marker;
    }
    return marker;
}
//draw board
void display_board(string board) {
    std::cout << '\n' << board[0] << ' ' << board[1] << ' ' << board[2];
    std::cout << '\n' << board[3] << ' ' << board[4] << ' ' << board[5];
    std::cout << '\n' << board[6] << ' ' << board[7] << ' ' << board[8] << '\n';
}