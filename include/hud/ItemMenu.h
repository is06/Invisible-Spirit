/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ITEM_MENU_H__
#define __IS06_ITEM_MENU_H__

#include "GameplaySubMenu.h"

namespace is06
{
namespace nHud
{
namespace nMenu
{

class CItemMenu : public CGameplaySubMenu
{
  public:
    CItemMenu();
    ~CItemMenu();

    void render();
};

}
}
}

#endif

