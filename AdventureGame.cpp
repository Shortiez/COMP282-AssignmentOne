//
// Created by Ben Gotts on 09/04/2024.
//

#include "Location.h"
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "Treasure.h"

Location cave;
Location temple;
Location dungeon;
Location castle;
Location clearing;
Location hall;
Location garden;
Location library;
Location forest;
Location house;
Location ruins;
Location field;

// Initialize Treasure objects
Treasure emerald("Emerald", 40);
Treasure sapphire("Sapphire", 40);
Treasure diamond("Diamond", 60);
Treasure goldRing("Gold Ring", 60);
Treasure treasureChest("Treasure Chest", 200);
Treasure bagOfCoins("Bag of Coins", 50);
Treasure ruby("Ruby", 10);
Treasure cup("Cup", 20);
Treasure pearl("Pearl", 30);
Treasure key("Key", 5);
Treasure book("Book", 15);

// Initialize Weapon objects
Weapon dagger("Dagger", 5);
Weapon sword("Sword", 6);
Weapon stick("Stick", 1);
Weapon club("Club", 3);
Weapon crossbow("Crossbow", 10);

// Initialize Potion objects
Potion redHealing("Red Healing Potion", 40);
Potion purpleHealing("Purple Healing Potion", 30);
Potion blueHealing("Blue Healing Potion", 20);

// Initialize Armour objects
// ringmail, chainmail, shield, breastplate, helmet, gauntlet
// name, description, defence
Armour ringmail("Ringmail",
                "Ringmail Armour",
                5);
Armour chainmail("Chainmail",
                 "Chainmail Armour",
                 2);
Armour shield("Shield",
              "Shield Armour",
              3);
Armour breastplate("Breastplate",
                   "Breastplate Armour",
                   4);
Armour helmet("Helmet",
              "Helmet Armour",
              1);
Armour gauntlet("Gauntlet",
                "Gauntlet Armour",
                2);

// Initialize Monster objects
Monster goblin = Monster("Goblin", 10);
Monster zombie = Monster("Zombie", 8);
Monster banshee = Monster("Banshee", 7);
Monster vampire = Monster("Vampire", 9);
Monster dragon = Monster("Dragon", 15);
Monster orc = Monster("Orc", 12);
Monster spectre = Monster("Spectre", 5);
Monster ghoul = Monster("Ghoul", 10);

Player player;
Player boss;

map<Direction, Location*> AvaliableExits;
bool gameRunning = true;

enum Command{
    MOVE_NORTH,
    MOVE_SOUTH,
    MOVE_EAST,
    MOVE_WEST,
    COLLECT,
    DRINK,
    INVENTORY,
    FIGHT,
    STATUS,
    QUIT,
    INVALID
};

void InitLocations();
void CreateMap();

void InitPlayer();
void InitBoss();

void DisplayPlayerLocation();

string DirectionToString(Direction dir);
Direction StringToDirection(string dir);

Command StringToCommand(string command);
void ProcessCommand(Command command);

void TryMove(Direction direction);
void CollectItems();
void ShowInventory();
void ShowPlayerStatus();
void DrinkPotion();

Monster SelectMonsterToFight();

int main()
{
    InitLocations();
    CreateMap();

    InitPlayer();
    InitBoss();

    // Game Loop
    while(gameRunning){
        DisplayPlayerLocation();

        string input = "";
        cout << "Enter a command: ";
        cin >> input;

        Command command = INVALID;
        command = StringToCommand(input);

        ProcessCommand(command);

        if(boss.getHitPoints() <= 0){
            cout << "Congratulations! You have defeated the boss!" << endl;
            cout << "Your final score is: " << player.getScore() << endl;

            gameRunning = false;
            break;
        }
    }

    return 0;
}

string DirectionToString(Direction dir){
    switch(dir){
        case NORTH:
            return "North";
        case SOUTH:
            return "South";
        case EAST:
            return "East";
        case WEST:
            return "West";
    }
    return "";
}
Direction StringToDirection(string dir){
    // dir = North, n, N
    if(dir == "North" || dir == "north" || dir == "n" || dir == "N"){
        return NORTH;
    }
    // dir = South, s, S
    if(dir == "South" || dir == "south" || dir == "s" || dir == "S"){
        return SOUTH;
    }
    // dir = East, e, E
    if(dir == "East" || dir == "east" || dir == "e" || dir == "E"){
        return EAST;
    }
    // dir = West, w, W
    if(dir == "West" || dir == "west" || dir == "w" || dir == "W"){
        return WEST;
    }
}

