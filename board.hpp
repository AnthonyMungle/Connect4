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
    bool isComputer;
    bool playerTurnOver;
    std::string playerOne = "[x]";
    std::string playerTwo = "[O]";
    std::string truePlayer = "[ ]";
    std::vector<std::vector<std::string>> board;
    Computer computer = Computer(0);

public:
    Board(int blocks, char playVsComputer);
    std::string ShowBoard();
    //int getScore(std::vector<std::vector<std::string>> board;);
    int getPlayerTurn();
    void placePiece(int numberOfRows);
    bool isValidMove(int rowToMove);
    bool hasWon();
    bool isComputerPlaying();
    void computersTurn();
    void swapTurns();
    std::vector <std::vector<std::string>> getBoard();

};
#endif //BOARD_HPP
