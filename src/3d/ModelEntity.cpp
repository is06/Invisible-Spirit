/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/ModelEntity.h"
#include "../../include/Game.h"

namespace is06
{
namespace model
{

/**
 * Initializations
 */
CModelEntity::CModelEntity() : engine::CEntity()
{
  MainMesh = NULL;
  MainBody = NULL;
  AttachedSpeaker = NULL;
}

/**
 * Rendering and event method
 */
void CModelEntity::update()
{
  //Entity::update();
}

/**
 *
 */
void CModelEntity::shaderRender()
{

}

/**
 * Loads a mesh in this entity
 * @param std::string& meshFilePath
 */
void CModelEntity::loadMesh(const std::string& meshFilePath)
{
  MainMesh = engine::CGame::getSceneManager()->getMesh(meshFilePath.c_str());
}

/**
 * Returns the irrlicht mesh object of the entity
 */
irr::scene::IMesh* CModelEntity::getMesh()
{
  return MainMesh;
}

/**
 * Returns newton main body of this entity
 */
NewtonBody* CModelEntity::getMainBody()
{
  return MainBody;
}

/**
 *
 */
void CModelEntity::attachSpeaker(sound::CSpeaker* speaker)
{
  AttachedSpeaker = speaker;
}

/**
 * Destroys all objects
 */
CModelEntity::~CModelEntity()
{
  AttachedSpeaker = NULL;
}

}
}
