//
// Created by Ben Gotts on 09/04/2024.
//

#include "Item.h"

Item::Item() {
    name = "Unnamed Item";
}
Item::Item(std::string &name) {
    setName(name);
}

string Item::getName() const {
    return name;
}
void Item::setName(const string& name) {
    Item::name = name;
}