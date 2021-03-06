/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_CORE_ENTITY_H__
#define __IS06_ENGINE_CORE_ENTITY_H__

#include "../../core.h"

namespace is06 { namespace NEngine { namespace NCore {

//! Main general abstract class for all entities in the game
class CEntity
{
public:
  CEntity();
  virtual ~CEntity();
  virtual void update();
  virtual void render();
};

}}}

#endif
