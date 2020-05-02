#include "Round.h"
#include <unordered_map>
#include "robots/R2_D2.h"
#include "robots/C_3PO.h"
#include "robots/L3_37.h"

R2_D2 *R2_D2::instance = nullptr;
C_3PO *C_3PO::instance = nullptr;
L3_37 *L3_37::instance = nullptr;
int Robot::lives = 3;

Round::Round () {
    coins = 0;
    damage = 0;
}

void Round::setMap(Map map) {
    this->map = new Map(map);
}

void Round::setCoins() {
    Round::coins++;
}

void Round::setDamage() {
    Round::damage++;
}

void Round::printMap() {
    map->printMap();
}

string Round::getNameRobot() {
    return Round::robot->getNameRobot();
}

int Round::getCoins() {
    return coins;
}

int Round::getDamage() {
    return damage;
}

int Round::getTotalCoins() {
    return totalCoins;
}

int Round::getTotalDamage() {
    return totalDamage;
}

void Round::chooseTheRobot() {
    R2_D2 *r2_d2 = R2_D2::getInstance();
    C_3PO *c_3po = C_3PO::getInstance();
    L3_37 *l3_37 = L3_37::getInstance();

    cout << "Hello there! The game is about to start." << endl;
    cout << "The next droids are available: R2-D2, C-3PO, L3-37. Type the name of the robot you want to use." << endl;
    string nameOfRobot;
    cin >> nameOfRobot;
    unordered_map<string, int> string_to_case{
            {"R2-D2",1},
            {"C-3PO",2},
            {"L3-37", 3}
    };
    switch(string_to_case.at(nameOfRobot)) {
        case 1:
            r2_d2->setDataForR2_D2();
            Round::robot = r2_d2;
            break;
        case 2:
            c_3po->setDataForC_3PO();
            Round::robot = c_3po;
            break;
        case 3:
            l3_37->setDataForL3_37();
            Round::robot = l3_37;
            break;
        default:
            cout << "The name you typed is invalid";
    }
    Round::robot->messageFromTheRobot();
}

void Round::Play (vector<AlongTheWay*> itemsAndTraps, Map* map) {
    ++numberRounds;
    cout << endl << "New round! ";

    // set position for the robot in the beginning of each round
    robot->setPositionOnMap(make_pair(0, 0));

    // set random positions for items and traps
    pair<int, int> coordinatesFinalLocation = map->getFinalLocation();
    int n = map->getVertical();
    int m = map->getOrizontal();
    for (int nr = 0; nr < 5; nr++) {
        for (AlongTheWay *itemOrTrap : itemsAndTraps) {
            bool ok = false;
            while (!ok) {
                int nPosition = rand() % n;
                int mPosition = rand() % m;
                if ((nPosition != 0 || mPosition != 0) &&
                    (nPosition != coordinatesFinalLocation.first || mPosition != coordinatesFinalLocation.second)) {
                    itemOrTrap->setPositionItem(nPosition, mPosition);
                    map->setOneCell(nPosition, mPosition, itemOrTrap->getName());
                    ok = true;
                }
            }
        }
    }
    robot->moveRobot(itemsAndTraps, map, this);
    setMap(map);
    numberRounds++;
    totalCoins += coins;
    totalDamage += damage;
    map->resetMap();
}