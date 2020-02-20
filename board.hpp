//
// Created by Anthony on 1/30/2020.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
#include "computer.hpp"

class Board {

private:
    int columnChoice;
    int rowChoice;
    int blocks;
    int playerTurn;
    std::string playerOne = "[x]";
    std::string playerTwo = "[O]";
    std::string truePlayer = "[ ]";
    std::vector<std::vector<std::string>> board;
    Computer computer;

public:
    Board(int blocks);
    std::string ShowBoard();
    int getPlayerTurn();
    void updateBoard(int numberOfRows);
    bool isValidMove(int rowToMove);
    bool hasWon();
    std::vector <std::vector<std::string>> getBoard();

};
#endif //BOARD_HPP
