/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_ENEMY_ENEMY_H__
#define __IS06_3D_ENEMY_ENEMY_H__

#include "../NPrimitive/CAnimatedModel.h"

namespace is06 { namespace N3D { namespace NEnemy {

//! Base class for all enemies
class CEnemy : public NPrimitive::CAnimatedModel
{
public:
  CEnemy();
  virtual ~CEnemy();

  virtual void update();
};

}}}

#endif
