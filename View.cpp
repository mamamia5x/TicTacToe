//
// Created by milleraa on 10/28/2024.
//

#include "View.h"

#include <iostream>

View::View(std::string symbol1, std::string symbol2) {
  this->symbol1 = symbol1;
  this->symbol2 = symbol2;
}

char View::getInput() {
  std::string input;
  std::cin >> input;
  return std::tolower(input.at(0));
}

void View::show(int (*board)[3], int turn) {
  bool done = turn == 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::string current = std::to_string(board[i][j]);
      if (current == "0") {
        if (done) current = " ";
        else current = std::to_string(3 * i + j + 1);
      } else if (current == "1") {
        current = symbol1;
      } else if (current == "2") {
        current = symbol2;
      }
      std::cout << " " << current << " ";
      if (j != 2) {
        std::cout << "║";
      }
    }
    if (i != 2) {
      std::cout << std::endl << "═══╬═══╬═══";
    }
    std::cout << std::endl;
  }
  if (!done) {
    std::string turnString = symbol1;
    if (turn == 2) turnString = symbol2;
    std::cout << "Player " << turn  << " (" << turnString << ") turn." << std::endl;
  }
}