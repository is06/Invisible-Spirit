/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PLAYER_STATE_CAPACITY_H__
#define __IS06_HUD_PLAYER_STATE_CAPACITY_H__

#include "../NCore/CHudEntity.h"

namespace is06 { namespace NHud { namespace NPlayerState {

class CCapacity : public NCore::CHudEntity
{
public:
  CCapacity();
  ~CCapacity();

  void render();

private:
  NPrimitive::CPicture* Icon;
  NText::CText* Value;
};

}}}

#endif
