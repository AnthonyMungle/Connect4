//
// Created by Anthony on 2/20/2020.
//
#include <string>
#include <vector>
#include <iostream>
#include "computer.hpp"

Computer::Computer(int size) {
        this->size = size;
        this->hieght = size;
        this->width = size;

}
void Computer::updateBoard(std::vector <std::vector<std::string>> vector){//, std::vector<int> validColumns) {
    this->board = vector;
    this->validColumns = validColumns;
}




int Computer::getColumnChoice(std::vector<std::vector<std::string>> newBoard, int depth) {

    int max=-100000000;
    int position = -1;
    std::vector<std::vector<std::string>> tempBoard;

    for (int i = 1; i <= this->size-1; ++i){
        if(newBoard[1][i] == "[ ]"){
            tempBoard = newBoard;
            tempBoard = makeTempVector(i);
            if (minPlayer(tempBoard, depth-1) + getScore(tempBoard) >= max){

                if(minPlayer(tempBoard, depth-1) + getScore(tempBoard) == max){
                    if(rand()%2 == 1) {
                        position = i;
                    }
                }
                else{
                    position = i;
                    max = minPlayer(tempBoard, depth-1) +getScore(tempBoard);
                }
            }
        }
    }
    return position;

}

int Computer::minPlayer(std::vector<std::vector<std::string>> tempBoard, int depth){

    int minimum=100000000;

    if(hasWon(tempBoard) == true) {
        return getScore(tempBoard) + depth * 250;
        //std::cout<<currentGameScore(boardArray);
    }
    if(depth == 0) {
        return getScore(tempBoard);
    }

    std::vector<std::vector<std::string>> newBoard;
    for (int i = 1; i <= this->size-1; ++i){
        if(tempBoard[1][i] == "[ ]"){
            newBoard = tempBoard;
            updateTempVector(newBoard, i, 1);//printBoard(tempArray);
            if(computer_turn(newBoard, depth - 1) < minimum){
                minimum = computer_turn(newBoard, depth - 1);
            }
        }
    }
    return minimum;
}

int Computer::computer_turn(std::vector<std::vector<std::string>> tempBoard, int depth){
    int maximum=-100000;
//true
    if(hasWon(tempBoard) == true) {
        return getScore(tempBoard) - depth * 250;
    }
    if (depth ==  0){
        return getScore(tempBoard);
    }
    std::vector<std::vector<std::string>> newBoard;
    for (int i = 1; i <= this->size-1; ++i){
        if(tempBoard[1][i] == "[ ]"){
            newBoard = tempBoard;
            updateTempVector(newBoard, i , 2);
            //print(temp);
            if (minPlayer(tempBoard, depth - 1 )> maximum){
                maximum = minPlayer(tempBoard, depth - 1);
            }
        }
    }
    return maximum;
}

std::vector<std::vector<std::string>> Computer::makeTempVector(int colChoice){
    tempVector = board;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1; j >= 0; j--) {
            if(j == colChoice -1 && tempVector[i][j] != playerOne && board[i][j] !=playerTwo){
                tempVector[i][j] = playerTwo;
                return tempVector;
            }
        }
    }
}



