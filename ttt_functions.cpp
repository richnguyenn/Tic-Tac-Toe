// Richard Nguyen
// Tic-Tac-Toe
// C++
// 2023/01/06 - 2023/01/07

#include <iostream>
using namespace std;

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void introduction() {
    cout << "Press [ENTER] to START!";
    cin.ignore();

    cout << "\n";

    cout << "=======================\n";
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "=======================\n";

    cout << "\n";

    cout << "Player 1 - 'X'\n";
    cout << "Player 2 - 'O'\n";

    cout << "\n";

    cout << "The 3x3 Board is given below:\n\n";

    cout << "     |     |      \n";
    cout << "  1  |  2  |  3   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  4  |  5  |  6   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  7  |  8  |  9   \n";
    cout << "     |     |      \n\n";

}

bool is_winner() {

    bool winner = false;

    //rows
    if (board[0] == board[1] && board[1] == board[2] && board[0] != " ") {
        winner = true;
    }
    else if (board[3] == board[4] && board[4] == board[5] && board[3] != " ") {
        winner = true;
    }
    else if (board[6] == board[7] && board[7] == board[8] && board[6] != " ") {
        winner = true;
    }

    //columns
    else if (board[0] == board[3] && board[3] == board[6] && board[0] != " ") {
        winner = true;
    }
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != " ") {
        winner = true;
    }
    else if (board[2] == board[5] && board[5] == board[8] && board[2] != " ") {
        winner = true;
    }

    //diagonal
    else if (board[0] == board[4] && board[4] == board[8] && board[0] != " ") {
        winner = true;
    }
    else if (board[2] == board[4] && board[4] == board[6] && board[2] != " ") {
        winner = true;
    }

    return winner;

}

bool filled_up() {

    bool filled = true;

    //check each square
    for (int i = 0; i < 9; i++) {
        if (board[i] == " ") {
            filled = false;
        }
    }

    return filled;

}



void set_position() {
    
    cout << "Player " << player << ", select a non-empty position on the board. (Enter 1-9)\n";

    while(!(cin >> position)) {
        cout << "Invalid position, please select a valid non-empty position (Enter 1-9)";
        std::cin.clear();
        std::cin.ignore();
    }
  
    std::cout << "\n";

    while (board[position-1] != " ") {
        cout << "That spot was already taken.\n";
        
        cout << "Player " << player << ", please enter a new position (Enter 1-9): ";
        cin >> position;
    }

}

void update_board() {

    if (player % 2 == 1) {
        board[position-1] = "X";
    }
    else {
        board[position-1] = "O";
    }

}

void change_player() {
    if (player == 1) {
        player++;
    }
    else {
        player--;
    }
}

void draw() {
 
    //board
    cout << "     |     |      \n";
 
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
 
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
 
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
 
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
 
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "     |     |      \n";
 
    cout << "\n";

}

void take_turn() {

  while ( !is_winner() && !filled_up() ) {
  
    set_position();

    update_board();

    change_player();

    draw();
  
  }

}

void end_game() {

    if (is_winner()) {
        if (player % 2 == 0) {
            cout << "Player " << player - 1 << " is the winner!";
        }
        else {
            cout << "Player " << player + 1<< " is the winner!";
        }
    }

    else if (filled_up()) {
        cout << "It is a draw.";
    }

}