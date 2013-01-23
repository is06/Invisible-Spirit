/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYABLE_CHARACTER_H__
#define __IS06_PLAYABLE_CHARACTER_H__

#include "../../include/model/CCharacter.h"
#include "../../include/engine/EPlayableCharacterType.h"

namespace is06
{
namespace n3D
{

//! Class for the hero, the playable character
class CPlayableCharacter : public CCharacter
{
  public:
    CPlayableCharacter(CCamera* cam);

    void update();

    void setCharacter(nEngine::EPlayableCharacterType type = nEngine::EPCT_AYRON);

    // Player moves
    void goLeft(f32 speed);
    void goRight(f32 speed);
    void goForward(f32 speed);
    void goBackward(f32 speed);
    void updateDirectionFromAngle(f32 angle);

    // Wall collisions
    void moveOpposite(const core::vector3df& normal);

    // Player control
    void toggleControl();
    void setControl(bool active);
    bool hasControl();

  private:
    void updateCoords(f32 deltaU, f32 speed);

    CCamera* LinkedCam;

    bool Controlable;
};

}
}

#endif
