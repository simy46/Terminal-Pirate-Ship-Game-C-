#pragma once
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "ship.h"

class Display {
private:

    

public:
    static void showBanner();

    static void showGameState(const Cabin& cabin);

    static void showCommandPrompt();

    static void displayCommand();

    static void displayLinks(const std::unordered_map<std::string, std::string>& links�, Ship& ship);
    
    static void displayObjects(const Cabin& cabin);

    static std::string getDirectionName(const std::string& direction);
};

