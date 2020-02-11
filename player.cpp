//
// Created by Anthony on 2/4/2020.
//

#include "player.hpp"

Player::Player(std::string name, bool isComputer){
    this->playerName = name;
    this->isComputer = isComputer;
}

std::string Player::getName(){
    return playerName;
}

bool Player::getisComputer(){
    return isComputer;
}

