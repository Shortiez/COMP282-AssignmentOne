//
// Created by Ben Gotts on 09/04/2024.
//

#include "Character.h"

void Character::setName(const string& name) {
    this->name = name;
}
string Character::getName() const {
    return name;
}

void Character::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}
int Character::getHitPoints() const {
    return hitPoints;
}
void Character::takeHit(int damage) {
    setHitPoints(getHitPoints() - damage);
}

void Character::addArmour(Armour armour) {
    this->armour.push_back(armour);
}
vector<Armour> Character::getArmour() {
    return armour;
}
void Character::setArmour(vector<Armour> armour) {
    this->armour = armour;
}
