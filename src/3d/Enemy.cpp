/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/3d/AnimatedModel.h"
#include "../../include/3d/Enemy.h"

namespace is06
{
namespace n3D
{

CEnemy::CEnemy() : CAnimatedModel()
{

}

void CEnemy::update()
{
  CAnimatedModel::update();
}

CEnemy::~CEnemy()
{

}

}
}
