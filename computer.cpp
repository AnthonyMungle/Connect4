//
// Created by Anthony on 2/20/2020.
//
#include <string>
#include <vector>
#include "computer.hpp"

Computer::Computer() {

}
void Computer::updateBoard(std::vector <std::vector<std::string>> vector) {
    this->board = vector;
}
