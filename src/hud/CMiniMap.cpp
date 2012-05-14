/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/hud/CMiniMap.h"
#include "../../include/engine/CGame.h"
#include "../../include/3d/CPlayableCharacter.h"

namespace is06
{
namespace nHud
{

CMiniMap::CMiniMap(n3D::CPlayableCharacter* player) : CHud()
{
  AttachedPlayer = player;
}

//! Sets the map picture
void CMiniMap::setMap(EMiniMapIdentifier id)
{
  string fileName = "";

  switch (id) {
    case EMMI_ALPHA_ZONE: fileName = "debug/alpha_zone"; break;
    default: fileName = "global/default"; break;
  }

  Map = new CPicture(0, 0, 150, 150, "resource/hud/minimap/" + fileName + ".png", true);
  PlayerPosition = new CMiniMapArrow(video::SColor(255, 255, 0, 255));
  EntrancePosition = new CMiniMapArrow(video::SColor(255, 0, 0, 255));
}

//! Renders all mimi map elements
void CMiniMap::render()
{
  Map->render();
  PlayerPosition->render();
  EntrancePosition->render();

  // Player position
  PlayerPosition->setPosition(
    AttachedPlayer->getNode()->getPosition().X,
    AttachedPlayer->getNode()->getPosition().Z
  );

  // Player rotation
  PlayerPosition->setRotation(AttachedPlayer->getNode()->getRotation().Y);

  // Other entities position and rotation
  for (AttachedEntitiesIt = AttachedEntities.begin(); AttachedEntitiesIt != AttachedEntities.end(); AttachedEntitiesIt++) {
    // Get position of entity
  }
}

void CMiniMap::show()
{
  Map->show();
  PlayerPosition->show();
  EntrancePosition->show();
}

void CMiniMap::hide()
{
  Map->hide();
  PlayerPosition->hide();
  EntrancePosition->hide();
}

void CMiniMap::setOpacity(u8 value)
{
  Map->setOpacity(value);
  PlayerPosition->setOpacity(value);
  EntrancePosition->setOpacity(value);
}

CMiniMap::~CMiniMap()
{
  delete Map;
  delete PlayerPosition;
  delete EntrancePosition;
}

}
}
