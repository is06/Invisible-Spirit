/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../../include/ref/core.h"
#include "../../../../include/gui/menus/common/Menu.h"
#include "../../../../include/gui/menus/common/MenuOption.h"
#include "../../../../include/gui/Picture.h"

namespace is06
{
namespace hud
{

CMenu::CMenu(irr::f32 x, irr::f32 y, irr::f32 width, irr::u8 height, EMenuStyle style) : CHud()
{
  LastInsertedIndex = 0;
  CurrentOption = 0;
  DefaultOption = 0;

  CurrentWidth = width;
  CurrentHeight = height;
  Pos = irr::core::position2df(x, y);

  LoopMode = false;

  CurrentStyle = style;

  Cursor = new CPicture(x - 16, y, 32, 32, "resource/hud/menus/cursor.png");
}

void CMenu::render()
{
  CHud::render();
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->render();
  }
  Cursor->render();
}

void CMenu::addOption(EMenuIcon icon, const std::string& title)
{
  irr::f32 posY = Pos.Y + (LastInsertedIndex * -1 * 40);
  Options.insert(std::make_pair(LastInsertedIndex, new CMenuOption(icon, title, Pos.X, posY, CurrentStyle)));
  LastInsertedIndex++;
}

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

void CMenu::firstOption()
{
  CurrentOption = 0;
}

void CMenu::lastOption()
{
  CurrentOption = Options.size() - 1;
}

/**
 * @todo
 */
void CMenu::removeOption(irr::u16 index)
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

void CMenu::show()
{
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->show();
  }
}

void CMenu::hide()
{
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->hide();
  }
}

void CMenu::setOpacity(irr::u8 value)
{
  for (OptionsIt = Options.begin(); OptionsIt != Options.end(); OptionsIt++) {
    OptionsIt->second->setOpacity(value);
  }
}

/**
 * @todo
 */
CMenuOption* CMenu::getOption(irr::u16 index)
{
  return Options[index];
}

irr::u16 CMenu::getCurrentOption()
{
  return CurrentOption;
}

CMenu::~CMenu()
{
  delete Cursor;
}

}
}
