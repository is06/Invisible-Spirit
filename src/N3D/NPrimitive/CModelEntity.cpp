/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NResource/CResourceManager.h"
#include "../../../include/N3D/NPrimitive/CModelEntity.h"

using is06::NEngine::NCore::CGame;

namespace is06 { namespace N3D { namespace NPrimitive {

//! Initializations
CModelEntity::CModelEntity() : NEngine::NCore::CEntity()
{
    MainMesh = NULL;
    MainBody = NULL;
    AttachedSpeaker = NULL;
}

//! Update method, called every cycle for event testing
void CModelEntity::update()
{

}

//! Called every cycle to generate shader effects
void CModelEntity::shaderRender()
{

}

//! Loads a mesh in this entity
/**
 * \param string& meshFilePath
 */
void CModelEntity::loadMesh(const string& meshFilePath)
{
    MainMesh = CGame::getResourceManager()->loadMesh(meshFilePath);
}

//! Returns the irrlicht mesh object of the entity
scene::IMesh* CModelEntity::getMesh()
{
    return MainMesh;
}

//! Returns newton main body of this entity
NewtonBody* CModelEntity::getMainBody()
{
    if (MainBody) {
        return MainBody;
    } else {
        return NULL;
    }
}

//! Links a speaker object to this model entity
void CModelEntity::attachSpeaker(NSound::CSpeaker* speaker)
{
  AttachedSpeaker = speaker;
}

//! Destroys all objects
CModelEntity::~CModelEntity()
{
  AttachedSpeaker = NULL;
}

}}}
