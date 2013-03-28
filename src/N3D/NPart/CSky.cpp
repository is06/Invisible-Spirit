/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/N3D/NPart/CSky.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NResource/CResourceManager.h"

using is06::NEngine::NCore::CGame;
using is06::NEngine::NResource::CResourceManager;

namespace is06 { namespace N3D { namespace NPart {

//! Constructor
/**
 * \todo make multiple layers
 */
CSky::CSky(const string& textureName) : NEngine::NCore::CEntity()
{
  string up = "resource/texture/map/sky/" + textureName + "/up.jpg";
  string dn = "resource/texture/map/sky/" + textureName + "/dn.jpg";
  string lf = "resource/texture/map/sky/" + textureName + "/lf.jpg";
  string rt = "resource/texture/map/sky/" + textureName + "/rt.jpg";
  string ft = "resource/texture/map/sky/" + textureName + "/ft.jpg";
  string bk = "resource/texture/map/sky/" + textureName + "/bk.jpg";

  Layers[0] = CGame::getSceneManager()->addSkyBoxSceneNode(
    CGame::getResourceManager()->loadTexture(up),
    CGame::getResourceManager()->loadTexture(dn),
    CGame::getResourceManager()->loadTexture(lf),
    CGame::getResourceManager()->loadTexture(rt),
    CGame::getResourceManager()->loadTexture(ft),
    CGame::getResourceManager()->loadTexture(bk)
  );
}

//! Update method, called every cycle for event testing
void CSky::update()
{

}

//! Changes the texture file group of the front layer
void CSky::setLayer(u8 index, const string& textureName)
{

}

//! Changes the opacity of the front layer
void CSky::setFrontLayerOpacity(u8 level)
{

}

//! Changes the rotation speed of a layer of the sky
void CSky::setRotationSpeed(u8 index, f32 speed)
{

}

//! Destructor
CSky::~CSky()
{
  Layers[0]->remove();
}

}}}
