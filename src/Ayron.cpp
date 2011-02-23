/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

/**
 * Constructeur de l'entité Ayron, définiti le mesh à charger ainsi que sa position initiale
 * @param Camera* cam pointeur vers la caméra associée à l'entité
 */
Ayron::Ayron(Camera* cam) : Character() {
  loadMesh("resource/mesh/character/cube.obj");
  createNode(core::vector3df(0, 1, -2));
  linkedCam = cam;

  // Spécial Geeko
  //mainNode->setScale(core::vector3df(0.07,0.07,0.07));

  // Direction de départ du perso : dos à la caméra
  mainNode->setRotation(core::vector3df(
    mainNode->getRotation().X,
    cam->getNode()->getRotation().Y - core::radToDeg(core::PI),
    mainNode->getRotation().Z
  ));

  //mainNode->setDebugDataVisible(scene::EDS_FULL);
  //mainNode->getMaterial(0).Wireframe = true;
}

/**
 * Fonction de mise à jour et de rendu de l'entité Ayron
 * La fonction appelle la updateBody de l'entité de Mouvement rattaché à l'entité Ayron
 * pour la gestion des collisions et de la physique
 */
void Ayron::render() { Character::render();

}

void Ayron::fall() {
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X,
    mainNode->getPosition().Y - 0.2,
    mainNode->getPosition().Z
  ));
}

/**
 *
 */
void Ayron::raise() {
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X,
    mainNode->getPosition().Y + 0.005,
    mainNode->getPosition().Z
  ));
}

/**
 *
 */
void Ayron::jump() {

}

/**
 * Applique une force opposée au déplacement du personnage pour le bloquer contre un mur
 */
void Ayron::moveOpposite() {
  f32 x = cos(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2));
  f32 z = sin(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2));

  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X + (x * (0.05f / 1024.0f)),
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + (z * (0.05f / 1024.0f))
  ));
}

/**
 * TODO : a faire
 */
void Ayron::moveSlide(f32 angle) {
  cout << angle << endl;

/*
  f32 speed = 0.05f;
  f32 x = cos(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2) + angle);
  f32 z = sin(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2) + angle);

  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X + (x * (speed / 1024.0f)),
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + (z * (speed / 1024.0f))
  ));
*/
}

/**
 * Déplace l'entité vers la gauche par rapport à la caméra
 * @param f32 speed vitesse de déplacement
 */
void Ayron::goLeft(f32 speed) {
  updateCoords(0, speed);
}

/**
 * Déplace l'entité vers la droite par rapport à la caméra
 * @param f32 speed vitesse de déplacement
 */
void Ayron::goRight(f32 speed) {
  updateCoords(core::PI, speed);
}

/**
 * Déplace l'entité vers l'avant par rapport à la caméra
 * @param f32 speed vitesse de déplacement
 */
void Ayron::goForward(f32 speed) {
  updateCoords((core::PI / 2), speed);
}

/**
 * Déplace l'entité vers l'arrière par rapport à la caméra
 * @param f32 speed vitesse de déplacement
 */
void Ayron::goBackward(f32 speed) {
  updateCoords((3 * core::PI / 2), speed);
}

/**
 * Met à jour les coordonnées quand le joueur veut se déplacer
 * @param f32 deltaU valeur de la direction du personnage (considérer le cercle trigonométrique)
 * @param f32 speed vitesse à laquelle le personnage doit se déplacer
 */
void Ayron::updateCoords(f32 deltaU, f32 speed) {
  f32 x = cos(core::degToRad(linkedCam->getNode()->getRotation().Y) + deltaU);
  f32 z = sin(core::degToRad(linkedCam->getNode()->getRotation().Y) + deltaU);
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X + ((x * -1) * (speed / 1024.0f)),
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + (z * (speed / 1024.0f))
  ));
}
