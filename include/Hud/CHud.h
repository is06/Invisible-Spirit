/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_H__
#define __IS06_HUD_H__

#include "../Engine/CEntity.h"

namespace is06
{
namespace NHud
{

//! Abstract main class for all hud elements
class CHud : public NEngine::CEntity
{
  public:
    CHud();
    virtual ~CHud();
    virtual void render() = 0;
    virtual void setOpacity(f32 value) = 0;
    virtual void addOpacity(f32 value) = 0;
    virtual void subOpacity(f32 value) = 0;
    virtual f32 getOpacity() = 0;
    virtual void show() = 0;
    virtual void hide() = 0;

  protected:
};

}
}

#endif
