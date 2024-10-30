#include <iostream>

#include "Controller.h"
#include "View.h"

int main() {
    static const std::string symbol1 = "X";
    static const std::string symbol2 = "O";
    View view = View(symbol1, symbol2);
    Board board = Board();
    Controller controller = Controller(&board, symbol1, symbol2);

    // controller.startGame();
    bool gameRunning = true;
    while (gameRunning) {
        view.show(board.getBoard(), controller.getTurn());
        char playerInput = view.getInput();
        if (playerInput == 'q') {
            gameRunning = false;
        } else {
            controller.updateBoard(playerInput);
            gameRunning = !controller.checkWin();
        }
    }
    view.show(board.getBoard(), 0);
    // view.endGame();
    return 0;
}