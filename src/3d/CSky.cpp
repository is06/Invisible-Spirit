/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/3d/CSky.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CResourceManager.h"

namespace is06
{
namespace n3D
{

CSky::CSky(const string& textureName) : nEngine::CEntity()
{
  string up = "resource/texture/map/sky/" + textureName + "/up.jpg";
  string dn = "resource/texture/map/sky/" + textureName + "/dn.jpg";
  string lf = "resource/texture/map/sky/" + textureName + "/lf.jpg";
  string rt = "resource/texture/map/sky/" + textureName + "/rt.jpg";
  string ft = "resource/texture/map/sky/" + textureName + "/ft.jpg";
  string bk = "resource/texture/map/sky/" + textureName + "/bk.jpg";

  Layers[0] = nEngine::CGame::getSceneManager()->addSkyBoxSceneNode(
    nEngine::CResourceManager::loadTexture(up),
    nEngine::CResourceManager::loadTexture(dn),
    nEngine::CResourceManager::loadTexture(lf),
    nEngine::CResourceManager::loadTexture(rt),
    nEngine::CResourceManager::loadTexture(ft),
    nEngine::CResourceManager::loadTexture(bk)
  );
}

void CSky::update()
{

}

void CSky::setLayer(u8 index, const string& textureName)
{

}

void CSky::setFrontLayerOpacity(u8 level)
{

}

void CSky::setRotationSpeed(u8 index, f32 speed)
{

}

CSky::~CSky()
{
  Layers[0]->remove();
}

}
}
