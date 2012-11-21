/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CSettings.h"
#include "../../include/hud/CHud2DElement.h"

using namespace irr;

namespace is06
{
namespace nHud
{

f32 CHud2DElement::FarValue = 0.1f;
f32 CHud2DElement::Coeff = 4954.94f;
u16 CHud2DElement::Indices[] = {2, 1, 3, 0, 1, 2};
core::matrix4 CHud2DElement::Mat;

CHud2DElement::CHud2DElement(f32 x, f32 y, f32 w, f32 h, bool alphaBlending) : CHud()
{
  AbsoluteTransformation = core::matrix4();
  AbsoluteTransformation.makeIdentity();

  Texture = NULL;
  Opacity = 255;

  // Visible on start
  Visible = true;

  // Animation Texture
  AnimSpeed = core::vector2df(0.0f, 0.0f);

  // Dimensions, position
  Size = core::dimension2df(w, h);

  // Material
  Material.Lighting = false;
  Material.DiffuseColor.setAlpha(Opacity);

  if (alphaBlending) {
    // Alpha blending (alpha channel + alpha vertex)
    Material.MaterialType = video::EMT_ONETEXTURE_BLEND;
    Material.MaterialTypeParam = video::pack_textureBlendFunc(
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

  setPosition(x, y);

  Vertices[0] = video::S3DVertex(
    core::vector3df((w/2/Coeff*-1), (h/2/Coeff), FarValue), // Position
    core::vector3df(1.0f, 1.0f, 0.0f), // Normal
    Material.DiffuseColor, // Color
    core::vector2df(MinTextureOffset.X, MinTextureOffset.Y) // Texture coords
  );
  Vertices[1] = video::S3DVertex(
    core::vector3df((w/2/Coeff), (h/2/Coeff), FarValue), // Position
    core::vector3df(1.0f, 0.0f, 0.0f), // Normal
    Material.DiffuseColor, // Color
    core::vector2df(MaxTextureOffset.X, MinTextureOffset.Y) // Texture coords
  );
  Vertices[2] = video::S3DVertex(
    core::vector3df((w/2/Coeff*-1), (h/2/Coeff*-1), FarValue), // Position
    core::vector3df(0.0f, 1.0f, 1.0f), // Normal
    Material.DiffuseColor, // Color
    core::vector2df(MinTextureOffset.X, MaxTextureOffset.Y) // Texture coords
  );
  Vertices[3] = video::S3DVertex(
    core::vector3df((w/2/Coeff), (h/2/Coeff*-1), FarValue), // Position
    core::vector3df(0.0f, 1.0f, 1.0f), // Normal
    Material.DiffuseColor, // Color
    core::vector2df(MaxTextureOffset.X, MaxTextureOffset.Y) // Texture coords
  );
}

void CHud2DElement::render()
{
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

    for (int i = 0; i <= 3; i++) {
      // Color
      Vertices[i].Color = Material.DiffuseColor;
      // Opacity
      Vertices[i].Color.setAlpha(Opacity);
    }

    // Rendering
    nEngine::CGame::getVideoDriver()->setMaterial(Material);
    nEngine::CGame::getVideoDriver()->setTransform(video::ETS_VIEW, AbsoluteTransformation);
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
  AbsoluteTransformation.setTranslation(core::vector3df(x/Coeff, y/Coeff, 0.0f));
}

void CHud2DElement::setRotation(f32 value)
{
  value *= -1;
  AbsoluteTransformation.setRotationDegrees(core::vector3df(0.0f, 0.0f, value));
}

void CHud2DElement::setTextureOffset(const core::vector2df& min, const core::vector2df& max)
{
  MinTextureOffset = min;
  MaxTextureOffset = max;
}

void CHud2DElement::addX(f32 val)
{
  AbsoluteTransformation.setTranslation(core::vector3df(
    AbsoluteTransformation.getTranslation().X + (val/Coeff),
    AbsoluteTransformation.getTranslation().Y,
    AbsoluteTransformation.getTranslation().Z
  ));
  //Position.X += val;
}

void CHud2DElement::subX(f32 val)
{
  AbsoluteTransformation.setTranslation(core::vector3df(
    AbsoluteTransformation.getTranslation().X - (val/Coeff),
    AbsoluteTransformation.getTranslation().Y,
    AbsoluteTransformation.getTranslation().Z
  ));
  //Position.X -= val;
}

void CHud2DElement::setX(f32 val)
{
  AbsoluteTransformation.setTranslation(core::vector3df(
    (val/Coeff),
    AbsoluteTransformation.getTranslation().Y,
    AbsoluteTransformation.getTranslation().Z
  ));
  //Position.X = val;
}

void CHud2DElement::addY(f32 val)
{
  AbsoluteTransformation.setTranslation(core::vector3df(
    AbsoluteTransformation.getTranslation().X,
    AbsoluteTransformation.getTranslation().Y + (val/Coeff),
    AbsoluteTransformation.getTranslation().Z
  ));
  //Position.Y += val;
}

void CHud2DElement::subY(f32 val)
{
  AbsoluteTransformation.setTranslation(core::vector3df(
    AbsoluteTransformation.getTranslation().X,
    AbsoluteTransformation.getTranslation().Y - (val/Coeff),
    AbsoluteTransformation.getTranslation().Z
  ));
  //Position.Y -= val;
}

void CHud2DElement::setY(f32 val)
{
  AbsoluteTransformation.setTranslation(core::vector3df(
    AbsoluteTransformation.getTranslation().X,
    (val/Coeff),
    AbsoluteTransformation.getTranslation().Z
  ));
  //Position.Y = val;
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
  return AbsoluteTransformation.getTranslation().X;
}

f32 CHud2DElement::getY()
{
  return AbsoluteTransformation.getTranslation().Y;
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

u8 CHud2DElement::getOpacity()
{
  return Opacity;
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
