/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BUTTON_H__
#define __IS06_BUTTON_H__

#include "../../enums/gameplay/CommandIdentifier.h"
#include "../Hud.h"

namespace is06
{
namespace hud
{

class CTargetLifeMeter : public CHud
{
  public:
    CTargetLifeMeter(irr::s32 init, irr::s32 min, irr::s32 max);
    ~CTargetLifeMeter();

    void render(const irr::core::vector3df& targetPosition);
    void updateValue(const irr::s32& value);

  private:
    CPicture* BarBack;
    CBarCounter* Gauge;
    CText* Label;
};

}
}

#endif
