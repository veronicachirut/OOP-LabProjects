#ifndef THE_WALK_GAME_MAP_H
#define THE_WALK_GAME_MAP_H

#include <iostream>
#include <utility>
#include "robots/Robot.h"
using namespace std;

class Robot;

class Map {
    int vertical, orizontal;        // map dimensions
    string **map;
    pair<int, int> finalLocation;
public:
    Map(int, int);
    Map(Map*);
    friend class R2_D2;
    friend class C_3PO;
    friend class L3_37;
    void setOneCell (int, int, string);
    int getVertical();
    int getOrizontal();
    string getOneCell(int, int);
    pair<int, int> getFinalLocation();
    void printMap();
    void resetMap();
};

#endif //THE_WALK_GAME_MAP_H