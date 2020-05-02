#ifndef THE_WALK_GAME_R2_D2_H
#define THE_WALK_GAME_R2_D2_H

#include "Robot.h"

class R2_D2 : public Robot{
    static R2_D2 *instance;

    R2_D2 () = default;

public:
    static R2_D2 *getInstance ();
    void setDataForR2_D2();
    void messageFromTheRobot() override;
};


#endif //THE_WALK_GAME_R2_D2_H
