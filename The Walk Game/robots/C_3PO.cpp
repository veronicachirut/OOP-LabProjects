#include "C_3PO.h"

C_3PO * C_3PO::getInstance() {
    if (!instance)
        instance = new C_3PO;
    return instance;
}

void C_3PO::setDataForC_3PO () {
    this->setNameRobot("C-3PO");
    this->setClassOfDroid("Second class");
    this->setPositionOnMap({0, 0});
    this->setLives(3);
}

void C_3PO::messageFromTheRobot() {
    cout << "C_3PO: I was there on Yavin when Luke Skywalker blew up the Death Star. Let's make history together one more time";
}