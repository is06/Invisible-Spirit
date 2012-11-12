/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/CMenu.h"
#include "../../include/hud/CMenuOption.h"
#include "../../include/hud/CPicture.h"

namespace is06
{
namespace nHud
{

//! \todo comment this function
CMenu::CMenu(f32 x, f32 y, f32 width, u8 height, EMenuStyle style) : CHud()
{
  LastInsertedIndex = 0;
  CurrentOption = 0;
  DefaultOption = 0;

  Width = width;
  Height = height;
  Position = core::position2df(x, y);

  LoopMode = false;

  Style = style;

  Cursor = new CPicture(x - 16, y, 32, 32, "resource/hud/menus/cursor.png");
}

//! \todo comment this function
void CMenu::render()
{
  CHud::render();
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->render();
  }
  Cursor->render();
}

//! \todo comment this function
void CMenu::addOption(EMenuIcon icon, const string& title)
{
  f32 posY = Position.Y + (LastInsertedIndex * -1 * 40);
  Options.insert(make_pair(LastInsertedIndex, new CMenuOption(icon, title, Position.X, posY, Style)));
  LastInsertedIndex++;
}

//! \todo comment this function
void CMenu::nextOption()
{
  if (LoopMode) {
    if (CurrentOption > Options.size()) {
      CurrentOption = 0;
      CurrentOption++;
      Cursor->subY(40);
    }
  } else {
    if (CurrentOption < Options.size() - 1) {
      CurrentOption++;
      Cursor->subY(40);
    }
  }
}

//! \todo comment this function
void CMenu::prevOption()
{
  if (LoopMode) {
    if (CurrentOption <= 0) {
      CurrentOption = Options.size();
      CurrentOption--;
      Cursor->addY(40);
    }
  } else {
    if (CurrentOption > 0) {
      CurrentOption--;
      Cursor->addY(40);
    }
  }
}

//! \todo comment this function
void CMenu::firstOption()
{
  CurrentOption = 0;
}

//! \todo comment this function
void CMenu::lastOption()
{
  CurrentOption = Options.size() - 1;
}

//! \todo write this function
void CMenu::removeOption(u16 index)
{
  /*
  options.erase(index);
  lastInsertedIndex = 0;
  for(optionsIt = options.begin(); optionsIt != options.end(); ++optionsIt) {
    *optionsIt = make_pair(lastInsertedIndex, optionsIt->second);
    lastInsertedIndex++;
  }
  */
}

//! \todo comment this function
void CMenu::show()
{
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->show();
  }
}

//! \todo comment this function
void CMenu::hide()
{
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->hide();
  }
}

//! \todo comment this function
void CMenu::setOpacity(u8 value)
{
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->setOpacity(value);
  }
}

//! \todo comment this function
CMenuOption* CMenu::getOption(u16 index)
{
  return Options[index];
}

//! \todo comment this function
u16 CMenu::getCurrentOption()
{
  return CurrentOption;
}

//! \todo comment this function
CMenu::~CMenu()
{
  delete Cursor;
}

}
}
