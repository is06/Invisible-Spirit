/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Hud2DElement.h"
#include "../../include/Game.h"

namespace is06
{
namespace hud
{

irr::u16 CHud2DElement::Indices[] = {2, 1, 3, 2, 0, 1};
irr::core::matrix4 CHud2DElement::Mat;

CHud2DElement::CHud2DElement(irr::f32 x, irr::f32 y, irr::f32 w, irr::f32 h) : CHud()
{
  Texture = NULL;
  Opacity = 255;

  // Visible on start
  IsVisible = true;

  // Animation Texture
  AnimSpeed = irr::core::vector2df(0.0f, 0.0f);

  // Dimensions, position
  Size = irr::core::dimension2df(w, h);
  Pos = irr::core::position2df(x, y);

  // Material
  Material.Lighting = false;
  Material.DiffuseColor.setAlpha(Opacity);

  // Diffuse effect
  /*
  Material.DiffuseColor.setRed(255);
  Material.DiffuseColor.setGreen(255);
  Material.DiffuseColor.setBlue(255);
  */

  // Wireframe effect (debug purpose?)
  //Material.Wireframe = true;

  // Diffuse shader
  Material.MaterialType = (irr::video::E_MATERIAL_TYPE)engine::CGame::Shaders.Diffuse;

  //material.setFlag(video::EMF_ANISOTROPIC_FILTER, true);
  Material.setTexture(0, NULL);

  // Disable filtering clamp
  Material.TextureLayer[0].TextureWrapU = irr::video::ETC_CLAMP_TO_EDGE;
  Material.TextureLayer[0].TextureWrapV = irr::video::ETC_CLAMP_TO_EDGE;

  MinTextureOffset.X = 0.0f;
  MinTextureOffset.Y = 0.0f;
  MaxTextureOffset.X = 1.0f;
  MaxTextureOffset.Y = 1.0f;

  // Vertices creation
  Vertices[0] = irr::video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 1, 0,
    irr::video::SColor(255,255,255,255),
    MinTextureOffset.X, MinTextureOffset.Y);
  Vertices[1] = irr::video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 0, 0,
    irr::video::SColor(255,255,255,255),
    MaxTextureOffset.X, MinTextureOffset.Y);
  Vertices[2] = irr::video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 1, 1,
    irr::video::SColor(255,255,255,255),
    MinTextureOffset.X, MaxTextureOffset.Y);
  Vertices[3] = irr::video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 0, 1,
    irr::video::SColor(255,255,255,255),
    MaxTextureOffset.X, MaxTextureOffset.Y);
}

