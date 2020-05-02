#ifndef THE_WALK_GAME_L3_37_H
#define THE_WALK_GAME_L3_37_H

#include "Robot.h"

class L3_37 : public Robot{
    static L3_37 *instance;

    L3_37 () = default;
public:
    static L3_37 *getInstance ();
    void setDataForL3_37();
    void messageFromTheRobot () override ;
};


#endif //THE_WALK_GAME_L3_37_H
