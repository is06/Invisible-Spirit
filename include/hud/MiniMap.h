/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MINI_MAP_H__
#define __IS06_MINI_MAP_H__

#include "MiniMapIdentifier.h"
#include "MiniMapArrow.h"
#include "Hud.h"
#include "Picture.h"

namespace is06
{
namespace nHud
{

class CMiniMap : public CHud
{
  public:
    CMiniMap(n3D::CPlayableCharacter* player);
    ~CMiniMap();

    void render();
    void hide();
    void show();
    void setOpacity(u8 value);
    void setMap(EMiniMapIdentifier id);

  private:
    CPicture* Map;
    CMiniMapArrow* PlayerPosition;
    CMiniMapArrow* EntrancePosition;

    n3D::CPlayableCharacter* AttachedPlayer;
    std::vector<n3D::CModelEntity*> AttachedEntities;
    std::vector<n3D::CModelEntity*>::iterator AttachedEntitiesIt;
};

}
}

#endif
