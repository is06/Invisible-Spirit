/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_H__
#define __IS06_HUD_H__

#include "../engine/Entity.h"

namespace is06
{
namespace nHud
{

//! Abstract main class for all hud elements
class CHud : public nEngine::CEntity
{
  public:
    CHud();
    virtual ~CHud();

    virtual void render() = 0;

    virtual void setOpacity(u8 value) = 0;
    virtual void show() = 0;
    virtual void hide() = 0;

  protected:
};

}
}

#endif
