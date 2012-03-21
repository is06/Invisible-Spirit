/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/3d/Camera.h"

using namespace irr;
using namespace std;

/**
 * Constructeur de la caméra, ajoute le noeud au gestionnaire de scène et associe rotation et target
 */
Camera::Camera()
{
  controlable = true;
  irrCam = Game::getSceneManager()->addCameraSceneNode(0, core::vector3df(0, 0, 0));
  irrCam->bindTargetAndRotation(true);
  irrCam->setNearValue(0.1f);
}

/**
 * Fonction de mise à jour de tous les objets Camera
 */
void Camera::update()
{

}

void Camera::turnX(f32 speed)
{
  irrCam->setRotation(core::vector3df(
    irrCam->getRotation().X + (speed * Game::getSpeedFactor()),
    irrCam->getRotation().Y,
    irrCam->getRotation().Z
  ));
}

void Camera::turnY(f32 speed)
{
  irrCam->setRotation(core::vector3df(
    irrCam->getRotation().X,
    irrCam->getRotation().Y + (speed * Game::getSpeedFactor()),
    irrCam->getRotation().Z
  ));
}

void Camera::turnZ(f32 speed)
{
  irrCam->setRotation(core::vector3df(
    irrCam->getRotation().X,
    irrCam->getRotation().Y,
    irrCam->getRotation().Z + (speed * Game::getSpeedFactor())
  ));
}

void Camera::moveX(f32 speed)
{
  irrCam->setPosition(core::vector3df(
    getX() + (speed * Game::getSpeedFactor()),
    getY(),
    getZ()
  ));
}

void Camera::moveY(f32 speed)
{
  irrCam->setPosition(core::vector3df(
    getX(),
    getY() + (speed * Game::getSpeedFactor()),
    getZ()
  ));
}

void Camera::moveZ(f32 speed)
{
  irrCam->setPosition(core::vector3df(
    getX(),
    getY(),
    getZ() + (speed * Game::getSpeedFactor())
  ));
}

f32 Camera::getX()
{
  return irrCam->getPosition().X;
}

f32 Camera::getY()
{
  return irrCam->getPosition().Y;
}

f32 Camera::getZ()
{
  return irrCam->getPosition().Z;
}

/**
 * Retourne le node Irrlicht associé à la caméra
 * @return ISceneNode* le noeud associé à la caméra
 */
scene::ICameraSceneNode* Camera::getNode()
{
  return irrCam;
}

const core::vector3df& Camera::getLastPosition() const
{
  return lastPosition;
}

void Camera::toggleControl()
{
  if (controlable) {
    controlable = false;
  } else {
    controlable = true;
  }
}

void Camera::setControl(bool val)
{
  controlable = val;
}

/**
 * Permet de savoir si le joueur a le contrôle sur la caméra
 * @return bool vaut vrai si le joueur a le contrôle
 */
bool Camera::hasControl()
{
  return controlable;
}
