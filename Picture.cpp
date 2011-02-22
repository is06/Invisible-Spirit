/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "core.h"

using namespace irr;

/**
 * Constructeur par défaut
 */
Picture::Picture() {
  construct(100, 100, 0, 0, "resource/hud/default.bmp");
}

/**
 * Création à l'aide de coordonnées directes
 */
Picture::Picture(f32 w, f32 h, f32 x, f32 y, const core::stringc& filePath) {
  construct(w, h, x, y, filePath);
}

/**
 * Création à l'aide de structures
 */
Picture::Picture(const core::dimension2df& newSize, const core::position2df& newPos, const core::stringc& filePath) : Hud() {
  construct(newSize.Width, newSize.Height, newPos.X, newPos.Y, filePath);
}

/**
 * Fonction de création de l'objet
 */
void Picture::construct(f32 w, f32 h, f32 x, f32 y, const core::stringc& filePath) {
  // Image visible dès sa création
  isVisible = true;

  // Animation Texture
  animSpeed = core::vector2df(0.0f, 0.0f);

  // Dimensions, position
  size = core::dimension2df(w, h);
  pos = core::position2df(x, y);

  // Materiau
  texture = Game::getVideoDriver()->getTexture(filePath.c_str());
  material.setTexture(0, texture);
  material.Lighting = false;
  material.DiffuseColor.setAlpha(255);
  material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.opacity;

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

/**
 * Rendu de l'élément d'interface
 */
void Picture::render() { Hud::render();

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

  // Dessin des polygones
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
void Picture::setSize(f32 w, f32 h) {
  size.Width = w;
  size.Height = h;
}

void Picture::setPosition(f32 x, f32 y) {
  pos.X = x;
  pos.Y = y;
}

void Picture::startUVAnimation(f32 uSpeed, f32 vSpeed) {
  animSpeed.X = uSpeed;
  animSpeed.Y = vSpeed;
}

void Picture::stopUVAnimation() {
  animSpeed.X = 0.0f;
  animSpeed.Y = 0.0f;
}

void Picture::hide() {
  isVisible = false;
}

void Picture::show() {
  isVisible = true;
}

void Picture::setOpacity(u8 value) {
  opacity = value;
}

Picture::~Picture() {

}
