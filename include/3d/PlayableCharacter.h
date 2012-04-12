/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYABLE_CHARACTER_H__
#define __IS06_PLAYABLE_CHARACTER_H__

#include "../../include/3d/Character.h"

namespace is06
{
namespace model
{

class CPlayableCharacter : public CCharacter
{
  public:
    CPlayableCharacter(CCamera* cam);

    void update();

    // Player moves
    void goLeft(irr::f32 speed);
    void goRight(irr::f32 speed);
    void goForward(irr::f32 speed);
    void goBackward(irr::f32 speed);

    // Gravity
    void fall(irr::f32 factor);
    void raise();
    void jump();
    void setJumpDelta(irr::f32 value);
    irr::f32 getJumpDelta();
    irr::f32 getJumpStrength();

    // Wall collisions
    void moveOpposite(const irr::core::vector3df& normal);

    // Player control
    void toggleControl();
    bool hasControl();

  private:
    void updateCoords(irr::f32 deltaU, irr::f32 speed);

    CCamera* LinkedCam;

    bool Controlable;
    irr::f32 JumpDelta;
    irr::f32 FallDelta;
    irr::f32 Gravity;
    irr::f32 JumpStrength;
};

}
}

#endif
