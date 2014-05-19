/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PART_MINI_MAP_H__
#define __IS06_HUD_PART_MINI_MAP_H__

#include "EMiniMapIdentifier.h"
#include "CMiniMapArrow.h"
#include "../NCore/CHudEntity.h"
#include "../NPrimitive/CPicture.h"

using namespace irr;

namespace is06 { namespace NHud { namespace NPart {

//! A mini map to show the player where his (or her) character is
class CMiniMap : public NCore::CHudEntity
{
public:
  CMiniMap(N3D::NCharacter::CPlayableCharacter* player);
  ~CMiniMap();

  void render();
  void hide();
  void show();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();
  void setMap(EMiniMapIdentifier id);
  void setWorldSize(f32 size);

private:
  core::vector2df getMapCoordinates(const core::vector2df& worldCoords);

  core::vector2df Position;
  f32 WorldSize;
  f32 Opacity;

  NPrimitive::CPicture* Map;
  CMiniMapArrow* PlayerPosition;
  CMiniMapArrow* EntrancePosition;

  N3D::NCharacter::CPlayableCharacter* AttachedPlayer;
  std::vector<N3D::NPrimitive::CModelEntity*> AttachedEntities;
  std::vector<N3D::NPrimitive::CModelEntity*>::iterator AttachedEntitiesIt;

  static f32 Coeff;
};

}}}

#endif
