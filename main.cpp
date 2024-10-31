#include "Controller.h"
#include "View.h"

int main() {
    std::string symbol1 = "\033[38:5:10mX\033[0m";
    std::string symbol2 = "\033[38:5:12mO\033[0m";
    int turns = 0;
    View view = View(symbol1, symbol2);
    Board board = Board();
    Controller controller = Controller(&board);

    view.showHelp();
    bool gameRunning = true;
    while (gameRunning) {
        view.show(board.getBoard(), controller.getTurn());
        char playerInput = view.getInput();
        if (playerInput == 'q') {
            gameRunning = false;
        } else if (playerInput == 'h') {
            view.showHelp();
        } else {
            if(controller.updateBoard(playerInput)) turns ++;
            gameRunning = !controller.checkWin() && turns < 9;
        }
    }
    view.showWinner(board.getWinner());
    view.show(board.getBoard(), 0);
    return 0;
}