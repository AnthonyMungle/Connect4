//
// Created by Anthony on 2/28/2020.
//

#ifndef UNTITLED5_BOARD_HPP
#define UNTITLED5_BOARD_HPP
class Board{

private:
    static const int Max_Row = 7;
    static const int Max_Col = 8;
    char x = 'x';
    char o = 'o';
    char nothing = ' ';
    //std::vector<std::vector<int>> board;
    bool isComputer;
    int playerOne = 1;
    int playerTwo = 2;
    int row;
    int col;

public:
    Board();
    bool isComputerTurn();
    void printBoard(int boardArray[7][8]);
    void copyArray(int boardArray[7][8], int tempArray[7][8]);
    void MakeTurn(int gameArray[7][8], int col, int turn);
    int computerDecision(int gameArray[7][8],int depth);
    int minPlayer(int gameArray[7][8],int depth);
    int computer_turn(int gameArray[7][8],int depth);
    int hasWon(int gameArray[7][8]);
    int currentMoveScore(int gameArray[7][8]);
    int getMaxRow();
    int getMaxCol();


};


#endif //UNTITLED5_BOARD_HPP
