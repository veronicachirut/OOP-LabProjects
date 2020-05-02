#include "L3_37.h"

L3_37 * L3_37::getInstance() {
    if (!instance)
        instance = new L3_37;
    return instance;
}

void L3_37::setDataForL3_37 () {
    this->setNameRobot("L3-37");
    this->setClassOfDroid("Third class");
    this->setPositionOnMap({0, 0});
    this->setLives(3);
}

void L3_37::messageFromTheRobot () {
    cout << "L3-37: Let's break free from our oppressors and become the individuals we were always meant to be!";
}