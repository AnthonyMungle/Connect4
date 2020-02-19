//
// Created by Anthony on 1/30/2020.
//

#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>

class Board {

private:
    int columnChoice;
    int blocks;
    int playerTurn;
    std::string playerOne = "[x]";
    std::string playerTwo = "[O]";
    std::string truePlayer = "[ ]";
    std::vector<std::vector<std::string>> board;

public:
    Board(int blocks);
    std::string ShowBoard();
    int getPlayerTurn();
    void updateBoard(int numberOfRows);
    bool isValidMove(int rowToMove);
    bool hasWon();

};
#endif //BOARD_HPP
