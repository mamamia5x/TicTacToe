//
// Created by milleraa on 10/28/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <string>


class Board {
public:
    void calcWin(int piece);
    int (*getBoard())[3];
    int getValue(int cell);
    int getWinner();
    bool setValue(int cell, int value);
private:
    int board[3][3];
    int win = 0;
};



#endif //BOARD_H
