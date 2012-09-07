/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_POSITION_INFO_H__
#define __IS06_HUD_POSITION_INFO_H__

#include "core.h"

using namespace irr;

namespace is06
{
namespace nEngine
{

struct SHudPositionInfo
{
  f32 Top;
  f32 Bottom;
  f32 Left;
  f32 Right;
  f32 VCenter;
  f32 HCenter;
  u16 Width;
  u16 Height;
};

}
}

#endif

