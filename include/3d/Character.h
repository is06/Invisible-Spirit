/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CHARACTER_H__
#define __IS06_CHARACTER_H__

#include "../../include/3d/AnimatedModel.h"

class Character : public AnimatedModel
{
  public:
    Character();

    virtual void render();

    bool isJumping;
    bool isFalling;
    bool isWalking;
    bool isTalking;

  protected:
    f32 jumpStrength;
};

#endif
