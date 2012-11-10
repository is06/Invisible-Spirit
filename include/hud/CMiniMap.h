/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MINI_MAP_H__
#define __IS06_MINI_MAP_H__

#include "EMiniMapIdentifier.h"
#include "CMiniMapArrow.h"
#include "CHud.h"
#include "CPicture.h"

using namespace irr;

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
    void setWorldSize(f32 size);

  private:
    core::vector2df getMapCoordinates(const core::vector2df& worldCoords);

    core::vector2df Position;
    f32 WorldSize;

    CPicture* Map;
    CMiniMapArrow* PlayerPosition;
    CMiniMapArrow* EntrancePosition;

    n3D::CPlayableCharacter* AttachedPlayer;
    std::vector<n3D::CModelEntity*> AttachedEntities;
    std::vector<n3D::CModelEntity*>::iterator AttachedEntitiesIt;

    static constexpr f32 COEFF = 4954.94f;
};

}
}

#endif
