/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/CGame.h"
#include "../../include/Engine/CEventManager.h"
#include "../../include/Hud/CMiniMapArrow.h"

using namespace irr;

namespace is06
{
namespace NHud
{

CMiniMapArrow::CMiniMapArrow(video::SColor color) : CHud()
{
  AbsoluteTransformation = core::matrix4();
  AbsoluteTransformation.makeIdentity();

  Visible = true;

  Material.DiffuseColor = color;
  Material.Wireframe = false;
  Material.Lighting = false;

  Vertices[0] = video::S3DVertex(
    core::vector3df(-0.0014f, 0.0027f, 0.1f), // Position
    core::vector3df(1.0f, 1.0f, 0.0f), // Normal
    color, // Color
    core::vector2df(0.0f, 0.0f) // Texture coords
  );
  Vertices[1] = video::S3DVertex(
    core::vector3df(0.0014f, 0.0027f, 0.1f), // Position
    core::vector3df(1.0f, 0.0f, 0.0f), // Normal
    color, // Color
    core::vector2df(0.0f, 0.0f) // Texture coords
  );
  Vertices[2] = video::S3DVertex(
    core::vector3df(0.0f, -0.0027f, 0.1f), // Position
    core::vector3df(0.0f, 1.0f, 1.0f), // Normal
    color, // Color
    core::vector2df(0.0f, 0.0f) // Texture coords
  );

  Indices[0] = 0;
  Indices[1] = 1;
  Indices[2] = 2;
}

void CMiniMapArrow::render()
{
  core::matrix4 mat;
  mat.makeIdentity();

  if (NEngine::CGame::getEventManager()->isKeyDown(KEY_NUMPAD7)) {
    Vertices[0].Pos.X += 0.00001f;
    Vertices[1].Pos.X -= 0.00001f;
  }
  if (NEngine::CGame::getEventManager()->isKeyDown(KEY_NUMPAD8)) {
    Vertices[0].Pos.Y += 0.00001f;
    Vertices[1].Pos.Y += 0.00001f;
    Vertices[2].Pos.Y -= 0.00001f;
  }
  if (NEngine::CGame::getEventManager()->isKeyDown(KEY_NUMPAD4)) {
    Vertices[0].Pos.X -= 0.00001f;
    Vertices[1].Pos.X += 0.00001f;
  }
  if (NEngine::CGame::getEventManager()->isKeyDown(KEY_NUMPAD5)) {
    Vertices[0].Pos.Y -= 0.00001f;
    Vertices[1].Pos.Y -= 0.00001f;
    Vertices[2].Pos.Y += 0.00001f;
  }

  Material.DiffuseColor.setAlpha(Opacity);

  if (Visible) {
    NEngine::CGame::getVideoDriver()->setMaterial(Material);
    NEngine::CGame::getVideoDriver()->setTransform(video::ETS_VIEW, AbsoluteTransformation);
    NEngine::CGame::getVideoDriver()->drawIndexedTriangleList(Vertices, 3, Indices, 1);
    NEngine::CGame::getVideoDriver()->setTransform(video::ETS_WORLD, mat);
  }
}

void CMiniMapArrow::show()
{
  Visible = true;
}

void CMiniMapArrow::hide()
{
  Visible = false;
}

void CMiniMapArrow::setOpacity(u8 value)
{
  Opacity = value;
}

void CMiniMapArrow::setPosition(f32 x, f32 y)
{
  AbsoluteTransformation.setTranslation(core::vector3df(x, y, 0.0f));
}

//! Rotates the arrow according to a Y axis rotation value
void CMiniMapArrow::setRotation(f32 value)
{
  value *= -1;
  AbsoluteTransformation.setRotationDegrees(core::vector3df(0.0f, 0.0f, value));
}

CMiniMapArrow::~CMiniMapArrow()
{

}

}
}
