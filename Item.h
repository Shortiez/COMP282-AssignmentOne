//
// Created by Ben Gotts on 09/04/2024.
//

#ifndef ASSIGNMENTONE_ITEM_H
#define ASSIGNMENTONE_ITEM_H

#include <string>

using namespace std;

class Item {
private:
    string name;
public:
    string getName() const;
    void setName(const string& name);

    Item();
    Item(string& name);
    virtual ~Item() {}
};

#endif //ASSIGNMENTONE_ITEM_H
