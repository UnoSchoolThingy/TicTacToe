/* Uno Pasadhika 
 * Tic Tac Toe game 
 * 9/9/2022 
 */

#include "tictactoe.h"

using namespace std;

int main() {
  TicTacToe game;
  char in[5];
  cout << "Welcome to tic tac toe! To move, enter your coordinates as a letter and a number with no spaces (example: a1)\n"; 
  while (true) { // Play infinitely until the loop is broken
    bool turn = false; // false = X, true = O
    game.printBoard();
    do {
      cout << "Current turn: " << (turn ? 'O' : 'X') << "! Please enter your move coordinates: ";
      cin >> in;
      while (!game.setBoardSquare(in, turn)) { // Keep checking if input works 
	cout << "Oopsie, you can't go there! Please enter the coordinates: ";
	cin >> in;
      }
      game.printBoard();
      turn = !turn; // Make it the other player's turn 
    } while (game.checkGameState());
    game.clearBoard(); // Reset the board for next time 
    game.printWinsAndDraws(); // Print scoreboard
    // Ask the user if they want to play again 
    cout << "Would you like to play again? (y/n): ";
    char c;
    cin >> c;
    if (tolower(c) != 'y') break;
  }
  cout << "Thanks for playing!\n";
}
