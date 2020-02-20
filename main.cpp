#include <iostream>
#include "board.hpp"


int main() {
    char newGame = 'Y';
    int amountOfSquare;
    int Player = 1; //will be used to compare turns with computer
    int choice;

    while(newGame ='Y') {
        std::cout<<"Welcome to Connect Four?"<<std::endl;
        std::cout<<"Your name will be Player1 Please select how many squares your game will consist of" << std::endl;
        std::cin >> amountOfSquare;
        Board game(amountOfSquare);
        std::cout<<game.ShowBoard();

    do {
            std::cout << " Player" << game.getPlayerTurn() << " Turn Select a row to place your symbol." << std::endl;
            std::cin >> choice;
            game.updateBoard(choice);
            std::cout << game.ShowBoard();
    } while (game.hasWon() == false);
        std::cout << "Congratulations Player" << game.getPlayerTurn() << " has Won!" << std::endl;
        std::cout<<"Would you like to play again? Y/N "<<std::endl;
        std::cin>>newGame;
}
    /*game.updateBoard(4);
    std::cout<<game.ShowBoard();
    game.updateBoard(4);
    std::cout<<game.ShowBoard();
    game.updateBoard(4);
    std::cout<<game.ShowBoard();
    game.updateBoard(2);
    game.updateBoard(2);
    game.updateBoard(2);
    std::cout<<game.ShowBoard();
   game.updateBoard(1);
    std::cout<<game.ShowBoard();
    game.updateBoard(4);
    std::cout<<game.ShowBoard();

    game.updateBoard(4);
    std::cout<<game.ShowBoard();

    game.updateBoard(4);
    std::cout<<game.ShowBoard();

    game.updateBoard(4);
    std::cout<<game.ShowBoard();*/
}