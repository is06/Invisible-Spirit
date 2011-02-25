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
 * Ayron entity constructor: defines which mesh to load and set the initial direction
 * @param Camera* cam pointer to a Camera to link to Ayron
 */
Ayron::Ayron(Camera* cam) : Character() {
  controlable = true;
  jumpStrength = 0.0f;
  fallStrength = 0.0f;

  // Loading mesh
  loadMesh("resource/mesh/character/cube.obj");
  createNode(core::vector3df(0, 1, -2));
  linkedCam = cam;

  // Start direction
  mainNode->setRotation(core::vector3df(
    mainNode->getRotation().X,
    cam->getNode()->getRotation().Y - core::radToDeg(core::PI),
    mainNode->getRotation().Z
  ));

  mainNode->getMaterial(0).Wireframe = true;
}

/**
 * Render function, called every cycle
 */
void Ayron::render() { Character::render();

}

/**
 * Called while Ayron's floor raycast is NOT in collision with the floor
 */
void Ayron::fall() {
  if(!isJumping) {
    if(fallStrength < Ayron::JUMP_STRENGTH) {
      fallStrength += Ayron::GRAVITY;
    }
    mainNode->setPosition(core::vector3df(
      mainNode->getPosition().X,
      mainNode->getPosition().Y - fallStrength,
      mainNode->getPosition().Z
    ));
  }
}

/**
 * Called while Ayron's floor raycast is in collision with the floor
 */
void Ayron::raise() {
  if(isFalling) {
    // Ayron is hitting the floor
    fallStrength = 0.0f;
    isFalling = false;
  }
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X,
    mainNode->getPosition().Y + 0.005,
    mainNode->getPosition().Z
  ));
}

/**
 * Called when the player wants Ayron to jump
 */
void Ayron::jump() {
  if(isJumping) {
    jumpStrength -= Ayron::GRAVITY;
    if(jumpStrength <= 0) {
      isJumping = false;
      isFalling = true;
    }
    mainNode->setPosition(core::vector3df(
      mainNode->getPosition().X,
      mainNode->getPosition().Y + jumpStrength,
      mainNode->getPosition().Z
    ));
  }
}

/**
 *
 */
void Ayron::setJumpStrength(f32 value) {
  jumpStrength = value;
}

/**
 *
 */
f32 Ayron::getJumpStrength() {
  return jumpStrength;
}

/**
 * Applies an opposite force to Ayron in order to stop it against a wall
 * Function still under development
 */
void Ayron::moveOpposite() {
  f32 x = cos(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2));
  f32 z = sin(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2));

  core::vector3df origin = mainNode->getPosition();

  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X - (x * (0.05f / 1024.0f)),
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + (z * (0.05f / 1024.0f))
  ));

  core::vector3df end(
    mainNode->getPosition().X - (x * (5.0f)),
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + (z * (5.0f))
  );

  core::matrix4 mat;
  Game::getVideoDriver()->setTransform(video::ETS_WORLD, mat);
  Game::getVideoDriver()->draw3DLine(origin, end, video::SColor(255,255,255,255));
}

/**
 * TODO
 */
void Ayron::moveSlide(f32 angle) {

}

/**
 * Move Ayron to the left from camera
 * @param f32 speed movement speed
 */
void Ayron::goLeft(f32 speed) {
  updateCoords(0, speed);
}

/**
 * Move Ayron to the right from camera
 * @param f32 speed movement speed
 */
void Ayron::goRight(f32 speed) {
  updateCoords(core::PI, speed);
}

/**
 * Move Ayron forward from camera
 * @param f32 speed movement speed
 */
void Ayron::goForward(f32 speed) {
  updateCoords((core::PI / 2), speed);
}

/**
 * Move Ayron backward from camera
 * @param f32 speed movement speed
 */
void Ayron::goBackward(f32 speed) {
  updateCoords((3 * core::PI / 2), speed);
}

/**
 * Update Ayron's coordinates when the player wants to move him
 * @param f32 deltaU direction value
 * @param f32 speed speed value
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

/**
 *
 */
bool Ayron::hasControl() {
  return controlable;
}
