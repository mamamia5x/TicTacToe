//
// Created by milleraa on 10/28/2024.
//

#include "Controller.h"

Controller::Controller(Board* board, std::string symbol1, std::string symbol2) {
  this->symbol1 = symbol1;
  this->symbol2 = symbol2;
  playerTurn = 1;
  this->board = board;
}

bool Controller::updateBoard(char input) {
  if (!isdigit(input)) return false;
  int number = input - '0';
  int value = board->getValue(number);
  if (value == 0) {
    board -> setValue(number, playerTurn);
    changeTurn();
    return true;
  }
  return false;
}

void Controller::changeTurn() {
  playerTurn ++;
  if (playerTurn > 2) {
    playerTurn = 1;
  }
}

int Controller::getTurn() {
  return playerTurn;
}

int getFirst(int x) {
  // From https://www.desmos.com/calculator/zmfinud3y4
  return x / 4 + 1 + x / 5 + x / 7 + 2 * (x / 8);
}
int getSecond(int x) {
  // From https://www.desmos.com/calculator/zmfinud3y4
  return 2 * x - x / 3 - 2 * (x / 4) - 2 * (x / 5) - 3 * (x / 7) + 3 * (x / 8);
}
int getThird(int x) {
  // From https://www.desmos.com/calculator/zmfinud3y4
  return 3 * x + x / 2 - x / 3 - 5 * (x / 4) - 4 * (x / 5) - x / 6 - 6 * (x / 7) + 4 * (x / 8);
}

bool Controller::checkWin() {
  for (int i = 1; i <= 8; i ++) {
    int first = board->getValue(getFirst(i));
    if (first != 0) {
      int second = board->getValue(getSecond(i));
      int third = board->getValue(getThird(i));
      if (first == second && second == third) {
        return true;
      }
    }
  }
  return false;
}
