/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCREEN_POSITION_H__
#define __IS06_SCREEN_POSITION_H__

#include "core.h"
#include "SHudPositionInfo.h"
#include "SDisplayPositionInfo.h"

using namespace irr;

namespace is06
{
namespace nEngine
{

//! Screen display and position information
struct SScreenPosition
{
  SHudPositionInfo Hud;
  SDisplayPositionInfo Display;
};

}
}

#endif
