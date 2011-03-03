/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

Hud2DElement::Hud2DElement(f32 w, f32 h, f32 x, f32 y) : Hud() {
  // Image visible dès sa création
  isVisible = true;

  // Animation Texture
  animSpeed = core::vector2df(0.0f, 0.0f);

  // Dimensions, position
  size = core::dimension2df(w, h);
  pos = core::position2df(x, y);

  // Materiau
  material.Lighting = false;
  material.DiffuseColor.setAlpha(255);
  //material.Wireframe = true;
  //material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.opacity;
  material.MaterialType = video::EMT_TRANSPARENT_ALPHA_CHANNEL;

  // Création vertices
  vertices[0] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 1, 0,
    video::SColor(255,255,255,255),
    0, 0);
  vertices[1] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF), FAR,
    1, 0, 0,
    video::SColor(255,255,255,255),
    1, 0);
  vertices[2] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF * -1), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 1, 1,
    video::SColor(255,255,255,255),
    0, 1);
  vertices[3] = video::S3DVertex(
    (x / COEFF) + (w / 2 / COEFF), (y / COEFF) + (h / 2 / COEFF * -1), FAR,
    0, 0, 1,
    video::SColor(255,255,255,255),
    1, 1);
}

void Hud2DElement::render() {
  // Déplacement
  vertices[0].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF * -1);
  vertices[0].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF);
  vertices[1].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF);
  vertices[1].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF);
  vertices[2].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF * -1);
  vertices[2].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF * -1);
  vertices[3].Pos.X = (pos.X / COEFF) + (size.Width / 2 / COEFF);
  vertices[3].Pos.Y = (pos.Y / COEFF) + (size.Height / 2 / COEFF * -1);

  // Opacité
  material.DiffuseColor.setAlpha(opacity);

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

  if(isVisible) {
    core::matrix4 mat;
    u16 indices[] = {0,2,3, 2,1,3, 1,0,3, 2,0,1};
    Game::getVideoDriver()->setMaterial(material);
    Game::getVideoDriver()->setTransform(video::ETS_VIEW, mat);
    Game::getVideoDriver()->drawIndexedTriangleList(vertices, 4, indices, 4);
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

}
