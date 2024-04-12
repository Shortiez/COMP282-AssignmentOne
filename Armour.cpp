//
// Created by Ben Gotts on 11/04/2024.
//

#include "Armour.h"
#include "Item.h"

Armour::Armour(string name, string description, int protection) {
    setName(name);
    setDescription(description);
    setProtection(protection);
}

string Armour::getDescription() {
    return description;
}
void Armour::setDescription(string description) {
    this->description = description;
}

int Armour::getProtection() {
    return protection;
}
void Armour::setProtection(int protection) {
    this->protection = protection;
}