#pragma once
#include <iomanip>
#include <iostream>
#include "ship.h"

class Game {
public:
    Game();

    void startGame();
    void interactWithObject(const Cabin& cabin, const std::string& objectKeyword);

private:

    void verifyCommand(const std::string& command);

    Ship ship_;

    bool exit_;

    std::unordered_map<std::string, Cabin> cabins_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> cabinlinks_;
    std::string currentCabin_;
};
