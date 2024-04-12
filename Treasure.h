//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_TREASURE_H
#define ASSIGNMENTONE_TREASURE_H

#include "Item.h"

class Treasure : public Item{
private:
    int value;
public:
    int getValue() const;
    void setValue(int value);

    Treasure();
    Treasure(string name, int value);
    virtual ~Treasure() {}
};


#endif //ASSIGNMENTONE_TREASURE_H
