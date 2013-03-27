/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NShader/CShadow.h"

namespace is06 { namespace NShader {

//! Constructor
CShadow::CShadow(EShadowMode mode)
{
  CurrentMode = mode;
}

//! Returns the shadow mode identifier
const EShadowMode& CShadow::getMode() const
{
  return CurrentMode;
}

//! Destructor, does nothing
CShadow::~CShadow()
{

}

}}