void CHud2DElement::render()
{
  // Déplacement et taille
  Vertices[0].Pos.X = (Pos.X / COEFF) + (Size.Width / 2 / COEFF * -1);
  Vertices[0].Pos.Y = (Pos.Y / COEFF) + (Size.Height / 2 / COEFF);
  Vertices[1].Pos.X = (Pos.X / COEFF) + (Size.Width / 2 / COEFF);
  Vertices[1].Pos.Y = (Pos.Y / COEFF) + (Size.Height / 2 / COEFF);
  Vertices[2].Pos.X = (Pos.X / COEFF) + (Size.Width / 2 / COEFF * -1);
  Vertices[2].Pos.Y = (Pos.Y / COEFF) + (Size.Height / 2 / COEFF * -1);
  Vertices[3].Pos.X = (Pos.X / COEFF) + (Size.Width / 2 / COEFF);
  Vertices[3].Pos.Y = (Pos.Y / COEFF) + (Size.Height / 2 / COEFF * -1);

  // Offset de texture
  Vertices[0].TCoords.X = MinTextureOffset.X;
  Vertices[0].TCoords.Y = MinTextureOffset.Y;
  Vertices[1].TCoords.X = MaxTextureOffset.X;
  Vertices[1].TCoords.Y = MinTextureOffset.Y;
  Vertices[2].TCoords.X = MinTextureOffset.X;
  Vertices[2].TCoords.Y = MaxTextureOffset.Y;
  Vertices[3].TCoords.X = MaxTextureOffset.X;
  Vertices[3].TCoords.Y = MaxTextureOffset.Y;

  // Animation UV
  if (AnimSpeed.X != 0.0f || AnimSpeed.Y != 0.0f) {
    Vertices[0].TCoords.X += AnimSpeed.X;
    Vertices[0].TCoords.Y += AnimSpeed.Y;
    Vertices[1].TCoords.X += AnimSpeed.X;
    Vertices[1].TCoords.Y += AnimSpeed.Y;
    Vertices[2].TCoords.X += AnimSpeed.X;
    Vertices[2].TCoords.Y += AnimSpeed.Y;
    Vertices[3].TCoords.X += AnimSpeed.X;
    Vertices[3].TCoords.Y += AnimSpeed.Y;
  }

  // Draws vertices of 2D element only if visible
  if (IsVisible) {
    // Opacity
    if (Opacity < 255) {
      Material.DiffuseColor.setAlpha(Opacity);
    }

    // Texture of 2D element
    if (Texture) {
      Material.setTexture(0, Texture);
    }

    engine::CGame::getVideoDriver()->setMaterial(Material);
    engine::CGame::getVideoDriver()->setTransform(irr::video::ETS_VIEW, Mat);
    engine::CGame::getVideoDriver()->drawIndexedTriangleList(Vertices, 4, Indices, 2);
    engine::CGame::getVideoDriver()->setTransform(irr::video::ETS_WORLD, Mat);
  }
}

/**
 * Change la taille de l'élément d'interface (déforme la texture)
 */
void CHud2DElement::setSize(irr::f32 w, irr::f32 h)
{
  Size.Width = w;
  Size.Height = h;
}

void CHud2DElement::setPosition(irr::f32 x, irr::f32 y)
{
  Pos.X = x;
  Pos.Y = y;
}

void CHud2DElement::setTextureOffset(const irr::core::vector2df& min, const irr::core::vector2df& max)
{
  MinTextureOffset = min;
  MaxTextureOffset = max;
}

void CHud2DElement::addX(irr::f32 val)
{
  Pos.X += val;
}

void CHud2DElement::subX(irr::f32 val)
{
  Pos.X -= val;
}

void CHud2DElement::setX(irr::f32 val)
{
  Pos.X = val;
}

void CHud2DElement::addY(irr::f32 val)
{
  Pos.Y += val;
}

void CHud2DElement::subY(irr::f32 val)
{
  Pos.Y -= val;
}

void CHud2DElement::setY(irr::f32 val)
{
  Pos.Y = val;
}

void CHud2DElement::setWidth(irr::f32 val)
{
  Size.Width = val;
}

void CHud2DElement::setHeight(irr::f32 val)
{
  Size.Height = val;
}

irr::f32 CHud2DElement::getX()
{
  return Pos.X;
}

irr::f32 CHud2DElement::getY()
{
  return Pos.Y;
}

irr::f32 CHud2DElement::getWidth()
{
  return Size.Width;
}

irr::f32 CHud2DElement::getHeight()
{
  return Size.Height;
}

void CHud2DElement::startUVAnimation(irr::f32 uSpeed, irr::f32 vSpeed)
{
  AnimSpeed.X = uSpeed;
  AnimSpeed.Y = vSpeed;
}

void CHud2DElement::stopUVAnimation()
{
  AnimSpeed.X = 0.0f;
  AnimSpeed.Y = 0.0f;
}

void CHud2DElement::hide()
{
  IsVisible = false;
}

void CHud2DElement::show()
{
  IsVisible = true;
}

void CHud2DElement::setOpacity(irr::u8 value)
{
  Opacity = value;
}

void CHud2DElement::diffuse(irr::video::SColor color)
{
  Opacity = color.getAlpha();
  Material.DiffuseColor = color;
}

CHud2DElement::~CHud2DElement()
{
  Texture = NULL;
}

}
}
