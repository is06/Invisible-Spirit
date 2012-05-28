/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/3d/CCamera.h"

using namespace irr;
using namespace std;

namespace is06
{
namespace n3D
{

CCamera::CCamera()
{
  Controlable = true;
  IrrCam = nEngine::CGame::getSceneManager()->addCameraSceneNode(0, core::vector3df(0, 0, 0));
  IrrCam->bindTargetAndRotation(true);
  IrrCam->setNearValue(0.1f);
}

void CCamera::update()
{

}

void CCamera::turnX(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X + (speed * nEngine::CGame::getSpeedFactor()),
    IrrCam->getRotation().Y,
    IrrCam->getRotation().Z
  ));
}

void CCamera::turnY(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X,
    IrrCam->getRotation().Y + (speed * nEngine::CGame::getSpeedFactor()),
    IrrCam->getRotation().Z
  ));
}

void CCamera::turnZ(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X,
    IrrCam->getRotation().Y,
    IrrCam->getRotation().Z + (speed * nEngine::CGame::getSpeedFactor())
  ));
}

void CCamera::moveX(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX() + (speed * nEngine::CGame::getSpeedFactor()),
    getY(),
    getZ()
  ));
}

void CCamera::moveY(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX(),
    getY() + (speed * nEngine::CGame::getSpeedFactor()),
    getZ()
  ));
}

void CCamera::moveZ(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX(),
    getY(),
    getZ() + (speed * nEngine::CGame::getSpeedFactor())
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

scene::ICameraSceneNode* CCamera::getNode()
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

bool CCamera::hasControl()
{
  return Controlable;
}

}
}
