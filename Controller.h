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
    Controller(Board* board, std::string symbol1, std::string symbol2);
    bool updateBoard(char input);
    bool checkWin();
    int getTurn();
private:
    Board* board;
    int playerTurn;
    std::string symbol1;
    std::string symbol2;
    void changeTurn();
};


#endif //CONTROLLER_H