Command StringToCommand(string command){
    if(command == "North" || command == "north" || command == "n" || command == "N"){
        return MOVE_NORTH;
    }
    if(command == "South" || command == "south" || command == "s" || command == "S"){
        return MOVE_SOUTH;
    }
    if(command == "East" || command == "east" || command == "e" || command == "E"){
        return MOVE_EAST;
    }
    if(command == "West" || command == "west" || command == "w" || command == "W"){
        return MOVE_WEST;
    }
    if(command == "collect"){
        return COLLECT;
    }
    if(command == "drink"){
        return DRINK;
    }
    if(command == "inventory" || command == "inv" ){
        return INVENTORY;
    }
    if(command == "fight"){
        return FIGHT;
    }
    if(command == "status"){
        return STATUS;
    }
    if(command == "quit" ){
        return QUIT;
    }

    return INVALID;
}
void ProcessCommand(Command command){
    switch(command){
        case MOVE_NORTH:
            TryMove(NORTH);
            break;
        case MOVE_SOUTH:
            TryMove(SOUTH);
            break;
        case MOVE_EAST:
            TryMove(EAST);
            break;
        case MOVE_WEST:
            TryMove(WEST);
            break;
        case COLLECT:
            CollectItems();
            break;
        case DRINK:
            DrinkPotion();
            break;
        case INVENTORY:
            ShowInventory();
            break;
        case FIGHT:
            if(player.combat(SelectMonsterToFight())){
                cout << "Game Over!" << endl;
                cout << "Player defeated! Score: " << player.getScore() << endl;

                gameRunning = false;
                break;
            }
            break;
        case STATUS:
            ShowPlayerStatus();
            break;
        case QUIT:
            gameRunning = false;
            break;
        case INVALID:
            break;
    }
}

void DisplayScore(){
    cout << "Score: " << player.getScore() << endl;
}
void DisplayPlayerLocation(){
    cout << "You are currently in the " << player.getCurrentLocation().getName() << ". " << player.getCurrentLocation().getDescription() << endl;
    cout << "Your available exits are: " << endl;

    for(const auto& exit : AvaliableExits){
        Location* location = exit.second;
        cout << location->getName() << " (" << DirectionToString(exit.first) << ") " << endl;
    }

    cout << endl;
}

void InitLocations(){
    cave.setName("Cave");
    temple.setName("Temple");
    dungeon.setName("Dungeon");
    castle.setName("Castle");
    clearing.setName("Clearing");
    hall.setName("Hall");
    garden.setName("Garden");
    library.setName("Library");
    forest.setName("Forest");
    house.setName("House");
    ruins.setName("Ruins");
    field.setName("Field");

    cave.setDescription("You are in a dark cave. You can see a faint light to the east.");
    temple.setDescription("You are in an ancient temple. The walls are covered in moss and ivy.");
    dungeon.setDescription("You are in a dark dungeon. You can hear the sound of dripping water.");
    castle.setDescription("You are in a grand castle. The walls are adorned with tapestries.");
    clearing.setDescription("You are in a clearing in the forest. The sun is shining.");
    hall.setDescription("You are in a grand hall. The room is filled with the sound of music.");
    garden.setDescription("You are in a beautiful garden. The flowers are in full bloom.");
    library.setDescription("You are in a dusty library. The shelves are filled with old books.");
    forest.setDescription("You are in a dense forest. The trees are tall and imposing.");
    house.setDescription("You are in a small house. The fire is crackling in the hearth.");
    ruins.setDescription("You are in a ruined building. The roof has collapsed in places.");
    field.setDescription("You are in a field. The grass is swaying in the breeze.");

    cave.addItem(&emerald);
    temple.addItem(&diamond);
    temple.addItem(&sword);
    dungeon.addItem(&redHealing);
    castle.addItem(&goldRing);
    castle.addItem(&stick);
    clearing.addItem(&club);
    hall.addItem(&bagOfCoins);
    hall.addItem(&blueHealing);
    garden.addItem(&ruby);
    garden.addItem(&crossbow);
    house.addItem(&treasureChest);
    ruins.addItem(&purpleHealing);
    ruins.addItem(&pearl);
    library.addItem(&book);
    library.addItem(&cup);
    field.addItem(&sapphire);
    field.addItem(&dagger);

    field.addMonster(&goblin);
    dungeon.addMonster(&zombie);
    forest.addMonster(&banshee);
    castle.addMonster(&vampire);
    ruins.addMonster(&dragon);
    house.addMonster(&orc);
    house.addMonster(&spectre);
    garden.addMonster(&ghoul);

    library.addItem(&gauntlet);
    dungeon.addItem(&helmet);
    clearing.addItem(&breastplate);
    ruins.addItem(&shield);
    house.addItem(&chainmail);
    garden.addItem(&ringmail);
}
void CreateMap() {
    cave.addExit(EAST, &field);

    field.addExit(WEST, &cave);
    field.addExit(EAST, &forest);
    field.addExit(SOUTH, &dungeon);

    dungeon.addExit(NORTH, &field);
    dungeon.addExit(EAST, &castle);

    castle.addExit(WEST, &dungeon);
    castle.addExit(SOUTH, &ruins);
    castle.addExit(NORTH, &forest);

    ruins.addExit(NORTH, &castle);

    forest.addExit(SOUTH, &castle);
    forest.addExit(WEST, &field);
    forest.addExit(NORTH, &temple);

    temple.addExit(SOUTH, &forest);
    temple.addExit(EAST, &clearing);

    clearing.addExit(WEST, &temple);
    clearing.addExit(EAST, &house);

    house.addExit(WEST, &clearing);
    house.addExit(EAST, &library);
    house.addExit(SOUTH, &hall);

    library.addExit(WEST, &house);
    library.addExit(SOUTH, &garden);

    garden.addExit(NORTH, &library);
    garden.addExit(WEST, &hall);

    hall.addExit(NORTH, &house);
    hall.addExit(EAST, &garden);

    cave.getExits();
    temple.getExits();
    dungeon.getExits();
    castle.getExits();
    clearing.getExits();
    hall.getExits();
    garden.getExits();
    library.getExits();
    forest.getExits();
    house.getExits();
    ruins.getExits();
    field.getExits();
}

