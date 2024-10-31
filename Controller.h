//
// Created by milleraa on 10/28/2024.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include "Board.h"
#include "Controller.h"


class Controller {
public:
    Controller(Board* board);
    bool updateBoard(char input);
    bool checkWin() const;
    int getTurn() const;
private:
    Board* board;
    int playerTurn = 1;
    void changeTurn();
};


#endif //CONTROLLER_H
