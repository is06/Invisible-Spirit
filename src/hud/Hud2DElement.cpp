/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/Settings.h"
#include "../../include/hud/Hud2DElement.h"

using namespace irr;

namespace is06
{
namespace nHud
{

u16 CHud2DElement::Indices[] = {2, 1, 3, 2, 0, 1};
core::matrix4 CHud2DElement::Mat;

CHud2DElement::CHud2DElement(f32 x, f32 y, f32 w, f32 h, bool alphaBlending) : CHud()
{
  Texture = NULL;
  Opacity = 255;

  // Visible on start
  Visible = true;

  // Animation Texture
  AnimSpeed = core::vector2df(0.0f, 0.0f);

  // Dimensions, position
  Size = core::dimension2df(w, h);
  Position = core::position2df(x, y);

  // Material
  Material.Lighting = false;
  Material.DiffuseColor.setAlpha(Opacity);

  if (alphaBlending) {
    // Alpha blending (alpha channel + alpha vertex)
    Material.MaterialType = video::EMT_ONETEXTURE_BLEND;
    Material.MaterialTypeParam = video::pack_texureBlendFunc(
      video::EBF_SRC_ALPHA,
      video::EBF_ONE_MINUS_SRC_ALPHA,
      video::EMFN_MODULATE_1X,
      video::EAS_TEXTURE | video::EAS_VERTEX_COLOR
    );
  } else {
    // Alpha vertex
    Material.MaterialType = video::EMT_TRANSPARENT_VERTEX_ALPHA;
  }

  // Texture filtering
  if (nEngine::CGame::Settings->getParamString("text", "texture_filter") == "anisotropic") {
    Material.setFlag(video::EMF_ANISOTROPIC_FILTER, true);
  } else if (nEngine::CGame::Settings->getParamString("text", "texture_filter") == "trilinear") {
    Material.setFlag(video::EMF_TRILINEAR_FILTER, true);
  } else if (nEngine::CGame::Settings->getParamString("text", "texture_filter") == "none") {
    Material.setFlag(video::EMF_BILINEAR_FILTER, false);
  }

  Material.setTexture(0, NULL);

  // Disable filtering clamp
  Material.TextureLayer[0].TextureWrapU = video::ETC_CLAMP_TO_EDGE;
  Material.TextureLayer[0].TextureWrapV = video::ETC_CLAMP_TO_EDGE;

  MinTextureOffset.X = 0.0f;
  MinTextureOffset.Y = 0.0f;
  MaxTextureOffset.X = 1.0f;
  MaxTextureOffset.Y = 1.0f;

  // Vertices creation
  Vertices[0] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 1, 0,
    video::SColor(255,255,255,255),
    MinTextureOffset.X, MinTextureOffset.Y);
  Vertices[1] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 0, 0,
    video::SColor(255,255,255,255),
    MaxTextureOffset.X, MinTextureOffset.Y);
  Vertices[2] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 1, 1,
    video::SColor(255,255,255,255),
    MinTextureOffset.X, MaxTextureOffset.Y);
  Vertices[3] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 0, 1,
    video::SColor(255,255,255,255),
    MaxTextureOffset.X, MaxTextureOffset.Y);
}

void CHud2DElement::render()
{
  // Déplacement et taille
  Vertices[0].Pos.X = (Position.X / COEFF) + (Size.Width / 2 / COEFF * -1);
  Vertices[0].Pos.Y = (Position.Y / COEFF) + (Size.Height / 2 / COEFF);
  Vertices[1].Pos.X = (Position.X / COEFF) + (Size.Width / 2 / COEFF);
  Vertices[1].Pos.Y = (Position.Y / COEFF) + (Size.Height / 2 / COEFF);
  Vertices[2].Pos.X = (Position.X / COEFF) + (Size.Width / 2 / COEFF * -1);
  Vertices[2].Pos.Y = (Position.Y / COEFF) + (Size.Height / 2 / COEFF * -1);
  Vertices[3].Pos.X = (Position.X / COEFF) + (Size.Width / 2 / COEFF);
  Vertices[3].Pos.Y = (Position.Y / COEFF) + (Size.Height / 2 / COEFF * -1);

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
  if (Visible) {
    // Texture of 2D element
    if (Texture) {
      Material.setTexture(0, Texture);
    }

    // Opacity
    Vertices[0].Color.setAlpha(Opacity);
    Vertices[1].Color.setAlpha(Opacity);
    Vertices[2].Color.setAlpha(Opacity);
    Vertices[3].Color.setAlpha(Opacity);

    // Rendering
    nEngine::CGame::getVideoDriver()->setMaterial(Material);
    nEngine::CGame::getVideoDriver()->setTransform(video::ETS_VIEW, Mat);
    nEngine::CGame::getVideoDriver()->drawIndexedTriangleList(Vertices, 4, Indices, 2);
    nEngine::CGame::getVideoDriver()->setTransform(video::ETS_WORLD, Mat);
  }
}

void CHud2DElement::setSize(f32 w, f32 h)
{
  Size.Width = w;
  Size.Height = h;
}

void CHud2DElement::setPosition(f32 x, f32 y)
{
  Position.X = x;
  Position.Y = y;
}

void CHud2DElement::setTextureOffset(const core::vector2df& min, const core::vector2df& max)
{
  MinTextureOffset = min;
  MaxTextureOffset = max;
}

void CHud2DElement::addX(f32 val)
{
  Position.X += val;
}

void CHud2DElement::subX(f32 val)
{
  Position.X -= val;
}

void CHud2DElement::setX(f32 val)
{
  Position.X = val;
}

void CHud2DElement::addY(f32 val)
{
  Position.Y += val;
}

void CHud2DElement::subY(f32 val)
{
  Position.Y -= val;
}

void CHud2DElement::setY(f32 val)
{
  Position.Y = val;
}

void CHud2DElement::setWidth(f32 val)
{
  Size.Width = val;
}

void CHud2DElement::setHeight(f32 val)
{
  Size.Height = val;
}

f32 CHud2DElement::getX()
{
  return Position.X;
}

f32 CHud2DElement::getY()
{
  return Position.Y;
}

f32 CHud2DElement::getWidth()
{
  return Size.Width;
}

f32 CHud2DElement::getHeight()
{
  return Size.Height;
}

void CHud2DElement::startUVAnimation(f32 uSpeed, f32 vSpeed)
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
  Visible = false;
}

void CHud2DElement::show()
{
  Visible = true;
}

void CHud2DElement::setOpacity(u8 value)
{
  Opacity = value;
}

void CHud2DElement::diffuse(video::SColor color)
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
