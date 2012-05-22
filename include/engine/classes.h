/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CLASSES_H__
#define __IS06_CLASSES_H__

namespace is06
{

// Engine classes
namespace nEngine
{
  class CGame;
  class CEngineException;
  class CEventManager;
  class CSettings;
  class CSettingsGroup;
  class CTimer;
  class CTranslation;
  class CEntity;
  class CSave;
  class CSaveSlot;
  class CSaveFile;
  class CPlayerControl;
  class CKeyboard;
  class CMouse;
  class CGamepad;
  class CDialog;
  class CDialogInterface;
}

// Debug classes
namespace nDebug
{
  class CMapEditor;
  class CColorProperty;
}

// Scenes
namespace nScene
{
  class CScene;
  class CSceneGameplay;
  class CSceneMenu;
}

// HUD
namespace nHud
{
  class CHud;
  class CHud2DElement;
  class CTriangle;
  class CQuad;
  class CCounter;
  class CBarCounter;
  class CDigitCounter;
  class CGameTimeCounter;
  class CWorldTimeCounter;
  class CTargetLifeMeter;
  class CIconCounter;
  class CPicture;
  class CAnimation;
  class CText;
  class CTextChar;
  class CTextFont;
  class CWindow;
  class CGameplayInterface;
  class CEnergyInterface;
  class CButtonsInterface;
  class CButton;
  class CTextButton;
  class CIconButton;
  class CIconTextButton;
  class CMenu;
  class CMenuOption;
  class CMainStateInfo;
  class CCapacityInfo;
  class CPlayerState;
  class CMiniMap;

  //! Menu and sub-menu interfaces
  namespace nMenu
  {
    class CGameplayMenu;
    class CDimensionMenu;
    class CItemMenu;
    class CMapMenu;
    class CMonstersMenu;
    class CSettingsMenu;
    class CSpiritMenu;
    class CStatusMenu;
    class CTalesMenu;
    class CWeaponMenu;
  }
}

// 3D Model
namespace n3D
{
  // General
  class CModelEntity;
  class CAnimatedModel;
  class CStaticModel;
  class CLevelMesh;
  class CCamera;
  class CTPCamera;
  class CLight;
  class CDirectLight;
  class COmniLight;
  class CSensor;
  class CPlaneSensor;
  class CBoxSensor;

  // Characters
  class CCharacter;
  class CPlayableCharacter;
  class CNPC;

  // Enemies
  class CEnemy;
  class CFloorEnemy;
  class CAirEnemy;
}

// Shaders
namespace nShader
{
  class CDiffuseShaderCallback;
  class CPostRenderGlow;
  class CDepthShaderCallback;
  class CShadowShaderCallback;
}

// Sound
namespace nSound
{
  class CSoundManager;
  class CSpeaker;
  class CMusicReference;
  class CMusic;
  class CMusicSequence;
}

}

#endif
