/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt

*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/debug/ColorProperty.h"
#include "../../include/Game.h"
#include "../../include/EventManager.h"

using namespace irr;
using namespace std;

ColorProperty::ColorProperty(const video::SColor& initialColor) {
  mainWindow = NULL;

  compABar = NULL;
  compAEdit = NULL;
  compAText = NULL;
  compRBar = NULL;
  compREdit = NULL;
  compRText = NULL;
  compGBar = NULL;
  compGEdit = NULL;
  compGText = NULL;
  compBBar = NULL;
  compBEdit = NULL;
  compBText = NULL;

  mainWindow = Game::getDebugGUI()->addWindow(core::recti(core::vector2di(50, 50), core::vector2di(300, 250)), false, L"Modifier la couleur");

  compABar = Game::getDebugGUI()->addScrollBar(true, core::recti(core::vector2di(50, 30), core::vector2di(210, 50)), mainWindow, 1001);
  compRBar = Game::getDebugGUI()->addScrollBar(true, core::recti(core::vector2di(50, 60), core::vector2di(210, 80)), mainWindow, 1002);
  compGBar = Game::getDebugGUI()->addScrollBar(true, core::recti(core::vector2di(50, 90), core::vector2di(210, 110)), mainWindow, 1003);
  compBBar = Game::getDebugGUI()->addScrollBar(true, core::recti(core::vector2di(50, 120), core::vector2di(210, 140)), mainWindow, 1004);

  compABar->setMin(0); compABar->setMax(255); compABar->setPos(initialColor.getAlpha());
  compRBar->setMin(0); compRBar->setMax(255); compRBar->setPos(initialColor.getRed());
  compGBar->setMin(0); compGBar->setMax(255); compGBar->setPos(initialColor.getGreen());
  compBBar->setMin(0); compBBar->setMax(255); compBBar->setPos(initialColor.getBlue());

  compAText = Game::getDebugGUI()->addStaticText(L"Alpha", core::recti(core::vector2di(8, 34), core::vector2di(42, 50)), false, true, mainWindow);
  compRText = Game::getDebugGUI()->addStaticText(L"Rouge", core::recti(core::vector2di(8, 64), core::vector2di(42, 80)), false, true, mainWindow);
  compGText = Game::getDebugGUI()->addStaticText(L"Vert", core::recti(core::vector2di(8, 94), core::vector2di(42, 110)), false, true, mainWindow);
  compBText = Game::getDebugGUI()->addStaticText(L"Bleu", core::recti(core::vector2di(8, 124), core::vector2di(42, 140)), false, true, mainWindow);

  compAEdit = Game::getDebugGUI()->addEditBox(convertIntToString(initialColor.getAlpha()).c_str(), core::recti(core::vector2di(218, 30), core::vector2di(242, 50)), true, mainWindow);
  compREdit = Game::getDebugGUI()->addEditBox(convertIntToString(initialColor.getRed()).c_str(), core::recti(core::vector2di(218, 60), core::vector2di(242, 80)), true, mainWindow);
  compGEdit = Game::getDebugGUI()->addEditBox(convertIntToString(initialColor.getGreen()).c_str(), core::recti(core::vector2di(218, 90), core::vector2di(242, 110)), true, mainWindow);
  compBEdit = Game::getDebugGUI()->addEditBox(convertIntToString(initialColor.getBlue()).c_str(), core::recti(core::vector2di(218, 120), core::vector2di(242, 140)), true, mainWindow);

  okButton = Game::getDebugGUI()->addButton(core::recti(core::vector2di(192, 172), core::vector2di(242, 192)), mainWindow, -1, L"OK");
  cancelButton = Game::getDebugGUI()->addButton(core::recti(core::vector2di(132, 172), core::vector2di(182, 192)), mainWindow, -1, L"Annuler");
}

void ColorProperty::events() {
  switch(Game::getEventManager()->getGUIEvent().EventType) {
    case gui::EGET_SCROLL_BAR_CHANGED: {
      gui::IGUIElement* bar = Game::getEventManager()->getGUIEvent().Caller;
      switch(bar->getID()) {
        case 1001:
          compAEdit->setText(convertIntToString(compABar->getPos()).c_str());
        break;
        case 1002:
          compREdit->setText(convertIntToString(compRBar->getPos()).c_str());
        break;
        case 1003:
          compGEdit->setText(convertIntToString(compGBar->getPos()).c_str());
        break;
        case 1004:
          compBEdit->setText(convertIntToString(compBBar->getPos()).c_str());
        break;
      }
    } break;
    default: {

    } break;
  }
}

core::stringw ColorProperty::convertIntToString(u32 value) {
  core::stringw final;

  wostringstream oss;
  oss << value;
  wstring str = oss.str();

  final.append(str.c_str());

  return final;
}

ColorProperty::~ColorProperty() {
  compABar->remove();
  compRBar->remove();
  compGBar->remove();
  compBBar->remove();

  compAText->remove();
  compRText->remove();
  compGText->remove();
  compBText->remove();

  compAEdit->remove();
  compREdit->remove();
  compGEdit->remove();
  compBEdit->remove();

  okButton->remove();
  cancelButton->remove();

  mainWindow->remove();
}
