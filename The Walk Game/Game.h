#ifndef THE_WALK_GAME_GAME_H
#define THE_WALK_GAME_GAME_H

#include "Map.h"
#include "Round.h"
#include "AlongTheWay.h"

class Game {
    vector<Round*> rounds;
    vector<AlongTheWay*> itemsOrTraps;
    Map* map;
public:
    Game(int);
    void setItemsAndTraps();
    void setMap();
    vector<AlongTheWay *> getItemsOrTraps();
    Map* getMap();
    void Run();
};

#endif //THE_WALK_GAME_GAME_H