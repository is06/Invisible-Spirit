/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/3d/CSky.h"
#include "../../include/engine/CGame.h"

namespace is06
{
namespace n3D
{

CSky::CSky(const string& textureName) : nEngine::CEntity()
{
  video::IVideoDriver* driver = nEngine::CGame::getVideoDriver();

  string up = "resource/texture/map/sky/" + textureName + "/up.jpg";
  string dn = "resource/texture/map/sky/" + textureName + "/dn.jpg";
  string lf = "resource/texture/map/sky/" + textureName + "/lf.jpg";
  string rt = "resource/texture/map/sky/" + textureName + "/rt.jpg";
  string ft = "resource/texture/map/sky/" + textureName + "/ft.jpg";
  string bk = "resource/texture/map/sky/" + textureName + "/bk.jpg";

  SkyBox = nEngine::CGame::getSceneManager()->addSkyBoxSceneNode(
    driver->getTexture(up.c_str()),
    driver->getTexture(dn.c_str()),
    driver->getTexture(lf.c_str()),
    driver->getTexture(rt.c_str()),
    driver->getTexture(ft.c_str()),
    driver->getTexture(bk.c_str())
  );
}

}
}
