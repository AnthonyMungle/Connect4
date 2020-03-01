
#include<bits/stdc++.h>
#include "board.hpp"

Board::Board(){
    this->row = Max_Row;
    this->col = Max_Col;
}
//prints the Board to the screen with every move
void Board::printBoard(int boardArray[Max_Row][Max_Col]){
    char boardPieces;

    //Space in between next board
    std::cout<<std::endl;
    for (int i = 1; i <= row-1; ++i){
        for (int j = 1; j <= col-1; ++j)
        {	if(boardArray[i][j] == 0)
                boardPieces = nothing;
            if(boardArray[i][j] == 1)
                boardPieces = o;
            if(boardArray[i][j] == 2)
                boardPieces = x;
            std::cout<<" [ "<< boardPieces;
        }
        std::cout<<" ] "<<std::endl;
    }
    std::cout<<"   1   2   3   4   5   6   7"<<std::endl;
}
int Board::getMaxRow(){
    return row;
}
int Board::getMaxCol(){
    return col;
}

int Board::currentMoveScore(int arrayBoard[Max_Row][Max_Col]){

    //score for win for max basically
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            //if(i == rowDrop && j== colDrop) {
            if (j + 3 < col && arrayBoard[i][j] == arrayBoard[i][j + 1] && arrayBoard[i][j] == arrayBoard[i][j + 2] &&
                arrayBoard[i][j] == arrayBoard[i][j + 3] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerTwo)
                return 500;
            if (i + 3 < row && arrayBoard[i][j] == arrayBoard[i + 1][j] && arrayBoard[i][j] == arrayBoard[i + 2][j] &&
                arrayBoard[i][j] == arrayBoard[i + 3][j] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerTwo)
                return 500;
            if (j + 3 < col && i - 3 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j + 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j + 2] && arrayBoard[i][j] == arrayBoard[i - 3][j + 3] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerTwo)
                return 500;
            if (j - 3 > 0 && i - 3 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j - 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j - 2] && arrayBoard[i][j] == arrayBoard[i - 3][j - 3] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerTwo)
                return 500;
        }
    }
    //score for player win
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            if (i + 3 < row && arrayBoard[i][j] == arrayBoard[i + 1][j] && arrayBoard[i][j] == arrayBoard[i + 2][j] &&
                arrayBoard[i][j] == arrayBoard[i + 3][j] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerOne)
                return -500;
            if (j - 3 > 0 && i - 3 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j - 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j - 2] && arrayBoard[i][j] == arrayBoard[i - 3][j - 3] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerOne)
                return -500;
            if (j + 3 < col && arrayBoard[i][j] == arrayBoard[i][j + 1] && arrayBoard[i][j] == arrayBoard[i][j + 2] &&
                arrayBoard[i][j] == arrayBoard[i][j + 3] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerOne)
                return -500;
            if (j + 3 < col && i - 3 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j + 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j + 2] && arrayBoard[i][j] == arrayBoard[i - 3][j + 3] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerOne)
                return -500;

        }
    }
    //Check for 3 in row with max player
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            if (i + 2 < row && arrayBoard[i][j] == arrayBoard[i + 1][j] && arrayBoard[i][j] == arrayBoard[i + 2][j] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerTwo) {
                if (i - 1 > 0 && arrayBoard[i - 1][j] == 0) {
                    return 300;
                }
                if (i + 3 < row && arrayBoard[i + 3][j] == 0) {
                    return 300;
                } else
                    return 300;
            }
            if (j + 2 < col && arrayBoard[i][j] == arrayBoard[i][j + 1] &&
                arrayBoard[i][j + 1] == arrayBoard[i][j + 2] &&
                arrayBoard[i][j] != 0 && arrayBoard[i][j] == playerTwo) {
                if (j - 1 > 0 && arrayBoard[i][j - 1] == 0) {
                    return 300;
                }
                if (j + 3 < col && arrayBoard[i][j + 3] == 0) {
                    return 300;
                } else
                    return 300;
            }

            if (i - 2 > 0 && j - 2 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j - 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j - 2] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerTwo) {
                if (i + 1 < row && j + 1 < col && arrayBoard[i + 1][j + 1] == 0) {
                    return 300;
                }
                if (i - 3 > 0 && j - 3 > 0 && arrayBoard[i - 3][j - 3] == 0) {
                    return 300;
                } else
                    return 270;
            }

            if (i - 2 > 0 && j + 2 < col && arrayBoard[i][j] == arrayBoard[i - 1][j + 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j + 2] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerTwo) {
                if (i - 3 > 0 && j + 3 < col && arrayBoard[i - 3][j + 3] == 0) {
                    return 300;
                }
                if (i + 1 < row && j - 1 > 0 && arrayBoard[i + 1][j - 1] == 0) {
                    return 300;
                } else
                    return 270;
            }

        }
    }

