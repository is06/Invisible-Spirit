/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TALES_MENU_H__
#define __IS06_TALES_MENU_H__

#include "GameplaySubMenu.h"

using namespace irr;
using namespace std;

class TalesMenu : public GameplaySubMenu
{
  public:
    TalesMenu();
    ~TalesMenu();

    void render(Keyboard* keyboard);
};

#endif
