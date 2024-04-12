//
// Created by Ben Gotts on 09/04/2024.
//

#include "Potion.h"

int Potion::getStrength() const {
    return strength;
}
void Potion::setStrength(int strength) {
    Potion::strength = strength;
}

Potion::Potion() {
    strength = 0;
}
Potion::Potion(int strength) {
    setStrength(strength);
}
Potion::Potion(string name, int strength) {
    setName(name);
    setStrength(strength);
}