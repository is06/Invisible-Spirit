/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Hud/PauseScreen/CSubScreen.h"

namespace is06 { namespace NHud { namespace NPauseScreen { namespace NSubScreen {

CSubScreen::CSubScreen() : CHud() {}

//! \todo comment this function
void CSubScreen::render()
{
  CHud::render();
}

//! \todo write this function
void CSubScreen::show()
{

}

//! \todo write this function
void CSubScreen::hide()
{

}

//! \todo write this function
void CSubScreen::setOpacity(f32 value)
{
  Opacity = value;
}

void CSubScreen::addOpacity(f32 value)
{
  Opacity += value;
}

void CSubScreen::subOpacity(f32 value)
{
  Opacity -= value;
}

f32 CSubScreen::getOpacity()
{
  return Opacity;
}

CSubScreen::~CSubScreen() {}

}}}}
