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

//! 3D Concepts
namespace N3D
{
  //! Cameras
  class CCamera;
  namespace NCamera
  {
    class CThirdPerson;
  }
  
  //! Characters
  class CCharacter;
  namespace NCharacter
  {
    class CNPC;
    class CPlayable;
  }
  
  //! Enemies
  class CEnemy;
  namespace NEnemy
  {
    class CAir;
    class CFloor;
  }
  
  //! Lights
  class CLight;
  namespace NLight
  {
    class CDirect;
    class COmni;
  }
  
  //! Sensors
  class CSensor;
  namespace NSensor
  {
    class CBox;
    class CPlane;
    class CTeleporter;
    // EPlaneType
  }

  class CAnimatedModel;
  class CLevelMesh;
  class CModelEntity;
  class CSky;
  class CStaticModel;  
  // SMeshAnimationInfo
}

//! Debug classes
namespace NDebug
{
  namespace NEditor
  {
    class CMap;
  }

  namespace NProperty
  {
    class CColor;
  }
  
  class CConsole;
  // EErrorCode
  // SDisplay
  // SOption
}

//! Engine classes
namespace NEngine
{
  class CPlayerControl;
  namespace NControl
  {
    class CGamepad;
    class CKeyboard;
    class CMouse;
    // ECommandIdentifier
    // EGamepadButton
    // EGamepadDirection
  }

  namespace NGameplay
  {
    class CDialog;
    class CDialogInterface;
    class CMapSectionInterface;
    class CNPCInterface;
    // EDifficultyLevel
    // EPlayableCharacterType
    // ETrophyIdentifier
  }

  namespace NResource
  {
    class CResourceManager;
    class CSettings;
    class CSettingsGroup;
    class CTranslation;
    // ELocaleIdentifier
  }
  
  class CSave;
  namespace NSave
  {
    class CSlot;
    class CFile;
    // SFileElement
  }

  class CGame;
  class CEngineException;
  class CEventManager;
  class CEntity;
  class CTimer;
  // ECharacterAnimationIdentifier
  // ECinemascopeAnimType
  // ECollisionType
  // EEventType
  // EFadeColor
  // ERayType
}

//! HUD
namespace NHud
{
  //! Buttons
  class CButton;
  namespace NButton
  {
    class CIcon;
    class CIconText;
    class CText;
  }
  
  //! Counters
  class CCounter;
  namespace NCounter
  {
    class CBar;
    class CDigit;
    class CGameTime;
    class CIcon;
    class CTargetLife;
    class CWorldTime;
    // EBarStyle
  }
  
  //! Hud ensembles
  class CEnsemble;
  namespace NEnsemble
  {
    class CCommands;
    class CEnergy;
  }
  
  //! Pause screen and sub-screen interfaces
  class CPauseScreen;
  namespace NPauseScreen
  {
    namespace NSubScreen
    {
      class CItems;
      class CMap;
      class CMonsters;
      class CSettings;
      class CSpirits;
      class CStatus;
      class CStory;
      class CWeapons;
    }
    
    class CSubScreen;
  }
  
  //! Player states
  class CPlayerState;
  namespace NPlayerState
  {
    class CCapacity;
    class CMainInfo;
  }

  //! Primitives
  class CHud;
  namespace NPrimitive
  {
    class CFlatElement;
    class CTriangle;
    class CQuad;
  }

  class CAnimation;
  class CCinemascopeMode;
  class CMenu;
  class CMenuOption;
  class CMiniMap;
  class CMiniMapArrow;
  class CPicture;
  class CText;
  class CTextChar;
  class CTextFont;
  class CWindow;
  // EFontStyle
  // EMenuIcon
  // EMenuStyle
  // EMiniMapIdentifier
  // ETextAlignment
  // EWindowStyle
  // SPositionInfo
}

//! Scenes
namespace NScene
{
  class CScene;
  class CSceneGameplay;
  class CSceneMenu;
  class CSceneDungeon;
  class CSceneSelectMap;
  // ESceneIdentifier
}

//! Shaders
namespace NShader
{
  class CDepthShaderCallback;
  class CDiffuseShaderCallback;
  class CIceShaderCallback;
  class CPostRenderGlow;
  class CPostRenderShader;
  class CShaders;
  class CShadow;
  class CShadowProcessor;
  class CShadowShaderCallback;
  // EShaderEffect
  // EShadowMode
}

//! Sound
namespace NSound
{
  class CMusic;
  class CMusicReference;
  class CMusicSequence;
  class CSoundManager;
  class CSpeaker;
  // SMusicInfo
  // SMusicSequenceInfo
}

}

#endif
