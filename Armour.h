//
// Created by Ben Gotts on 11/04/2024.
//

#ifndef ASSIGNMENTONE_ARMOUR_H
#define ASSIGNMENTONE_ARMOUR_H

#include <string>
#include "Item.h"

using namespace std;

class Armour : public Item{
private:
    string description;
    int protection;
public:
    Armour(string name, string description, int protection);

    string getDescription();
    void setDescription(string description);

    int getProtection();
    void setProtection(int protection);
};


#endif //ASSIGNMENTONE_ARMOUR_H