//Score for player min for 3 in a row
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (j + 2 < col && arrayBoard[i][j] == arrayBoard[i][j + 1] &&
                arrayBoard[i][j + 1] == arrayBoard[i][j + 2] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerOne) {
                if (j - 1 > 0 && arrayBoard[i][j - 1] == 0) {
                    return -300;
                }
                if (j + 3 < col && arrayBoard[i][j + 3] == 0) {
                    return -300;
                } else
                    return -270;
            }

            if (i + 2 < row && arrayBoard[i][j] == arrayBoard[i + 1][j] && arrayBoard[i][j] == arrayBoard[i + 2][j] &&
                arrayBoard[i][j] != 0 &&arrayBoard[i][j] == playerOne) {
                if (i - 1 > 0 && arrayBoard[i - 1][j] == 0) {
                    return -300;
                }
                if (i + 3 < row && arrayBoard[i + 3][j] == 0) {
                    return -300;
                } else
                    return -270;
            }
            if (i - 2 > 0 && j + 2 < col && arrayBoard[i][j] == arrayBoard[i - 1][j + 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j + 2] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerOne) {
                if (i - 3 > 0 && j + 3 < col && arrayBoard[i - 3][j + 3] == 0) {

                    return -300;
                }
                if (i + 1 < row && j - 1 > 0 && arrayBoard[i + 1][j - 1] == 0) {
                    return -300;
                } else
                    return -270;
            }
            if (i - 2 > 0 && j - 2 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j - 1] &&
                arrayBoard[i][j] == arrayBoard[i - 2][j - 2] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerOne) {
                if (i + 1 < row && j + 1 < col && arrayBoard[i + 1][j + 1] == 0) {
                    return -300;
                }
                if (i - 3 > 0 && j - 3 > 0 && arrayBoard[i - 3][j - 3] == 0) {
                    return -300;
                } else
                    return -270;
            }
        }
    }
    //Checks currentGameScore for two in row max player
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            if (i - 1 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j + 1] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerTwo)
                return 200;
            if (i - 1 > 0 && j - 1 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j - 1] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerTwo)
                return 200;
            if (j + 1 < col && arrayBoard[i][j] == arrayBoard[i][j + 1] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == 0)
                return 200;
            if (i + 1 < row && arrayBoard[i][j] == arrayBoard[i + 1][j] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerTwo)
                return 200;

        }
    }
    //Score for min PLayer getting two in row
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            if (i - 1 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j + 1] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerOne)
                return -200;
            if (i - 1 > 0 && j - 1 > 0 && arrayBoard[i][j] == arrayBoard[i - 1][j - 1] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerOne)
                return -200;
            if (j + 1 < row && arrayBoard[i][j] == arrayBoard[i][j + 1] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == 0)
                return -200;
            if (i + 1 < row && arrayBoard[i][j] == arrayBoard[i + 1][j] && arrayBoard[i][j] != 0 &&
                arrayBoard[i][j] == playerOne)
                return -200;
        }
    }
    return 0;
}

//Needed to make temporary moves for scoring
void Board::copyArray(int boardArray[Max_Row][Max_Col], int tempArray[Max_Row][Max_Col]){
    for (int i = 1; i <= row-1; ++i){
        for (int j = 1; j <= col-1; ++j){
            tempArray[i][j] = boardArray[i][j];
        }
    }
}

