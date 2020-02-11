//
// Created by Anthony on 2/4/2020.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {

private:
    std::string playerName;
    bool isComputer;
public:
    Player(std::string name, bool isComputer);
    std::string getName();
    bool hasPlayerWon();
    bool getisComputer();
};
#endif //PLAYER_HPP
