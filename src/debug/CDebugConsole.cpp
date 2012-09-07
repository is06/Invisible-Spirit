/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CKeyboard.h"
#include "../../include/debug/CDebugConsole.h"

using namespace irr;

namespace is06
{
namespace nDebug
{

CDebugConsole::CDebugConsole()
{
  gui::IGUIFont* font = nEngine::CGame::getDebugGUI()->getFont("resource/texture/debug/font/std.png");
  CommandTextInput = nEngine::CGame::getDebugGUI()->addEditBox(
    L"", core::recti(
      4,
      nEngine::CGame::ScreenPos.Display.Bottom - 25,
      nEngine::CGame::ScreenPos.Display.Right - 104,
      nEngine::CGame::ScreenPos.Display.Bottom - 4
    )
  );
  CommandTextInput->setDrawBorder(false);
  CommandTextInput->setOverrideFont(font);
  CommandTextInput->setOverrideColor(video::SColor(255, 255, 255, 255));

  nEngine::CGame::getDebugGUI()->setFocus(CommandTextInput);
}

void CDebugConsole::render()
{
  nEngine::CGame::getVideoDriver()->draw2DRectangle(
    video::SColor(255, 75, 75, 75),
    core::recti(
      0,
      nEngine::CGame::ScreenPos.Display.Bottom - 30,
      nEngine::CGame::ScreenPos.Display.Right - 100,
      nEngine::CGame::ScreenPos.Display.Bottom
    )
  );
  nEngine::CGame::getVideoDriver()->draw2DRectangle(
    video::SColor(255, 50, 50, 50),
    core::recti(
      4,
      nEngine::CGame::ScreenPos.Display.Bottom - 25,
      nEngine::CGame::ScreenPos.Display.Right - 104,
      nEngine::CGame::ScreenPos.Display.Bottom - 4
    )
  );
}

void CDebugConsole::executeCurrentCommand()
{
  wstring wcommand(CommandTextInput->getText());
  string command(wcommand.begin(), wcommand.end());
  CommandTextInput->setText(L"");

  // Split command string into a vector container
  istringstream iss(command);
  vector<string> elements;
  copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(elements));

  if (elements[0] == "new") {
    // Object creation

  } else {
    // Object access/modification
    if (elements[0] == "scene") {
      manageSceneInterface(elements);
    }
  }
}

void CDebugConsole::manageSceneInterface(const vector<string>& elements)
{
  if (elements[1] == "set_light_color") {
    execute_scene_set_light_color(
      stringToInt(elements[2]),
      stringToInt(elements[3]),
      stringToInt(elements[4]),
      stringToInt(elements[5])
    );
  }
}

void CDebugConsole::execute_scene_set_light_color(u8 alpha, u8 red, u8 green, u8 blue)
{
  video::SColor color = video::SColor(alpha, red, green, blue);
  nEngine::CGame::getSceneManager()->setAmbientLight(color);
}

s32 CDebugConsole::stringToInt(const string& str)
{
  istringstream iss(str);
  s32 intVal = 0;
  iss >> intVal;
  return intVal;
}

CDebugConsole::~CDebugConsole()
{
  CommandTextInput->remove();
}

}
}
