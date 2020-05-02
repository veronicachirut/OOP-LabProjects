#include "Game.h"
#include <chrono>
#include <thread>
#include <unordered_map>

Robot *Round::robot = nullptr;
int Round::numberRounds = 0;
int Round::totalCoins = 0;
int Round::totalDamage = 0;

Game::Game (int numberRounds) {
    for (int i = 0; i < numberRounds; i++) {
        Round* round = new Round();
        this->rounds.push_back(round);
    }
}

void Game::setMap() {
    this->map = new Map(15, 15);
}

void Game::setItemsAndTraps () {
    vector<string> compatibleClassesI1;
    compatibleClassesI1.emplace_back("Fist class");
    AlongTheWay* item1 = new AlongTheWay(compatibleClassesI1, "I1", "++lives");
    itemsOrTraps.push_back(item1);

    vector<string> compatibleClassesI2;
    compatibleClassesI2.emplace_back("All");
    AlongTheWay* item2 = new AlongTheWay(compatibleClassesI2, "I2", "coins");
    itemsOrTraps.push_back(item2);

    AlongTheWay* trap1 = new AlongTheWay(compatibleClassesI2, "T1", "--lives");
    itemsOrTraps.push_back(trap1);
    AlongTheWay* trap2 = new AlongTheWay(compatibleClassesI2, "T2", "--position");
    itemsOrTraps.push_back(trap2);
}

void Game::Run() {
    cout << "Game is loading ..." << endl;
    this_thread::sleep_for(std::chrono::milliseconds(500));
    setItemsAndTraps();
    setMap();
    Round::chooseTheRobot();
    cout << endl << "Simulation with successive rounds? Yes/No?" << endl;
    string answer;
    cin >> answer;
    unordered_map<string, int> string_to_case{
            {"Yes",1},
            {"No",2},
    };
    switch (string_to_case.at(answer)) {
        case 1:
            for (Round *round : rounds) {
                round->Play(getItemsOrTraps(), getMap());
            }
            break;
        case 2:
            for (Round *round : rounds) {
                round->Play(getItemsOrTraps(), getMap());
                cout << endl << "Do you want to see the map of the planets and moons " << Round::getNameRobot()
                     << " visited? Yes/No?" << endl;
                string yourAnswer;
                cin >> yourAnswer;
                if (yourAnswer == "Yes") {
                    cout << endl << "Tatooine, Coruscant, Hoth, Naboo, so many planets... and " << Round::getNameRobot() << " finally did it!" << endl;
                    round->printMap();
                    cout << "In this round " << Round::getNameRobot() << " achieved " << round->getCoins() << " coins for his master Obi-Wan with only " << round->getDamage() << " damage" << endl;
                }
            }
            cout << endl << "Total coins: " << Round::getTotalCoins();
            cout << endl << "Total damage: " << Round::getTotalDamage();
            break;
    }
}

vector<AlongTheWay *> Game::getItemsOrTraps() {
    return itemsOrTraps;
}

Map* Game::getMap() {
    return map;
}
