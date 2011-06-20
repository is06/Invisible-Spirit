/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt

*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;

MapEditor::MapEditor() {
  active = false;
  mainMenu = NULL;
  cp = NULL;
}

void MapEditor::events() {
  if(active) {
    cp->events();
  }
}

void MapEditor::toggle() {
  if(active) {
    active = false;
    if(mainMenu) {
      delete mainMenu;
    }
  } else {
    openMapProperties();
    active = true;
  }
}

void MapEditor::openMapProperties() {
  mainMenu = Game::getDebugGUI()->addWindow(core::recti(core::vector2di(0, 0), core::vector2di(200, 400)), false, L"Propriétés de la map", 0, 1000);
  gui::IGUIEditBox* mapNameEditBox = Game::getDebugGUI()->addEditBox(L"MAP_TEST", core::recti(core::vector2di(100, 24), core::vector2di(190, 44)), true);
  //gui::IGUIButton* btn = Game::getDebugGUI()->addButton(core::recti(core::vector2di(4, 20), core::vector2di(44, 20)), mainMenu, 1001, L"Test");
  mainMenu->addChild(mapNameEditBox);
  //mainMenu->addChild(btn);

  cp = new ColorProperty(video::SColor(127, 0, 255, 50));
}

bool MapEditor::isRunning() {
  return active;
}

MapEditor::~MapEditor() {
  if(mainMenu) {
    delete mainMenu;
    delete cp;
  }
}
