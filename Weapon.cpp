//
// Created by Ben Gotts on 09/04/2024.
//

#include "Weapon.h"

int Weapon::getPower() const {
    return power;
}
void Weapon::setPower(int power) {
    Weapon::power = power;
}

Weapon::Weapon() {
    power = 0;
}
Weapon::Weapon(int power) {
    setPower(power);
}
Weapon::Weapon(string name, int power) {
    setName(name);
    setPower(power);
}