int Computer::getScore(std::vector<std::vector<std::string>> board) {


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            //if(i == rowDrop && j== colDrop) {
            if (j + 3 < size && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3] &&
                board[i][j] != "[ ]" && board[i][j] == playerTwo)
                return 5000;
            if (i + 3 < size && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j] && board[i][j] != "[ ]" &&
                board[i][j] == playerTwo)
                return 5000;
            if (j + 3 < size && i - 3 > 0 && board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3] &&
                board[i][j] != "[ ]" && board[i][j] == playerTwo)
                return 5000;
            if (j - 3 > 0 && i - 3 > 0 && board[i][j] == board[i - 1][j - 1] &&
                board[i][j] == board[i - 2][j - 2] && board[i][j] == board[i - 3][j - 3] &&
                board[i][j] != "[ ]" && board[i][j] == playerTwo)
                return 5000;
        }
    }

    //check for 3
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j + 2 < size && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] &&
                board[i][j] != "[ ]" &&
                board[i][j] == playerTwo) {
                if (j - 1 > 0 && board[i][j - 1] == "[ ]") {
                    return 1200;
                }
                if (j + 3 < size && board[i][j + 3] == "[ ]") {
                    return 1200;
                } else
                    return 1000;
            }

            if (i + 2 < size && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
                board[i][j] != "[ ]" &&
                board[i][j] == playerTwo) {
                if (i - 1 > 0 && board[i - 1][j] == "[ ]") {
                    return 1200;
                }
                if (i + 3 < size && board[i + 3][j] == "[ ]") {
                    return 1200;
                } else
                    return 1000;
            }
            if (i - 2 > 0 && j + 2 < size && board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] && board[i][j] != "[ ]" &&
                board[i][j] == playerTwo) {
                if (i - 3 > 0 && j + 3 < size && board[i - 3][j + 3] == "[ ]") {

                    return 1200;
                }
                if (i + 1 < size && j - 1 > 0 && board[i + 1][j - 1] == "[ ]") {
                    return 1200;
                } else
                    return 1000;
            }
            if (i - 2 > 0 && j - 2 > 0 && board[i][j] == board[i - 1][j - 1] &&
                board[i][j] == board[i - 2][j - 2] && board[i][j] != "[ ]" &&
                board[i][j] == playerTwo) {
                if (i + 1 < size && j + 1 < size && board[i + 1][j + 1] == "[ ]") {
                    return 1200;
                }
                if (i - 3 > 0 && j - 3 > 0 && board[i - 3][j - 3] == "[ ]") {
                    return 1200;
                } else
                    return 1000;
            }
        }
    }


    //Checks score for two in row
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j + 1 < size && board[i][j] == board[i][j + 1] && board[i][j] != "[ ]" && board[i][j] == "[ ]")
                return 250;
            if (i + 1 < size && board[i][j] == board[i + 1][j] && board[i][j] != "[ ]" && board[i][j] == playerTwo)
                return 250;
            if (i - 1 > 0 && board[i][j] == board[i - 1][j + 1] && board[i][j] != "[ ]" && board[i][j] == playerTwo)
                return 250;
            if (i - 1 > 0 && j - 1 > 0 && board[i][j] == board[i - 1][j - 1] && board[i][j] != "[ ]" &&
                board[i][j] == playerTwo)
                return 250;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j + 3 < size && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3] &&
                board[i][j] != "[ ]" && board[i][j] == playerOne)
                return -5000;
            if (i + 3 < size && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j] && board[i][j] != "[ ]" &&
                board[i][j] == playerOne)
                return -5000;
            if (j + 3 < size && i - 3 > 0 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] &&
                board[i][j] == board[i - 3][j + 3] &&
                board[i][j] != "[ ]" && board[i][j] == playerOne)
                return -5000;
            if (j - 3 > 0 && i - 3 > 0 && board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2] &&
                board[i][j] == board[i - 3][j - 3] &&
                board[i][j] != "[ ]" && board[i][j] == playerOne)
                return -5000;
        }
    }

