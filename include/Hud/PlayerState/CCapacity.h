/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYER_STATE_CAPACITY_H__
#define __IS06_PLAYER_STATE_CAPACITY_H__

#include "../CHud.h"

namespace is06
{
namespace NHud
{

class CCapacity : public CHud
{
  public:
    CCapacity();
    ~CCapacity();

    void render();

  private:
    CPicture* Icon;
    CText* Value;
};

}
}

#endif
