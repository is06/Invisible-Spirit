/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#include "core.h"

using namespace irr;
using namespace std;

/**
 * Constructeur de l'entité Ayron, définiti le mesh à charger ainsi que sa position initiale
 * @param Camera* cam pointeur vers la caméra associée à l'entité
 */
Ayron::Ayron(Camera* cam) : PlayableCharacter() {
  loadMesh("resource/mesh/character/cube.obj");
  // Creation du node à 10 mètres de hauteur
  createNode(core::vector3df(0, 5, 0));
  linkedCam = cam;
}

/**
 * Fonction de mise à jour et de rendu de l'entité Ayron
 * La fonction appelle la updateBody de l'entité de Mouvement rattaché à l'entité Ayron
 * pour la gestion des collisions et de la physique
 */
void Ayron::render() { PlayableCharacter::render();

}

void Ayron::fall() {
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X,
    mainNode->getPosition().Y - 0.2,
    mainNode->getPosition().Z
  ));
}

void Ayron::raise() {
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X,
    mainNode->getPosition().Y + 0.05,
    mainNode->getPosition().Z
  ));
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
