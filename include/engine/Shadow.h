/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADOW_H__
#define __IS06_SHADOW_H__

#include "../enums/engine/ShadowMode.h"

namespace is06
{
namespace engine
{

class CShadow
{
  public:
    CShadow(engine::EShadowMode mode = SHADOW_MODE_CAST);
    ~CShadow();

    const engine::EShadowMode& getMode() const;

  private:
    engine::EShadowMode CurrentMode;
};

}
}

#endif

