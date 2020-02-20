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
    stringBoard.append(" ");
    for(int k = 1; k <= blocks; k++){

        stringBoard.append(std::to_string(k));
        stringBoard.append("  ");
    }
    stringBoard.append("\n");

    return stringBoard;
}

void Board::updateBoard(int rowToDrop) {
    bool playerTurnOver = false;
    if (playerTurn == 1) {
        this->truePlayer = this->playerOne;
    } else {
        this->truePlayer = this->playerTwo;
    }
    while (playerTurnOver == false) {

        if (isValidMove(rowToDrop)) {
            int row = rowToDrop - 1;

            for (int i = blocks - 1; i >= 0; i--) {
                for (int j = blocks - 1; j >= 0; j--) {

                    if (j == row && (board[i][j] != playerOne && board[i][j] != playerTwo)) {
                        board[i][j] = truePlayer;
                        this->rowChoice = i;
                        this->columnChoice = j;
                        playerTurnOver = true;
                        //Swaps turns
                        if(!hasWon()) {
                            if (playerTurn == 1) {
                                playerTurn = 2;
                            } else(playerTurn = 1);
                        }

                        return;
                    }


                }
            }
        } else {
            std::cout << "Invalid move!" << std::endl;
            std::cin >> rowToDrop;
            this->columnChoice = rowToDrop;
            do {
                if (isValidMove(rowToDrop)) {
                    playerTurnOver = true;
                } else {
                    std::cout << "Invalid move. Please make a different move!" << std::endl;
                    std::cin >> rowToDrop;
                    this->columnChoice = rowToDrop;
                }
            } while (playerTurnOver == false);

            int row = rowToDrop - 1;

            for (int i = blocks - 1; i >= 0; i--) {
                for (int j = blocks - 1; j >= 0; j--) {

                    if (j == row && (board[i][j] != playerOne && board[i][j] != playerTwo)) {
                        board[i][j] = truePlayer;
                        this->rowChoice = i;
                        this->columnChoice = j;
                        playerTurnOver = true;
                        //Swaps turns
                        if(!hasWon()) {
                            if (playerTurn == 1) {
                                playerTurn = 2;
                            } else(playerTurn = 1);
                        }

                        return;
                    }
                }
            }

        }
    }
}



bool Board::isValidMove(int rowToMove) {
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


    int i = rowChoice;
    int j = columnChoice;

                if ((j -3 >=0)&& (board[i][j] == truePlayer && board[i][j - 1] == truePlayer && board[i][j - 2] == truePlayer && //Win Right
                    board[i][j - 3] == truePlayer)) {
                    return true;
                }
                if ((j +3 <blocks)&& (board[i][j] == truePlayer && board[i][j + 1] == truePlayer && board[i][j + 2] == truePlayer && //Win Left
                    board[i][j + 3] == truePlayer)) {
                    return true;
                }
                if ((i+3 < blocks) && (board[i][j] == truePlayer && board[i+1][j] == truePlayer && board[i+2][j] == truePlayer && //Down...up is irrelevant
                    board[i+3][j] == truePlayer)) {
                    return true;
                }
                if ((i+3 < blocks)&& (j+3 < blocks) && (board[i][j] == truePlayer && board[i+1][j+1] == truePlayer && board[i+2][j+2] == truePlayer && // Diagonal down right
                    board[i+3][j+3] == truePlayer)) {
                    return true;
                }
                if ((i+3 < blocks)&& (j-3 >= 0) && (board[i][j] == truePlayer && board[i+1][j-1] == truePlayer && board[i+2][j-2] == truePlayer && // Diagonal down right
                     board[i+3][j-3] == truePlayer)) {
                    return true;
                }




    return false;
}

std::vector<std::vector<std::string>> Board::getBoard() {
    return board;
}