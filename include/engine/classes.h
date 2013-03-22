/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CLASSES_H__
#define __IS06_CLASSES_H__

//! Main namespace for Invisible Spirit Game
namespace is06
{

//! The namespace which provides 3D Model classes
namespace N3D
{
  class CCamera;
  //! Specialized camera classes
  namespace NCamera
  {
    class CThirdPerson;
  }

  class CCharacter;
  //! Types of characters
  namespace NCharacter
  {
    class CNPC;
    class CPlayable;
  }

  class CEnemy;
  //! Types of enemies
  namespace NEnemy
  {
    class CAir;
    class CFloor;
  }

  class CLight;
  //! Types of lights
  namespace NLight
  {
    class CDirect;
    class COmni;
  }

  class CSensor;
  //! Types of sensors (box, planes, teleporters...)
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

//! Namespace for debugging information and parameters
namespace NDebug
{
  class CConsole;
  // EErrorCode
  // SDisplay
  // SOption
}

//! Engine generic classes
namespace NEngine
{
  class CPlayerControl;
  //! Player control interface classes
  namespace NControl
  {
    class CGamepad;
    class CKeyboard;
    class CMouse;
    // ECommandIdentifier
    // EGamepadButton
    // EGamepadDirection
  }

  //! Screen display related information structure (screen position)
  namespace NDisplay
  {
    // SPositionInfo
  }

  //! Classes related to gameplay entities
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

  //! External resources management
  namespace NResource
  {
    class CResourceManager;
    class CSettings;
    class CSettingsGroup;
    class CTranslation;
    // ELocaleIdentifier
  }

  namespace NException
  {
    class CEngineException;
    class C3DException;
  }

  class CSave;
  //! Savefile management
  namespace NSave
  {
    class CSlot;
    class CFile;
    // SFileElement
  }

  class CGame;
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

//! Hud namespace with all simili 2D elements to display
namespace NHud
{
  class CButton;
  //! Types of buttons
  namespace NButton
  {
    class CIcon;
    class CIconText;
    class CText;
  }

  class CCounter;
  //! Types of counters (bars, life, meters, money...)
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

  class CEnsemble;
  //! HUD ensemble zones (energy, command icons...)
  namespace NEnsemble
  {
    class CCommands;
    class CEnergy;
  }

  class CPauseScreen;
  //! Pause screen
  namespace NPauseScreen
  {
    //! Pause sub-screens
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

  class CPlayerState;
  //! Player state classes in pause screen (HP, exp., level...)
  namespace NPlayerState
  {
    class CCapacity;
    class CMainInfo;
  }

  class CHud;
  //! HUD primitive entities (quad, triangle, flat element...)
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

//! Namespace for scene types
namespace NScene
{
  class CScene;
  class CSceneGameplay;
  class CSceneMenu;
  class CSceneDungeon;
  class CSceneSelectMap;
  // ESceneIdentifier
}

//! This namespace is for shader graphical effects
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

//! Namespace for sound and music interfaces
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
