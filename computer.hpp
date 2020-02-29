//
// Created by Anthony on 2/20/2020.
//

#ifndef CONNECT4_COMPUTER_HPP
#define CONNECT4_COMPUTER_HPP

#include <vector>

class Computer {

private:
    std::vector<std::vector<std::string>> board;
    std::vector<std::vector<std::string>> tempVector;
    std::vector<int> validColumns;
    std::string playerOne = "[x]";
    std::string playerTwo = "[O]";
    std::string truePlayer = "[ ]";
    int rowDrop;
    int colDrop;
    int computerScore;
    int size;
    int width;
    int hieght;

public:
    Computer(int size);
    int getScore(std::vector<std::vector<std::string>> board);
    int getColumnChoice(std::vector<std::vector<std::string>> newBoard, int depth);
    int minPlayer(std::vector<std::vector<std::string>> board, int depth);
    int computer_turn(std::vector<std::vector<std::string>> board, int depth);
    void updateBoard(std::vector<std::vector<std::string>> board);//, std::vector<int> validColumn);
    void updateTempVector(std::vector<std::vector<std::string>> board, int col, int player);
    std::vector<std::vector<std::string>> makeTempVector(int colChoice);
    bool hasWon(std::vector<std::vector<std::string>> newBoard);
};



#endif //CONNECT4_COMPUTER_HPP
