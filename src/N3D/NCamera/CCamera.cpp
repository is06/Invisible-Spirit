/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/CGame.h"
#include "../../../include/N3D/CCamera.h"

using namespace irr;
using namespace std;

namespace is06 { namespace N3D { namespace NCamera {

//! Main constructor of abstract class
CCamera::CCamera()
{
  Controlable = true;
  IrrCam = NEngine::CGame::getSceneManager()->addCameraSceneNode(0, core::vector3df(0, 0, 0));
  IrrCam->bindTargetAndRotation(true);
  IrrCam->setNearValue(0.1f);
}

//! All cameras update function
void CCamera::update()
{

}

//! Turns around X rotation axis (from front to back)
/**
 * \param f32 speed the rotation value
 */
void CCamera::turnX(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X + (speed * NEngine::CGame::getSpeedFactor()),
    IrrCam->getRotation().Y,
    IrrCam->getRotation().Z
  ));
}

//! Turns around Y rotation axis (from side to side)
/**
 * \param f32 speed the rotation value
 */
void CCamera::turnY(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X,
    IrrCam->getRotation().Y + (speed * NEngine::CGame::getSpeedFactor()),
    IrrCam->getRotation().Z
  ));
}

//! Turns around Z rotation axis ((anti-)clockwise)
/**
 * \param f32 speed the rotation value
 */
void CCamera::turnZ(f32 speed)
{
  IrrCam->setRotation(core::vector3df(
    IrrCam->getRotation().X,
    IrrCam->getRotation().Y,
    IrrCam->getRotation().Z + (speed * NEngine::CGame::getSpeedFactor())
  ));
}

//! Moves the camera along the X axis
void CCamera::moveX(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX() + (speed * NEngine::CGame::getSpeedFactor()),
    getY(),
    getZ()
  ));
}

//! Moves the camera along the Y axis
void CCamera::moveY(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX(),
    getY() + (speed * NEngine::CGame::getSpeedFactor()),
    getZ()
  ));
}

//! Moves the camera along the Z axis
void CCamera::moveZ(f32 speed)
{
  IrrCam->setPosition(core::vector3df(
    getX(),
    getY(),
    getZ() + (speed * NEngine::CGame::getSpeedFactor())
  ));
}

//! Returns the current X coordinate of the camera
f32 CCamera::getX()
{
  return IrrCam->getPosition().X;
}

//! Returns the current Y coordinate of the camera
f32 CCamera::getY()
{
  return IrrCam->getPosition().Y;
}

//! Returns the current Z coordinate of the camera
f32 CCamera::getZ()
{
  return IrrCam->getPosition().Z;
}

//! Returns the Irrlicht camera scene node pointer
scene::ICameraSceneNode* CCamera::getNode()
{
  return IrrCam;
}

//! Returns a 3d vector of the previous position
const core::vector3df& CCamera::getLastPosition() const
{
  return LastPosition;
}

//! Toggles control for this camera
void CCamera::toggleControl()
{
  if (Controlable) {
    Controlable = false;
  } else {
    Controlable = true;
  }
}

//! Enables/Disables the control for this camera
void CCamera::setControl(bool val)
{
  Controlable = val;
}

//! Returns true if this camera is controlable
bool CCamera::hasControl()
{
  return Controlable;
}

CCamera::~CCamera()
{

}

}}}
