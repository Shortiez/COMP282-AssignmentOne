//
// Created by Ben Gotts on 09/04/2024.
//

#include "Player.h"

int Player::getScore() {
    return score;
}

void Player::setScore(int score) {
    this->score = score;
}

Location Player::getCurrentLocation() {
    return currentLocation;
}

void Player::setCurrentLocation(Location currentLocation) {
    this->currentLocation = currentLocation;
}

int rollDice(){
    srand(time(nullptr));

    return (int)(rand() % 6 + 1);
}

int calculateProtection(vector<Armour> armour) {
    srand(time(nullptr));

    int protection = 0;

    for (int i = 0; i < armour.size(); i++) {
        protection += armour[i].getProtection();
    }

    // Return a random number between 0 and the total protection
    return (int)(rand() % protection + 1);
}

bool Player::combat(Monster monster) {
    cout << "Player enters combat with " << monster.getName() << endl;

    while (true) {
        // Monster strikes first
        int monsterDamage = (rollDice() * 2);
        cout << "Monster inflicts " << monsterDamage << " damage." << endl;
        takeHit(monsterDamage - calculateProtection(armour));

        // Check if player is defeated
        if (getHitPoints() <= 0) {
            return true; // Player was defeated
        }

        // Player strikes back
        int playerDamage = rollDice();
        playerDamage += getMostPowerfulWeapon().getPower(); // Add weapon power
        cout << "Player inflicts " << playerDamage << " damage." << endl;
        monster.takeHit(playerDamage - calculateProtection(monster.getArmour()));

        // Display updated hitpoints
        cout << "Player hitpoints: " << getHitPoints() << endl;
        cout << "Monster hitpoints: " << monster.getHitPoints() << endl;

        // Check if monster is defeated
        if (monster.getHitPoints() <= 0) {
            cout << "Monster defeated!" << endl;
            // Update player's score
            int newScore = getScore() + monster.getHitPoints();
            setScore(newScore);

            // Drop loot
            vector<Item* > monsterLoot = monster.getLoot();
            Location playerLocation = getCurrentLocation();
            int itemsDropped = 0;
            for (int i = 0; i < monsterLoot.size(); i++) {
                playerLocation.addItem(monsterLoot[i]);
                itemsDropped++;
            }

            cout << "Monster dropped " << itemsDropped << " items!" << endl;
            cout << "Type 'collect' to pick up items." << endl;

            return false; // Player was not defeated
        }
    }
}

Weapon Player::getMostPowerfulWeapon() {
    Weapon mostPowerfulWeapon = weapons[0];

    for (int i = 1; i < weapons.size(); i++) {
        if (weapons[i].getPower() > mostPowerfulWeapon.getPower()) {
            mostPowerfulWeapon = weapons[i];
        }
    }

    return mostPowerfulWeapon;
}