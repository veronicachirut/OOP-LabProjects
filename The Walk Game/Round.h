#ifndef THE_WALK_GAME_ROUND_H
#define THE_WALK_GAME_ROUND_H

#include "Map.h"
#include "AlongTheWay.h"
#include <list>

class Map;
class Robot;

class Round {
    Map* map;
    int coins;
    int damage;
    static Robot* robot;
    static int numberRounds;
    static int totalCoins;
    static int totalDamage;
public:
    Round();
    void Play(vector<AlongTheWay*>, Map*);
    void setMap(Map);
    void printMap();
    void setDamage();
    void setCoins();
    int getCoins();
    int getDamage();
    static string getNameRobot();
    static void chooseTheRobot();
    static int getTotalDamage();
    static int getTotalCoins();
};

#endif //THE_WALK_GAME_ROUND_H