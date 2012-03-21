/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/ModelEntity.h"
#include "../../include/Game.h"

using namespace irr;
using namespace std;

/**
 * Initializations
 */
ModelEntity::ModelEntity() : Entity()
{
  mainMesh = NULL;
  mainBody = NULL;
  attachedSpeaker = NULL;
}

/**
 * Rendering and event method
 */
void ModelEntity::update()
{
  //Entity::update();
}

/**
 *
 */
void ModelEntity::shaderRender()
{

}

/**
 * Loads a mesh in this entity
 * @param string& meshFilePath
 */
void ModelEntity::loadMesh(const string& meshFilePath)
{
  mainMesh = Game::getSceneManager()->getMesh(meshFilePath.c_str());
}

/**
 * Returns the irrlicht mesh object of the entity
 */
scene::IMesh* ModelEntity::getMesh()
{
  return mainMesh;
}

/**
 * Returns newton main body of this entity
 */
NewtonBody* ModelEntity::getMainBody()
{
  return mainBody;
}

/**
 *
 */
void ModelEntity::attachSpeaker(Speaker* spk)
{
  attachedSpeaker = spk;
}

/**
 * Destroys all objects
 */
ModelEntity::~ModelEntity()
{
  attachedSpeaker = NULL;
}
