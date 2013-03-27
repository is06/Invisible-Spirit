/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/N3D/NCharacter/CPlayableCharacter.h"
#include "../../../include/N3D/NCamera/CCamera.h"
#include "../../../include/NEngine/NGameplay/CDialogInterface.h"
#include "../../../include/N3D/NCharacter/EPlayableCharacterType.h"
#include "../../../include/NMap/NGeneric/MAP_METADIM.h"
#include "../../../include/NSound/CMusicReference.h"

namespace is06 { namespace NMap { namespace NGeneric {

MAP_METADIM::MAP_METADIM() : NScene::CSceneGameplay()
{
  Hero = new N3D::NCharacter::CPlayableCharacter(Camera);
  Hero->setCharacter(N3D::NCharacter::EPCT_AYRON);
  Hero->setControl(false);

  Music->play("norya");

  EventState = 0;
}

void MAP_METADIM::events()
{
  NScene::CSceneGameplay::events();

  if (SceneTime < 10.0f) {
    // Camera movement (10 seconds) - EVENT 0
    //Camera->moveAlongPath(CameraPath);
  } else {
    // Norya dialog 1 - EVENT 2
    EventState = 1;
    if (EventState == 1) {
      Dialog->start("norya_first");
      EventState = 2;
    }
    // Norya dialog 2 - EVENT 3
    if (EventState == 2 && Dialog->finished()) {
      Dialog->start("norya_second");
      EventState = 3;
    }
    // Character control: first tutorial - EVENT 4
    if (EventState == 3 && Dialog->finished()) {
      Hero->setControl(true);
      EventState = 4;
    }
  }
}

void MAP_METADIM::postRender()
{

}

void MAP_METADIM::hudRender()
{

}

MAP_METADIM::~MAP_METADIM()
{

}

}}}
