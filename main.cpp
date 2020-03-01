#include<bits/stdc++.h>

#include "board.hpp"
int main(){

    char playAgain ='y';
    while(playAgain == 'y') {

        Board game;
        int boardArray[7][8] = {0};//boardArray is the initial board
        int AiLevel; // Will be input by player is used to determine the depth of the computers choice also variety in moves
        int col; //will be input by the first player
        int turnNumber=0;//turn is the amount of turns taken will be compared with maxTurns to end the game if draw occurs
        int maxTurns=42;

        std::string playerName;
        std::cout<<"CONNECT FOUR"<<std::endl;
        std::cout<<"Please enter your name: ";
        std::cin>>playerName;


        std::cout << "Enter level of Agent 1-3: (level 3 needs time to think)";
        std::cin >> AiLevel;
        //minimum depth added to agent
        AiLevel = AiLevel + 3;
        //print the initial board;
        game.printBoard(boardArray);

        //plays as long as turns dont run out
        //checks if the value input is also valid
        while (turnNumber < maxTurns) {

            //Players turn determined by even number of turnsNumber
            if (turnNumber % 2 == 0) {
                std::cout << "player1 turn " << std::endl;
                std::cin >> col;
                if (col < 1 || col > game.getMaxCol() || boardArray[1][col] != 0) {
                    std::cout << "invalid input!" << std::endl;
                    continue;
                }
                game.MakeTurn(boardArray, col, turnNumber);

                //computers turn if choice == -1 then it becomes a draw
            } else {
                int choice;
                choice = game.computerDecision(boardArray, AiLevel);
                if (choice != -1) {
                    game.MakeTurn(boardArray, choice, 1);
                } else {
                    std::cout << "Game draw" << std::endl;
                    return 0;
                }
            }

            //prints the board every turn
            game.printBoard(boardArray);

            //checks for win using hasWon()
            if (game.hasWon(boardArray) == 1) {
                if (turnNumber % 2 == 0) {
                    std::cout << playerName << " wins" << std::endl;
                    break;
                } else {
                    std::cout << "Computer has won" << std::endl;
                    break;
                }
            }
            turnNumber = turnNumber + 1;
        }
        std::cout<<"Would you like to play again? y/n"<<std::endl;
        std::cin>>playAgain;
        std::cout<<std::endl;
    }
    return 0;
}