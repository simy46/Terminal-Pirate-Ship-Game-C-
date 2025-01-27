#include "game.h"
#include "display.h"


Game::Game() : currentCabin_("deck"), ship_(Ship()), exit_(false) {}

void Game::verifyCommand(const std::string& command) {
    if (command.size() == 1) {
        const auto& links = ship_.getCabinLinks(currentCabin_);
        auto it = links.find(command);
        if (it != links.end()) {
            currentCabin_ = it->second;
            std::cout << "Going " << Display::getDirectionName(command) << "..." << std::endl;
        }
        else if (command == "C") {
            Display::displayCommand();
        }
        else {
            std::cout << "Cannot go there." << std::endl;
        }
    }
    else if (command == "look") {
        std::cout << "You are in " << ship_.getCabin(currentCabin_).getName() << std::endl;
        std::cout << "The description of this cabin is: " << ship_.getCabin(currentCabin_).getDescription() << std::endl;

        // Display objects in the room
        Display::displayObjects(ship_.getCabin(currentCabin_));
    }
    else if (command == "use") {
        // Handle using an object
        std::cout << "What do you want to use? ";
        std::string objectKeyword;
        std::cin >> objectKeyword;
        interactWithObject(ship_.getCabin(currentCabin_), objectKeyword);
    }
    else if (command == "exit") {
        std::cout << "Going to deliver Binks Sake!\n";
        std::cout << "Lets all sing it with a Don! A song of the waves\n";
        std::cout << "Doesnt matter who you are, Someday youll just be bones\n";
        std::cout << "Never - Ending, Ever - wandering, Our funny Traveling tale!\n";
        exit_ = true;
    }
    else {
        std::cout << "Command not found." << std::endl;
    }
}
void Game::startGame() {
    Display::showBanner();
    Display::displayCommand();

    while (!exit_) {
        Display::showGameState(ship_.getCabin(currentCabin_));

        const auto& links = ship_.getCabinLinks(currentCabin_);
        Display::displayLinks(links, ship_);

        Cabin& currentCabin = ship_.getCabin(currentCabin_);

        Display::displayObjects(currentCabin);

        Display::showCommandPrompt();
        std::string command;
        std::cin >> command;

        verifyCommand(command);
    }
}

void Game::interactWithObject(const Cabin& cabin, const std::string& objectKeyword) {
    const Object* foundObject = cabin.findObject(objectKeyword);
    if (foundObject) {
        std::cout << "You interact with " << foundObject->getName() << " : " << foundObject->getDescription() << std::endl;

        const auto& linkedObjects = ship_.getCabinLinks(cabin.getName());
        auto linkedObjectIt = linkedObjects.find(foundObject->getName());
        if (linkedObjectIt != linkedObjects.end()) {
            currentCabin_ = linkedObjectIt->second;
            std::cout << "You discover a new area : " << currentCabin_ << std::endl;
        }
    }
    else {
        std::cout << "Object not found." << std::endl;
    }
}
