//
// Created by Anthony on 2/20/2020.
//

#ifndef CONNECT4_COMPUTER_HPP
#define CONNECT4_COMPUTER_HPP

#include <vector>

class Computer {

private:
    std::vector<std::vector<std::string>> board;

public:
    Computer();
    void updateBoard(std::vector<std::vector<std::string>> board);

};



#endif //CONNECT4_COMPUTER_HPP
