/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_WEAPON_MENU_H__
#define __IS06_WEAPON_MENU_H__

#include "CGameplaySubMenu.h"

namespace is06
{
namespace nHud
{
namespace nMenu
{

class CWeaponMenu : public CGameplaySubMenu
{
  public:
    CWeaponMenu();
    ~CWeaponMenu();

    void render();
};

}
}
}

#endif
