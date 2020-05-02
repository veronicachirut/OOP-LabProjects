#ifndef THE_WALK_GAME_C_3PO_H
#define THE_WALK_GAME_C_3PO_H

#include "Robot.h"

class C_3PO : public Robot {
    static C_3PO *instance;

    C_3PO () = default;

public:
    static C_3PO *getInstance ();
    void setDataForC_3PO();
    void messageFromTheRobot () override ;
};


#endif //THE_WALK_GAME_C_3PO_H
