#ifndef THE_WALK_GAME_ALONGTHEWAY_H
#define THE_WALK_GAME_ALONGTHEWAY_H
#include <vector>
#include <iostream>
using namespace std;

class AlongTheWay {
    vector<string> compatibleClasses;
    pair<int, int> position;
    string name;
    string role;
public:
    AlongTheWay();
    AlongTheWay(vector<string>, string, string);
    string getName();
    void setPositionItem(int, int);
};

#endif //THE_WALK_GAME_ALONGTHEWAY_H
