#include <vector>
#include "Ship.h"


Ship::Ship() {
    createShip();
    createObjects();
};

void Ship::createShip() {
    cabins_["deck"] = Cabin("The Deck", "Welcome aboard, me heartie! This be the startin' point of yer grand adventure.");
    cabins_["captainsQuarters"] = Cabin("Captain's Quarters", "This be where the captain plots his course and guards his precious treasures.");
    cabins_["galley"] = Cabin("The Galley", "Aye, the galley be stocked with provisions. No pilferin' the rum!");
    cabins_["brig"] = Cabin("The Brig", "A dark and dank cell – beware, for some secrets be hidden here.");
    cabins_["crewQuarters"] = Cabin("Crew Quarters", "The restin' place for the hardworking crew. Shh... they be sleepin'.");
    cabins_["bathroom"] = Cabin("The Head", "A place for washin' yer face and contemplatin' life's mysteries.");
    cabins_["gameCabin"] = Cabin("The Game Cabin", "Challenge yer shipmates to a game of cards or dice.");
    cabins_["crowsNest"] = Cabin("The Crow's Nest", "A high perch atop the mast where a pirate's keen eye scans the horizon.");


    // Lien deck
    cabinLinks_["deck"]["U"] = "crowsNest";
    cabinLinks_["deck"]["N"] = "captainsQuarters";
    cabinLinks_["deck"]["E"] = "brig";
    cabinLinks_["deck"]["S"] = "galley";

    // Lien crowsNest
    cabinLinks_["crowsNest"]["D"] = "deck";

    // Lien captain's quarters
    cabinLinks_["captainsQuarters"]["S"] = "deck";

    // Lien brig
    cabinLinks_["brig"]["W"] = "deck";
    cabinLinks_["brig"]["N"] = "crewQuarters";

    // Lien galley
    cabinLinks_["galley"]["N"] = "deck";
    cabinLinks_["galley"]["W"] = "bathroom";
    cabinLinks_["galley"]["E"] = "gameCabin";

    // Lien crew quarters
    cabinLinks_["crewQuarters"]["S"] = "brig";

    // Lien game cabin
    cabinLinks_["gameCabin"]["W"] = "galley";

    // Lien bathroom
    cabinLinks_["bathroom"]["E"] = "galley";
}


void Ship::addObjectToCabin(const std::string& cabinName, const Object& object) {
    cabinObjects_[cabinName].push_back(object);
    cabins_[cabinName].addObject(object);
}

void Ship::createObjects() {
   
    
    addObjectToCabin("deck", Object("Map", "An old map with mysterious markings."));

   
    addObjectToCabin("captainsQuarters", Object("Captain's Log", "A leather-bound log filled with the captain's notes."));
    

    addObjectToCabin("crowsNest", Object("Telescope", "A brass telescope for spotting distant ships.")); 
}


Cabin& Ship::getCabin(std::string currentCabin) {
    return cabins_[currentCabin];
}

std::unordered_map<std::string, std::string>& Ship::getCabinLinks(std::string currentCabin) {
    return cabinLinks_[currentCabin];
}