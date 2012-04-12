/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/engine/Shadow.h"

namespace is06
{
namespace engine
{

/**
 *
 */
CShadow::CShadow(EShadowMode mode)
{
  CurrentMode = mode;
}

const EShadowMode& CShadow::getMode() const
{
  return CurrentMode;
}

/**
 *
 */
CShadow::~CShadow()
{

}

}
}
