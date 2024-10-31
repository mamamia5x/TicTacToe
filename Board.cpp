//
// Created by milleraa on 10/28/2024.
//

#include "Board.h"
int getI(int cell);
int getJ(int cell);

int (*Board::getBoard())[3] {
  return board;
}

int Board::getValue(const int cell) const {
  return board[getI(cell)][getJ(cell)];
}

bool Board::setValue(const int cell, const int value) {
  if (getValue(cell) == 0) {
    board[getI(cell)][getJ(cell)] = value;
    return true;
  }
  return false;
}

void Board::calcWin(const int piece) {
  win = piece;
}

int Board::getWinner() const {
  return win;
}



int getI(const int cell) {
  return (cell - 1) / 3;
}

int getJ(const int cell) {
  return (cell - 1) % 3;
}