int Board::hasWon(int boardArray[Max_Row][Max_Col]){

    for (int j = 1; j <= col-1; ++j){
        for (int i = 1; i <= row-4; ++i){
            if(boardArray[i][j] == boardArray[i+1][j] && boardArray[i][j] == boardArray[i+2][j] && boardArray[i][j] == boardArray[i+3][j] && boardArray[i][j] != 0 ) {
                return 1;
            }
        }
    }
    for (int i = row-1; i >= row-4; --i){
        for (int j = col-1; j >= col -4; --j){
            if( boardArray[i][j] == boardArray[i-1][j-1] && boardArray[i][j] == boardArray[i-2][j-2] && boardArray[i][j] == boardArray[i-3][j-3] && boardArray[i][j] !=0 ){
                return 1;
            }

        }
    }
    for (int i = row-1; i >= row-3; --i){
        for (int j = 1; j <= col-4; ++j){
            if(boardArray[i][j] == boardArray[i-1][j+1] && boardArray[i][j] == boardArray[i-2][j+2] && boardArray[i][j] == boardArray[i-3][j+3] && boardArray[i][j] !=0 ) {
                return 1;
            }
        }
    }
    for (int i = 1; i <= row-1; ++i){
        for (int j = 1; j <= col-4; ++j){
            if(boardArray[i][j] == boardArray[i][j+1] && boardArray[i][j+1] == boardArray[i][j+2] && boardArray[i][j] == boardArray[i][j+3] && boardArray[i][j] != 0 ) {
                return 1;
            }
        }
    }
    return 0;
}
//updates the board based on who just went
void Board::MakeTurn(int gameArray[Max_Row][Max_Col], int col, int turn)
{	//cout<<"hi"
    for (int i = row-1; i >= 1; --i){
        if(gameArray[i][col] == 0){
            if(turn % 2 == 0){
                gameArray[i][col] = 1;
                break;
            }
            else{
                gameArray[i][col] = 2;
                break;
            }
        }
    }
}

//called from main starts the min max recursion until the selected depth is 0
//Prunes worse max inputs in order to not waste time searching
int Board::computerDecision(int boardArray[Max_Row][Max_Col],int depth){

    int max=-1000000;
    int point = -1; //if Returned at -1 ends game in draw
    int tempArray[Max_Row][Max_Col];
    for (int i = 1; i <= row; ++i){
        if(boardArray[1][i] == 0){
            copyArray(boardArray, tempArray);
            MakeTurn(tempArray, i, 1);
            if (minPlayer(tempArray, depth-1) + currentMoveScore(tempArray) >= max){ //this ensures the only thing chosen or searched is a better max (prune)
                //std::cout<<minPlayer(tempArray, depth-1);
                if(minPlayer(tempArray, depth-1) + currentMoveScore(tempArray) == max){
                    if(rand()%2 == 1) {
                        point = i;
                    }
                }
                else{
                    point = i;
                    max = minPlayer(tempArray, depth-1) +currentMoveScore(tempArray);
                }
            }
        }
    }
    return point;
}

//trying for the minimum on the next board uses depth to search future outcomes once runs out the best score is chosen
int Board::minPlayer(int boardArray[Max_Row][Max_Col],int depth){
    int minimum=1000000;

    if(hasWon(boardArray) == 1) {
        return currentMoveScore(boardArray) + depth * 250;
        //std::cout<<currentGameScore(boardArray);
    }
    if(depth == 0) {
        return currentMoveScore(boardArray);
    }
    int tempArray[Max_Row][Max_Col];
    for (int i = 1; i <= row; ++i){
        if(boardArray[1][i] == 0){
            copyArray(boardArray, tempArray);
            MakeTurn(tempArray, i, 2);
            if(computer_turn( tempArray, depth - 1) < minimum){
                minimum = computer_turn(tempArray, depth - 1);
            }
        }
    }
    return minimum;
}

//Trying for the maximum after depth runs out decision is made
//Ensures best max is chosen
int Board::computer_turn(int boardArray[Max_Row][Max_Col], int depth){
    int maximum=-1000000;

    if(hasWon(boardArray) == 1) {
        return currentMoveScore(boardArray) - depth * 250;
    }
    if (depth ==  0){
        return currentMoveScore(boardArray);
    }
    int tempArray[Max_Row][Max_Col];
    for (int i = 1; i <= row; ++i){
        if(boardArray[1][i] == 0){
            copyArray(boardArray, tempArray);
            MakeTurn(tempArray, i, 1);
            //print(tempArray);
            if (minPlayer(tempArray, depth - 1 )> maximum){
                maximum = minPlayer(tempArray, depth - 1);
            }
        }
    }
    return maximum;
}




