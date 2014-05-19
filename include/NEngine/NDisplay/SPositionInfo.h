/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_DISPLAY_POSITION_INFO_H__
#define __IS06_ENGINE_DISPLAY_POSITION_INFO_H__

#include "../../core.h"

using namespace irr;

namespace is06 { namespace NEngine { namespace NDisplay {

//! Position information data structure
struct SPositionInfo
{
  u16 Top;
  u16 Bottom;
  u16 Left;
  u16 Right;
  u16 VCenter;
  u16 HCenter;
  u16 Width;
  u16 Height;
  u8 ColorDepth;
};

}}}

#endif
