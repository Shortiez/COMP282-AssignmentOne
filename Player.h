//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_PLAYER_H
#define ASSIGNMENTONE_PLAYER_H

#include "Character.h"
#include "Location.h"
#include "Weapon.h"
#include "Potion.h"
#include "Treasure.h"

#include <vector>

using namespace std;

class Player : public Character {
private:
    int score;
    Location currentLocation;
public:
    vector<Weapon> weapons;
    vector<Potion> potions;
    vector<Treasure> treasures;

    int getScore();
    void setScore(int score);
    Location getCurrentLocation();
    void setCurrentLocation(Location currentLocation);

    bool combat(Monster monster);
    Weapon getMostPowerfulWeapon();
};

#endif //ASSIGNMENTONE_PLAYER_H
