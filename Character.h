//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_CHARACTER_H
#define ASSIGNMENTONE_CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "Armour.h"

using namespace std;

class Character {
protected:
    string name;
    int hitPoints;
    vector<Armour> armour;
public:
    void setName(const string& name);
    string getName() const;

    int getHitPoints() const;
    void setHitPoints(int hitPoints);
    void takeHit(int damage);

    void addArmour(Armour armour);
    vector<Armour> getArmour();
    void setArmour(vector<Armour> armour);
};

#endif //ASSIGNMENTONE_CHARACTER_H
