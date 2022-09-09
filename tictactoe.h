#pragma once

#include <iostream>
#include <cstring>

using std::cout;

// Tic tac toe class 
class TicTacToe {
 private:
  char board[3][3]; 
  int matchResults[3]; // x, o, draw
  const uint8_t boardCheckPositions[8][3][2] = { // For checking for game wins 
    { { 0, 0 }, { 1, 1 }, { 2, 2 } },
    { { 0, 2 }, { 1, 1 }, { 2, 0 } },
    { { 0, 0 }, { 0, 1 }, { 0, 2 } },
    { { 1, 0 }, { 1, 1 }, { 1, 2 } },
    { { 2, 0 }, { 2, 1 }, { 2, 2 } },
    { { 0, 0 }, { 1, 0 }, { 2, 0 } },
    { { 0, 1 }, { 1, 1 }, { 2, 1 } },
    { { 0, 2 }, { 1, 2 }, { 2, 2 } }
  };
 public:

  // Class constructor
  TicTacToe() {
    clearBoard();
    memset(matchResults, 0, 12);
  }

  // Check if we can play there and then do that and return true, otherwise return false 
  bool setBoardSquare(char* s, bool t) {
    if (strlen(s) != 2) return false;
    s[0] = tolower(s[0]);
    if (s[0] >= 'a' && s[0] <= 'c' && s[1] >= '1' && s[1] <= '3') {
      char& c = board[s[0] - 'a'][s[1] - '1'];
      if (c == ' ') {
	c = t ? 'O' : 'X';
	return true;
      }
    }
    return false;
  }

  void clearBoard() {
    memset(board, ' ', 9);
  }
  
  void printBoard() {
    cout << "  1 2 3 \n";
    for (int i = 0; i < 3; i++) {
      cout << (char)('a' + i) << ' ';
      for (int j = 0; j < 3; j++) {
	cout << board[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  void printWinsAndDraws() {
    cout << "=======SCOREBOARD=======\n";
    cout << "X wins: " << matchResults[0] << "\nO wins: " << matchResults[1] << "\nDraws: " << matchResults[2] << '\n';
    cout << "========================\n";
  }
  
  // Check for wins and draws and print results if the game is over  
  bool checkGameState() {
    // Check win by checking each sequence in boardCheckPositions to see if all the squares are the same and equal to X or O 
    for (int i = 0; i < 8; i++) {
      if (board[boardCheckPositions[i][0][0]][boardCheckPositions[i][0][1]] != ' ' &&
	  board[boardCheckPositions[i][0][0]][boardCheckPositions[i][0][1]] == board[boardCheckPositions[i][1][0]][boardCheckPositions[i][1][1]] &&
	  board[boardCheckPositions[i][1][0]][boardCheckPositions[i][1][1]] == board[boardCheckPositions[i][2][0]][boardCheckPositions[i][2][1]]) {
	cout << board[boardCheckPositions[i][0][0]][boardCheckPositions[i][0][1]] << " won!\n";
        matchResults[(board[boardCheckPositions[i][0][0]][boardCheckPositions[i][0][1]] == 'X') ? 0 : 1]++;
	return false;
      }
    }
    // Check tie  
    int ct = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
	if (board[i][j] != ' ') ct++;
	else break;
      }
    }
    if (ct == 9) {
      cout << "Draw!\n";
      matchResults[2]++;
      return false;
    }
    
    return true;
  }
  
};
