/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Hud2DElement.h"
#include "../../include/Game.h"

using namespace irr;
using namespace std;

u16 Hud2DElement::indices[] = {2, 1, 3, 2, 0, 1};
core::matrix4 Hud2DElement::mat;

Hud2DElement::Hud2DElement(f32 x, f32 y, f32 w, f32 h) : Hud() {
  texture = NULL;

  // Image visible dès sa création
  isVisible = true;

  // Animation Texture
  animSpeed = core::vector2df(0.0f, 0.0f);

  // Dimensions, position
  size = core::dimension2df(w, h);
  pos = core::position2df(x, y);

  // Materiau
  material.Lighting = false;
  //material.DiffuseColor.setAlpha(255);
  //material.Wireframe = true;
  //material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.opacity;
  material.MaterialType = video::EMT_TRANSPARENT_ALPHA_CHANNEL;
  material.setTexture(0, NULL);

  minTextureOffset.X = 0.0f;
  minTextureOffset.Y = 0.0f;
  maxTextureOffset.X = 1.0f;
  maxTextureOffset.Y = 1.0f;

  // Création vertices
  vertices[0] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 1, 0,
    video::SColor(255,255,255,255),
    minTextureOffset.X, minTextureOffset.Y);
  vertices[1] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 0, 0,
    video::SColor(255,255,255,255),
    maxTextureOffset.X, minTextureOffset.Y);
  vertices[2] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 1, 1,
    video::SColor(255,255,255,255),
    minTextureOffset.X, maxTextureOffset.Y);
  vertices[3] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 0, 1,
    video::SColor(255,255,255,255),
    maxTextureOffset.X, maxTextureOffset.Y);
}

void Hud2DElement::render() {
  // Déplacement et taille
  vertices[0].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF * -1);
  vertices[0].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF);
  vertices[1].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF);
  vertices[1].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF);
  vertices[2].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF * -1);
  vertices[2].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF * -1);
  vertices[3].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF);
  vertices[3].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF * -1);

  // Offset de texture
  vertices[0].TCoords.X = minTextureOffset.X;
  vertices[0].TCoords.Y = minTextureOffset.Y;
  vertices[1].TCoords.X = maxTextureOffset.X;
  vertices[1].TCoords.Y = minTextureOffset.Y;
  vertices[2].TCoords.X = minTextureOffset.X;
  vertices[2].TCoords.Y = maxTextureOffset.Y;
  vertices[3].TCoords.X = maxTextureOffset.X;
  vertices[3].TCoords.Y = maxTextureOffset.Y;

  // Animation UV
  if(animSpeed.X != 0.0f || animSpeed.Y != 0.0f) {
    vertices[0].TCoords.X += animSpeed.X;
    vertices[0].TCoords.Y += animSpeed.Y;
    vertices[1].TCoords.X += animSpeed.X;
    vertices[1].TCoords.Y += animSpeed.Y;
    vertices[2].TCoords.X += animSpeed.X;
    vertices[2].TCoords.Y += animSpeed.Y;
    vertices[3].TCoords.X += animSpeed.X;
    vertices[3].TCoords.Y += animSpeed.Y;
  }

  // Draws vertices of 2D element only if visible
  if(isVisible) {
    // Opacity
    material.DiffuseColor.setAlpha(opacity);

    // Texture of 2D element
    if(texture) {
      material.setTexture(0, texture);
    }

    Game::getVideoDriver()->setMaterial(material);
    Game::getVideoDriver()->setTransform(video::ETS_VIEW, mat);
    Game::getVideoDriver()->drawIndexedTriangleList(vertices, 4, indices, 2);
    Game::getVideoDriver()->setTransform(video::ETS_WORLD, mat);
  }
}

/**
 * Change la taille de l'élément d'interface (déforme la texture)
 */
void Hud2DElement::setSize(f32 w, f32 h) {
  size.Width = w;
  size.Height = h;
}

void Hud2DElement::setPosition(f32 x, f32 y) {
  pos.X = x;
  pos.Y = y;
}

void Hud2DElement::setTextureOffset(const core::vector2df& min, const core::vector2df& max) {
  minTextureOffset = min;
  maxTextureOffset = max;
}

void Hud2DElement::addX(f32 val) {
  pos.X += val;
}

void Hud2DElement::subX(f32 val) {
  pos.X -= val;
}

void Hud2DElement::setX(f32 val) {
  pos.X = val;
}

void Hud2DElement::addY(f32 val) {
  pos.Y += val;
}

void Hud2DElement::subY(f32 val) {
  pos.Y -= val;
}

void Hud2DElement::setY(f32 val) {
  pos.Y = val;
}

void Hud2DElement::setWidth(f32 val) {
  size.Width = val;
}

void Hud2DElement::setHeight(f32 val) {
  size.Height = val;
}

f32 Hud2DElement::getX() {
  return pos.X;
}

f32 Hud2DElement::getY() {
  return pos.Y;
}

f32 Hud2DElement::getWidth() {
  return size.Width;
}

f32 Hud2DElement::getHeight() {
  return size.Height;
}

void Hud2DElement::startUVAnimation(f32 uSpeed, f32 vSpeed) {
  animSpeed.X = uSpeed;
  animSpeed.Y = vSpeed;
}

void Hud2DElement::stopUVAnimation() {
  animSpeed.X = 0.0f;
  animSpeed.Y = 0.0f;
}

void Hud2DElement::hide() {
  isVisible = false;
}

void Hud2DElement::show() {
  isVisible = true;
}

void Hud2DElement::setOpacity(u8 value) {
  opacity = value;
}

Hud2DElement::~Hud2DElement() {
  texture = NULL;
}
