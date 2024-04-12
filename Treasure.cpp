//
// Created by Ben Gotts on 09/04/2024.
//

#include "Treasure.h"

int Treasure::getValue() const {
    return value;
}
void Treasure::setValue(int value) {
    Treasure::value = value;
}

Treasure::Treasure() {
    value = 0;
}
Treasure::Treasure(string name, int value) {
    setName(name);
    setValue(value);
}