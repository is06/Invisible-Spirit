/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCREEN_POSITION_H__
#define __IS06_SCREEN_POSITION_H__

namespace is06
{
namespace engine
{

struct SScreenPosition
{
  irr::f32 Top;
  irr::f32 Bottom;
  irr::f32 Left;
  irr::f32 Right;
  irr::f32 VCenter;
  irr::f32 HCenter;

  irr::u16 Width;
  irr::u16 Height;

  irr::u16 DisplayWidth;
  irr::u16 DisplayHeight;
  irr::u8 DisplayDepth;
};

}
}

#endif
