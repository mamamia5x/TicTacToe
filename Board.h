//
// Created by milleraa on 10/28/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <string>


class Board {
public:
    bool playMove(int row, int col, int symbol);
    bool calcWin();

    int (*getBoard())[3];
    int getValue(int cell);
    bool setValue(int cell, int value);
private:
    int board[3][3];
};



#endif //BOARD_H
