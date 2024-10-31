//
// Created by milleraa on 10/28/2024.
//

#include "View.h"
#include <iostream>

std::string toYellow(int number);

View::View(std::string symbol1, std::string symbol2) {
  this->symbol1 = symbol1;
  this->symbol2 = symbol2;
}

char View::getInput() {
  std::string input;
  std::cout << "Where would you like to go?\n > ";
  std::cin >> input;
  return std::tolower(input.at(0));
}

void View::show(int (*board)[3], int turn) {
  bool done = turn == 0;
  if (!done) {
    std::string turnString = symbol1;
    if (turn == 2) turnString = symbol2;
    std::cout << "Player " << turn  << " (" << turnString << ") turn." << std::endl;
  }
  for (int i = 0; i < 3; ++i) {
    std::cout << "   ";
    for (int j = 0; j < 3; ++j) {
      std::string current = std::to_string(board[i][j]);
      if (current == "0") {
        if (done) current = " ";
        else current =  toYellow(3 * i + j + 1);
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
      std::cout << std::endl << "   ═══╬═══╬═══";
    }
    std::cout << std::endl;
  }
}

void View::showWinner(const int winner) {
  if (winner == 0) {
    std::cout << "Game ended in a tie." << std::endl;
  } else {
    std::string winnerText = symbol1;
    if (winner == 2) winnerText = symbol2;
    std::cout << "Player " << winner << " (" << winnerText << ") wins." << std::endl;
  }
}

void View::showHelp() {
  std::cout << "\nWelcome to tic-tac-toe!" << std::endl <<
    "Player 1 is " << symbol1 << ", and Player 2 is " << symbol2 << "." <<
    std::endl << "The board is full of numbers " << toYellow(1)
    << "-" << toYellow(9) << "," << std::endl <<
    "simply choose a number to place your piece there.\n" << std::endl;
}

std::string toYellow(const int number) {
  return "\033[38:5:11m" + std::to_string(number) + "\033[0m";
}