//Score for player at 3
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j + 2 < size && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] &&
                board[i][j] != "[ ]" &&
                board[i][j] == playerOne) {
                if (j - 1 > 0 && board[i][j - 1] == "[ ]") {
                    return -1200;
                }
                if (j + 3 < size && board[i][j + 3] == "[ ]") {
                    return -1200;
                } else
                    return -1000;
            }

            if (i + 2 < size && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
                board[i][j] != "[ ]" &&
                board[i][j] == playerOne) {
                if (i - 1 > 0 && board[i - 1][j] == "[ ]") {
                    return -1200;
                }
                if (i + 3 < size && board[i + 3][j] == "[ ]") {
                    return -1200;
                } else
                    return -1000;
            }
            if (i - 2 > 0 && j + 2 < size && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] &&
                board[i][j] != "[ ]" &&
                board[i][j] == playerOne) {
                if (i - 3 > 0 && j + 3 < size && board[i - 3][j + 3] == "[ ]") {

                    return -1200;
                }
                if (i + 1 < size && j - 1 > 0 && board[i + 1][j - 1] == "[ ]") {
                    return -1200;
                } else
                    return -1000;
            }
            if (i - 2 > 0 && j - 2 > 0 && board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2] &&
                board[i][j] != "[ ]" &&
                board[i][j] == playerOne) {
                if (i + 1 < size && j + 1 < size && board[i + 1][j + 1] == "[ ]") {
                    return -1200;
                }
                if (i - 3 > 0 && j - 3 > 0 && board[i - 3][j - 3] == "[ ]") {
                    return -1200;
                } else
                    return -1000;
            }
        }
    }


    //Score for player at 2
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j + 1 < size && board[i][j] == board[i][j + 1] && board[i][j] != "[ ]" && board[i][j] == "[ ]")
                return -250;
            if (i + 1 < size && board[i][j] == board[i + 1][j] && board[i][j] != "[ ]" && board[i][j] == playerOne)
                return -250;
            if (i - 1 > 0 && board[i][j] == board[i - 1][j + 1] && board[i][j] != "[ ]" && board[i][j] == playerOne)
                return -250;
            if (i - 1 > 0 && j - 1 > 0 && board[i][j] == board[i - 1][j - 1] && board[i][j] != "[ ]" &&
                board[i][j] == playerOne)
                return -250;


        }
    }
        return 0;
}

void Computer::updateTempVector(std::vector<std::vector<std::string>> board, int col , int player){
    if(player == 1){
        truePlayer = "[o]";
    }
    else{
        truePlayer = "[x]";
    }
    col = col - 1;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = size - 1; j >= 0; j--) {

            if (j == col && (board[i][j] != playerOne && board[i][j] != playerTwo)) {
                board[i][j] = truePlayer;
            }
        }
    }
}

bool Computer::hasWon(std::vector<std::vector<std::string>> newBoard) {

    for (int i = 1; i <= size-1; ++i)
    {
        for (int j = 1; j <= size-4; ++j)
        {
            if(j + 3 <= size-4 && newBoard[i][j] == newBoard[i][j+1] && newBoard[i][j+1] == newBoard[i][j+2] && newBoard[i][j] == newBoard[i][j+3] && newBoard[i][j] != "[ ]" )
                return true;
        }
    }
    for (int j = 1; j <= size-1; ++j)
    {
        for (int i = 1; i <= size-4; ++i)
        {
            if(i + 3 <= size && newBoard[i][j] == newBoard[i+1][j] && newBoard[i][j] == newBoard[i+2][j] && newBoard[i][j] == newBoard[i+3][j] && newBoard[i][j] != "[ ]" )
                return true;
        }
    }
    for (int i = size-1; i >= size-3; --i)
    {
        for (int j = 1; j <= size-4; ++j)
        {
            if(i-3 >= 0 && j-3 >= 0 && newBoard[i][j] == newBoard[i-1][j+1] && newBoard[i][j] == newBoard[i-2][j+2] && newBoard[i][j] == newBoard[i-3][j+3] && newBoard[i][j] != "[ ]" )
                return true;
        }
    }
    for (int i = size-1; i >= size-4; --i)
    {for (int j = size-1; j >= size -4; --j){
            if(i-3 >0 && j-3 >0 && newBoard[i][j] == newBoard[i-1][j-1] && newBoard[i][j] == newBoard[i-2][j-2] && newBoard[i][j] == newBoard[i-3][j-3] && newBoard[i][j] != "[ ]" ){
                return true;
            }

        }
    }
    return 0;
}
