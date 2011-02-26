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
