//
// Created by Anthony on 1/30/2020.
//
#include <iostream>
#include "board.hpp"




Board::Board(int blocks) {
    this->blocks = blocks;
    this->board.resize(blocks, std::vector<std::string>(blocks, "[ ]"));
    playerTurn = 1;


}

std::string Board::ShowBoard() {
    std::string stringBoard;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            stringBoard.append(board[i][j]);
        }
        stringBoard.append("\n");
    }

    return stringBoard;
}

void Board::updateBoard(char rowToDrop) {
    bool playerTurnOver = false;
    if(playerTurn== 1) {
        this->truePlayer = this->playerOne;
    }else{
        this->truePlayer = this->playerTwo;
    }
    while(playerTurnOver == false){

        if (isValidMove(rowToDrop)) {
            int row = rowToDrop - 1;

            for (int i = blocks - 1; i >= 0; i--) {
                for (int j = blocks - 1; j >= 0; j--) {

                    if (j == row && (board[i][j] != playerOne && board[i][j] != playerTwo )) {
                        board[i][j] = truePlayer;
                        playerTurnOver = true;
                        //Swaps turns
                        if(playerTurn == 1 && !hasWon()){
                            playerTurn = 2;
                        }else(playerTurn = 1);

                        return;
                    }


                }
            }
        } else {
            do{
            std::cout << "Invalid move. Please make a different move!" << std::endl;
            std::cin >> rowToDrop;
            }while(isValidMove(rowToDrop == false));

        }
    }

}

bool Board::isValidMove(char rowToMove) {
    int amountInRow = 0;
    bool isCorrectMove = true;
    if(rowToMove > blocks) {
        isCorrectMove = false;
    }
    if(rowToMove <= 0) {
        isCorrectMove = false;
    }

    int row = rowToMove -1;

    for (int i = blocks -1 ; i >= 0; i--) {
        for (int j = blocks -1; j >= 0; j--) {

            if (j == row && (board[i][j] != "[ ]")) {
                amountInRow ++;
            }

        }
    }
    if(amountInRow == blocks){
        isCorrectMove = false;
    }

    return isCorrectMove;
}

int Board::getPlayerTurn() {
    return playerTurn;
}

bool Board::hasWon() {

    //Need winning statement return false for now.
    for (int i = blocks - 1; i >= 0; i--) {

        for (int j = blocks - 1; j >= 0; j--) {
        }

        }

    return false;
}