/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/NHud/NPart/CMiniMap.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/N3D/NCharacter/CPlayableCharacter.h"

using namespace irr;

namespace is06 { namespace NHud { namespace NPart {

f32 CMiniMap::Coeff = 4954.94f;

CMiniMap::CMiniMap(N3D::NCharacter::CPlayableCharacter* player) : NCore::CHudEntity()
{
    Map = NULL;
    EntrancePosition = NULL;
    PlayerPosition = NULL;

    AttachedPlayer = player;
    Position = core::vector2df(
        NEngine::NCore::CGame::ScreenPos.Hud.Right - 150.0f,
        NEngine::NCore::CGame::ScreenPos.Hud.Bottom + 150.0f
    );
}

//! Sets the map picture
void CMiniMap::setMap(EMiniMapIdentifier id)
{
    string fileName = "";

    switch (id) {
        default: fileName = "global/default"; break;
    }

    Map = new NPrimitive::CPicture(Position.X, Position.Y, 250, 250, "resource/hud/minimap/" + fileName + ".png", true);
    Map->setOpacity(0.8f);
    //Map->setRotation(45.0f);

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
    if (Map != NULL) {
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

void CMiniMap::setOpacity(f32 value)
{
    Opacity = value;
    Map->setOpacity(Map->getOpacity() * Opacity);
    PlayerPosition->setOpacity(Map->getOpacity() * Opacity);
    EntrancePosition->setOpacity(Map->getOpacity() * Opacity);
}

void CMiniMap::addOpacity(f32 value)
{
    Opacity += value;
    Map->setOpacity(Map->getOpacity() * Opacity);
    PlayerPosition->setOpacity(Map->getOpacity() * Opacity);
    EntrancePosition->setOpacity(Map->getOpacity() * Opacity);
}

void CMiniMap::subOpacity(f32 value)
{
    Opacity -= value;
    Map->setOpacity(Map->getOpacity() * Opacity);
    PlayerPosition->setOpacity(Map->getOpacity() * Opacity);
    EntrancePosition->setOpacity(Map->getOpacity() * Opacity);
}

f32 CMiniMap::getOpacity()
{
    return Opacity;
}

void CMiniMap::setWorldSize(f32 size)
{
    WorldSize = size;
}

core::vector2df CMiniMap::getMapCoordinates(const core::vector2df& worldCoords)
{
    return core::vector2df(
        (Position.X / Coeff) + ((worldCoords.X / Coeff) * (250.0f / WorldSize)),
        (Position.Y / Coeff) + ((worldCoords.Y / Coeff) * (250.0f / WorldSize))
    );
}

CMiniMap::~CMiniMap()
{
    delete Map;
    delete PlayerPosition;
    delete EntrancePosition;
}

}}}
