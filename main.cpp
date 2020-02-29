#include <iostream>
#include "board.hpp"


int main() {
    char newGame = 'y';
    char playVsComputer = 'n';
    int amountOfSquare;
    int choice;

    while (newGame == 'y') {
        std::cout << "Welcome to Connect Four?" << std::endl;
        std::cout << "Do you want to play vs computer? y/n" << std::endl;
        std::cin >> playVsComputer;
        std::cout << "Your name will be Player1 Please select how many squares your game will consist of" << std::endl;
        std::cin >> amountOfSquare;
        Board game(amountOfSquare, playVsComputer);
        std::cout << game.ShowBoard();

        do {

                std::cout << " Player" << game.getPlayerTurn() << " Turn Select a row to place your symbol."<< std::endl;
                if(game.isComputerPlaying() == false) {
                    std::cin >>choice;
                    game.placePiece(choice);
                }else{
                    if(game.getPlayerTurn() == 1){
                        std::cin >> choice;
                        game.placePiece(choice);
                    }else{
                        game.computersTurn();
                    }
                }

                std::cout << game.ShowBoard() << std::endl;

        } while (game.hasWon() == false);

        std::cout << "Congratulations Player" << game.getPlayerTurn() << " has Won!" << std::endl;
        std::cout << "Would you like to play again? y/n " << std::endl;
        std::cin >> newGame;
    }
}