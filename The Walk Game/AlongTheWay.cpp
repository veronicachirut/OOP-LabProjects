#include "AlongTheWay.h"

AlongTheWay::AlongTheWay () {
    this->position.first = 0;
    this->position.second = 0;
    this->role = "";
}

AlongTheWay::AlongTheWay (vector<string> compatibleClasses, string name, string role) {
    for (string compatibleClass : compatibleClasses) {
        this->compatibleClasses.push_back(compatibleClass);
    }
    this->position.first = 0;
    this->position.second = 0;
    this->name = name;
    this->role = role;
}

string AlongTheWay::getName() {
    return name;
}

void AlongTheWay::setPositionItem(int n, int m) {
    position = make_pair(n, m);
}