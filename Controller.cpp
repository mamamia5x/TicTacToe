//
// Created by milleraa on 10/28/2024.
//

#include "Controller.h"

Controller::Controller(Board* board) {
  this->board = board;
}

bool Controller::updateBoard(const char input) {
  if (!isdigit(input)) return false;
  const int number = input - '0';
  if (number == 0) return false;
  if (board->getValue(number) == 0) {
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

int Controller::getTurn() const {
  return playerTurn;
}

int getFirst(const int x) {
  // From https://www.desmos.com/calculator/zmfinud3y4
  return x / 4 + 1 + x / 5 + x / 7 + 2 * (x / 8);
}
int getSecond(const int x) {
  // From https://www.desmos.com/calculator/zmfinud3y4
  return 2 * x - x / 3 - 2 * (x / 4) - 2 * (x / 5) - 3 * (x / 7) + 3 * (x / 8);
}
int getThird(const int x) {
  // From https://www.desmos.com/calculator/zmfinud3y4
  return 3 * x + x / 2 - x / 3 - 5 * (x / 4) - 4 * (x / 5) - x / 6 - 6 * (x / 7) + 4 * (x / 8);
}

bool Controller::checkWin() const {
  for (int i = 1; i <= 8; i ++) {
    int first = board->getValue(getFirst(i));
    if (first != 0) {
      int second = board->getValue(getSecond(i));
      int third = board->getValue(getThird(i));
      if (first == second && second == third) {
        board->calcWin(first);
        return true;
      }
    }
  }
  return false;
}
