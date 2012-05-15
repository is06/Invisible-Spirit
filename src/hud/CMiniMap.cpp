/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/hud/CMiniMap.h"
#include "../../include/engine/CGame.h"
#include "../../include/3d/CPlayableCharacter.h"

using namespace irr;

namespace is06
{
namespace nHud
{

CMiniMap::CMiniMap(n3D::CPlayableCharacter* player) : CHud()
{
  AttachedPlayer = player;
  Position = core::vector2df(
    nEngine::CGame::ScreenPos.Right - 150.0f,
    nEngine::CGame::ScreenPos.Top - 150.0f
  );
}

//! Sets the map picture
void CMiniMap::setMap(EMiniMapIdentifier id)
{
  string fileName = "";

  switch (id) {
    case EMMI_ALPHA_ZONE: fileName = "debug/alpha_zone"; break;
    default: fileName = "global/default"; break;
  }

  Map = new CPicture(Position.X, Position.Y, 250, 250, "resource/hud/minimap/" + fileName + ".png", true);
  Map->setOpacity(127);

  // Entrance
  EntrancePosition = new CMiniMapArrow(video::SColor(255, 255, 0, 0));
  EntrancePosition->setRotation(AttachedPlayer->getNode()->getRotation().Y);
  core::vector2df playerCoords = getMapCoordinates(core::vector2df(
    AttachedPlayer->getNode()->getPosition().X,
    AttachedPlayer->getNode()->getPosition().Z
  ));
  EntrancePosition->setPosition(playerCoords.X, playerCoords.Y);

  // Player
  PlayerPosition = new CMiniMapArrow(video::SColor(255, 255, 255, 0));
}

//! Renders all mimi map elements
void CMiniMap::render()
{
  Map->render();
  EntrancePosition->render();
  PlayerPosition->render();

  core::vector2df playerCoords = getMapCoordinates(core::vector2df(
    AttachedPlayer->getNode()->getPosition().X,
    AttachedPlayer->getNode()->getPosition().Z
  ));

  // Player position
  PlayerPosition->setPosition(playerCoords.X, playerCoords.Y);

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

void CMiniMap::setWorldSize(f32 size)
{
  WorldSize = size;
}

core::vector2df CMiniMap::getMapCoordinates(const core::vector2df& worldCoords)
{
  return core::vector2df(
    (Position.X / COEFF) + (worldCoords.X / COEFF),
    (Position.Y / COEFF) + (worldCoords.Y / COEFF)
  );
}

CMiniMap::~CMiniMap()
{
  delete Map;
  delete PlayerPosition;
  delete EntrancePosition;
}

}
}
