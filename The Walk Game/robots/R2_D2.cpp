#include "R2_D2.h"

R2_D2 * R2_D2::getInstance() {
    if (!instance)
        instance = new R2_D2;
    return instance;
}

void R2_D2::setDataForR2_D2 () {
    this->setNameRobot("R2-D2");
    this->setClassOfDroid("First class");
    this->setPositionOnMap({0, 0});
    this->setLives(3);
}

void R2_D2::messageFromTheRobot() {
    cout << "R2-D2: Hi, you! Thank you for choosing me! I will do anything to assure victory for the human I serve";
}