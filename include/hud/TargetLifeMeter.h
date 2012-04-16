/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BUTTON_H__
#define __IS06_BUTTON_H__

#include "../engine/CommandIdentifier.h"
#include "Hud.h"

namespace is06
{
namespace nHud
{

class CTargetLifeMeter : public CHud
{
  public:
    CTargetLifeMeter(s32 init, s32 min, s32 max);
    ~CTargetLifeMeter();

    void render(const core::vector3df& targetPosition);
    void updateValue(const s32& value);

  private:
    CPicture* BarBack;
    CBarCounter* Gauge;
    CText* Label;
};

}
}

#endif
