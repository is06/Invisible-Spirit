/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/CGame.h"
#include "../../include/hud/CMiniMapArrow.h"

using namespace irr;

namespace is06
{
namespace nHud
{

CMiniMapArrow::CMiniMapArrow(video::SColor color) : CHud()
{
  Visible = true;

  Material.DiffuseColor = color;
  Material.Wireframe = false;
  Material.Lighting = false;

  Vertices[0] = video::S3DVertex(0, 0, 10, 1, 1, 0, color, 0, 0);
  Vertices[1] = video::S3DVertex(0, 10, 0, 1, 1, 0, color, 0, 0);
  Vertices[2] = video::S3DVertex(10, 0, 0, 1, 1, 0, color, 0, 0);

  Indices[0] = 0;
  Indices[1] = 1;
  Indices[2] = 2;
}

void CMiniMapArrow::render()
{
  core::matrix4 mat;

  Material.DiffuseColor.setAlpha(Opacity);

  if (Visible) {
    nEngine::CGame::getVideoDriver()->setMaterial(Material);
    nEngine::CGame::getVideoDriver()->setTransform(video::ETS_VIEW, AbsoluteTransformation);
    nEngine::CGame::getVideoDriver()->drawIndexedTriangleList(Vertices, 3, Indices, 1);
    nEngine::CGame::getVideoDriver()->setTransform(video::ETS_WORLD, mat);
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
  AbsoluteTransformation.setTranslation(core::vector3df(x, 0.0f, y));
}

void CMiniMapArrow::setRotation(f32 value)
{
  AbsoluteTransformation.setRotationDegrees(core::vector3df(0.0f, value, 0.0f));
}

CMiniMapArrow::~CMiniMapArrow()
{

}

}
}