void InitPlayer(){
    player.setName("Player");
    player.setScore(0);

    player.setCurrentLocation(clearing);
    AvaliableExits = player.getCurrentLocation().getExits();
}
void InitBoss(){
    boss.setName("Boss");
    boss.setHitPoints(30);

    boss.setCurrentLocation(cave);
}

void TryMove(Direction direction){
    if(AvaliableExits.find(direction) != AvaliableExits.end()){
        player.setCurrentLocation(*AvaliableExits[direction]);

        AvaliableExits = player.getCurrentLocation().getExits();
    }
    else{
        cout << "You cannot move in that direction." << endl;
    }
}
void ShowInventory(){

    cout << "===== Inventory ===== " << endl;

    cout << "Weapons: " << endl;
    if(player.weapons.empty()){
        cout << "None" << endl;
    }
    else{
        for(Weapon weapon : player.weapons){
            cout << weapon.getName() << " (" << weapon.getPower() << " Power)" << endl;
        }
    }

    cout << "Potions: " << endl;
    if(player.potions.empty()){
        cout << "None" << endl;
    }
    else{
        for(Potion potion : player.potions){
            cout << potion.getName() << " (" << potion.getStrength() << " Strength)" << endl;
        }
    }

    cout << "Treasures: " << endl;
    if(player.treasures.empty()){
        cout << "None" << endl;
    }
    else{
        for(Treasure treasure : player.treasures){
            cout << treasure.getName() << " (" << treasure.getValue() << " Value)" << endl;
        }
    }

    cout << "Armour: " << endl;
    if(player.getArmour().empty()){
        cout << "None" << endl;
    }
    else{
        for(Armour armour : player.getArmour()){
            cout << armour.getName() << " (" << armour.getProtection() << " Protection)" << endl;
        }
    }

    cout << "=====================" << endl;
}
void ShowPlayerStatus(){
    cout << "===== Player Status =====" << endl;

    cout << "Player: " << player.getName() << endl;
    cout << "Hit Points: " << player.getHitPoints() << endl;
    cout << "Score: " << player.getScore() << endl;

    cout << "=========================" << endl;
}
void CollectItems(){
    vector<Weapon*> weapons = player.getCurrentLocation().weapons;
    vector<Potion*> potions = player.getCurrentLocation().potions;
    vector<Treasure*> treasures = player.getCurrentLocation().treasure;
    int itemsCollectedCount = 0;

    for(Weapon* weapon : weapons){
        player.weapons.push_back(*weapon);

        itemsCollectedCount++;
    }
    for(Potion* potion : potions){
        player.potions.push_back(*potion);

        itemsCollectedCount++;
    }
    for(Treasure* treasure : treasures){
        player.treasures.push_back(*treasure);

        itemsCollectedCount++;
    }

    cout << "You have collected " << itemsCollectedCount << " item/items from the location." << endl;
}
void DrinkPotion(){
    for(Potion potion : player.potions){
        player.setHitPoints(player.getHitPoints() + potion.getStrength());
        player.potions.pop_back();
    }
}

Monster SelectMonsterToFight(){
    vector<Monster*> monsters = player.getCurrentLocation().getMonsters();

    Monster selectedMonster = *monsters[0];

    for (Monster* monster : monsters){
        if (monster->getHitPoints() > selectedMonster.getHitPoints()){
            selectedMonster = *monster;
        }
    }

    return selectedMonster;
}