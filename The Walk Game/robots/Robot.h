#ifndef THE_WALK_GAME_ROBOT_H
#define THE_WALK_GAME_ROBOT_H

#include <utility>
#include <vector>
#include <iostream>
using namespace std;

#include "../Map.h"
#include "../AlongTheWay.h"
#include "../Round.h"

class Map;
class Round;

class Robot {
    string nameRobot;
    string classOfDroid;
    pair <int, int> positionOnMap;
    static int lives;
public:
    Robot ();
    string &getNameRobot();
    void setNameRobot(const string &nameRobot);
    void setClassOfDroid(const string &classOfDroid);
    void setPositionOnMap(const pair<int, int> &positionOnMap);
    void setLives(int lives);
    virtual void messageFromTheRobot() = 0;
    void moveRobot(vector<AlongTheWay*>, Map*, Round*);
    virtual ~Robot();
};

/*
   First class droids - are skilled in mathematical, physical and medical sciences
   Second class - are skilled in engineering and technical sciences
   Third class - social sciences and service functions
 */

#endif //THE_WALK_GAME_ROBOT_H