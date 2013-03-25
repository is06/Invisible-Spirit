/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_DEBUG_MAP_ALPHA_ZONE_H__
#define __IS06_MAP_DEBUG_MAP_ALPHA_ZONE_H__

#include "../../../include/3D/Sensor/CTeleporter.h"
#include "../../../include/Scene/CSceneGameplay.h"
#include "../../../include/Shader/CPostRenderGlow.h"

namespace is06 { namespace NMap { namespace NDebug {

//! This map is for alpha version 0.1 testing purpose only
class MAP_ALPHA_ZONE : public NScene::CSceneGameplay
{
public:
  MAP_ALPHA_ZONE();
  ~MAP_ALPHA_ZONE();

  void events();
  void postRender();
  void hudRender();
  void loadingSequence();
  void start();

private:
  NSound::CSpeaker*           Spk;
  NShader::CPostRenderGlow*   GlowShader;
  N3D::NLight::COmni*         Lt;
  N3D::NLight::CDirect*       DLight;
  N3D::NSensor::CTeleporter*  ToDungeonSensor;
  N3D::NCharacter::CNPC*      NPC1;
};

}}}

#endif
