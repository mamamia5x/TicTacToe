//
// Created by milleraa on 10/28/2024.
//

#include "Board.h"
int getI(int cell);
int getJ(int cell);

int (*Board::getBoard())[3] {
  return board;
}

int Board::getValue(int cell) {
  return board[getI(cell)][getJ(cell)];
}

bool Board::setValue(int cell, int value) {
  if (getValue(cell) == 0) {
    board[getI(cell)][getJ(cell)] = value;
    return true;
  }
  return false;
}

int getI(int cell) {
  return (cell - 1) / 3;
}

int getJ(int cell) {
  return (cell - 1) % 3;
}