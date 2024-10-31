//
// Created by milleraa on 10/28/2024.
//

#ifndef VIEW_H
#define VIEW_H
#include <string>

class View {
public:
    View(std::string& symbol1, std::string& symbol2);
    char getInput();
    void show(const int (*board)[3], int turn) const;
    void showWinner(int winner) const;
    void showHelp();
private:
    std::string* symbol1;
    std::string* symbol2;
};


#endif //VIEW_H
