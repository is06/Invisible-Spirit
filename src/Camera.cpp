/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

/**
 * Constructeur de la caméra, ajoute le noeud au gestionnaire de scène et associe rotation et target
 */
Camera::Camera() {
  controlable = true;
  irrCam = Game::getSceneManager()->addCameraSceneNode(0, core::vector3df(0, 0, 0));
  irrCam->bindTargetAndRotation(true);
  irrCam->setNearValue(0.1f);
}

/**
 * Fonction de mise à jour de tous les objets Camera
 */
void Camera::render() {

}

/**
 * Retourne le node Irrlicht associé à la caméra
 * @return ISceneNode* le noeud associé à la caméra
 */
scene::ISceneNode* Camera::getNode() {
  return irrCam;
}

/**
 * Permet de savoir si le joueur a le contrôle sur la caméra
 * @return bool vaut vrai si le joueur a le contrôle
 */
bool Camera::hasControl() {
  return controlable;
}
