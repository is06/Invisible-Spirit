/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/debug/CDebugConsole.h"

using namespace irr;

namespace is06
{
namespace nDebug
{

CDebugConsole::CDebugConsole()
{
  CommandTextInput = nEngine::CGame::getDebugGUI()->addEditBox(L"test", core::recti(0,0,100,100));
}

void CDebugConsole::render()
{
  nEngine::CGame::getVideoDriver()->draw2DRectangle(video::SColor(255, 255, 255, 255), core::recti(0, 200, 400, 230));
}

CDebugConsole::~CDebugConsole()
{
  CommandTextInput->remove();
}

}
}
