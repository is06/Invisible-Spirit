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

namespace is06
{
namespace model
{

/**
 * Constructeur de la caméra, ajoute le noeud au gestionnaire de scène et associe rotation et target
 */
CCamera::CCamera()
{
  Controlable = true;
  IrrCam = engine::CGame::getSceneManager()->addCameraSceneNode(0, core::vector3df(0, 0, 0));
  IrrCam->bindTargetAndRotation(true);
  IrrCam->setNearValue(0.1f);
}

/**
 * Fonction de mise à jour de tous les objets Camera
 */
void CCamera::update()
{

}

void CCamera::turnX(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X + (speed * engine::CGame::getSpeedFactor()),
    IrrCam->getRotation().Y,
    IrrCam->getRotation().Z
  ));
}

void CCamera::turnY(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X,
    IrrCam->getRotation().Y + (speed * engine::CGame::getSpeedFactor()),
    IrrCam->getRotation().Z
  ));
}

void CCamera::turnZ(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X,
    IrrCam->getRotation().Y,
    IrrCam->getRotation().Z + (speed * engine::CGame::getSpeedFactor())
  ));
}

void CCamera::moveX(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX() + (speed * engine::CGame::getSpeedFactor()),
    getY(),
    getZ()
  ));
}

void CCamera::moveY(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX(),
    getY() + (speed * engine::CGame::getSpeedFactor()),
    getZ()
  ));
}

void CCamera::moveZ(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX(),
    getY(),
    getZ() + (speed * engine::CGame::getSpeedFactor())
  ));
}

f32 CCamera::getX()
{
  return IrrCam->getPosition().X;
}

f32 CCamera::getY()
{
  return IrrCam->getPosition().Y;
}

f32 CCamera::getZ()
{
  return IrrCam->getPosition().Z;
}

/**
 * Retourne le node Irrlicht associé à la caméra
 * @return ISceneNode* le noeud associé à la caméra
 */
irr::scene::ICameraSceneNode* CCamera::getNode()
{
  return IrrCam;
}

const core::vector3df& CCamera::getLastPosition() const
{
  return LastPosition;
}

void CCamera::toggleControl()
{
  if (Controlable) {
    Controlable = false;
  } else {
    Controlable = true;
  }
}

void CCamera::setControl(bool val)
{
  Controlable = val;
}

/**
 * Permet de savoir si le joueur a le contrôle sur la caméra
 * @return bool vaut vrai si le joueur a le contrôle
 */
bool CCamera::hasControl()
{
  return Controlable;
}

}
}
