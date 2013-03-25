/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_ENEMY_FLOOR_H__
#define __IS06_3D_ENEMY_FLOOR_H__

#include "../../../include/3D/CEnemy.h"

namespace is06 { namespace N3D { namespace NEnemy {

//! Base class for all walking and crawling enemies
class CFloorEnemy : public CEnemy
{
public:
  CFloorEnemy();
  virtual ~CFloorEnemy();

  virtual void update();
};

}}}

#endif
