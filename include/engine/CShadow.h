/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADOW_H__
#define __IS06_SHADOW_H__

#include "EShadowMode.h"

namespace is06
{
namespace nEngine
{

//! A reprensentation of a shadow comportement attached to a 3D entity
class CShadow
{
  public:
    CShadow(nEngine::EShadowMode mode = ESM_CAST);
    ~CShadow();

    const nEngine::EShadowMode& getMode() const;

  private:
    nEngine::EShadowMode CurrentMode;
};

}
}

#endif

