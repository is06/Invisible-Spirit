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
        //! Camera classes
        namespace NCamera
        {
            class CCamera;
            class CThirdPerson;
        }

        //! Characters
        namespace NCharacter
        {
            class CCharacter;
            class CNPC;
            class CPlayableCharacter;
        }

        //! Enemies
        namespace NEnemy
        {
            class CEnemy;
            class CAirEnemy;
            class CFloorEnemy;
        }

        //! Lights
        namespace NLight
        {
            class CLight;
            class CDirectLight;
            class COmniLight;
        }

        //! Sensors (box, planes, teleporters...)
        namespace NSensor
        {
            class CSensor;
            class CBoxSensor;
            class CPlaneSensor;
            class CTeleporter;
        }

        //! Primitive 3D model entities
        namespace NPrimitive
        {
            class CModelEntity;
            class CAnimatedModel;
            class CStaticModel;
            class CMapPart;
        }

        //! Map parts like skies, grass, water etc.
        namespace NPart
        {
            class CSky;
        }
    }

    //! Namespace for debugging information and parameters
    namespace NDebug
    {
        class CConsole;
    }

    //! Engine generic classes
    namespace NEngine
    {
        //! Player control interface classes
        namespace NControl
        {
            class CPlayerControl;
            class CGamepad;
            class CKeyboard;
            class CMouse;
        }

        namespace NCore
        {
            class CGame;
            class CEntity;
        }

        namespace NEvent
        {
            class CEventManager;
        }

        //! Classes related to gameplay entities
        namespace NGameplay
        {
            class CDialog;
            class CDialogInterface;
            class CMapSectionInterface;
            class CNPCInterface;
        }

        //! External resources management
        namespace NResource
        {
            class CResourceManager;
            class CSettings;
            class CSettingsGroup;
            class CTranslation;
        }

        namespace NException
        {
            class CEngineException;
            class C3DException;
        }

        //! Savefile management
        namespace NSave
        {
            class CSave;
            class CSaveSlot;
            class CSaveFile;
        }

        namespace NTime
        {
            class CTimer;
        }
    }

    //! Hud namespace with all simili 2D elements to display
    namespace NHud
    {
        //! Types of buttons
        namespace NButton
        {
            class CButton;
            class CIconButton;
            class CIconTextButton;
            class CTextButton;
        }

        namespace NCore
        {
            class CHudEntity;
        }

        //! Types of counters (bars, life, meters, money...)
        namespace NCounter
        {
            class CCounter;
            class CBarMeter;
            class CTargetLifeMeter;
            class CDigitCounter;
            class CGameTime;
            class CWorldTime;
            class CIconCounter;
        }

        namespace NMenu
        {
            class CMenu;
            class CMenuOption;
        }

        //! HUD parts (energy, command icons...)
        namespace NPart
        {
            class CHudPart;
            class CCommands;
            class CEnergy;
            class CMiniMap;
            class CMiniMapArrow;
            class CCinemascopeMode;
        }

        //! Pause screen
        namespace NPauseScreen
        {
            class CPauseScreen;

            //! Pause sub-screens
            namespace NSubScreen
            {
                class CSubScreen;
                class CItems;
                class CMap;
                class CMonsters;
                class CSettings;
                class CSpirits;
                class CStatus;
                class CStory;
                class CWeapons;
            }
        }

        //! Player state classes in pause screen (HP, exp., level...)
        namespace NPlayerState
        {
            class CPlayerState;
            class CCapacity;
            class CMainInfo;
        }

        //! HUD primitive entities (quad, triangle, flat element...)
        namespace NPrimitive
        {
            class CFlatElement;
            class CTriangle;
            class CQuad;
            class CAnimation;
            class CPicture;
        }

        namespace NText
        {
            class CText;
            class CTextChar;
            class CTextFont;
        }

        namespace NWindow
        {
            class CWindow;
        }
    }

    //! Namespace for scene types
    namespace NScene
    {
        class CScene;
        class CSceneGameplay;
        class CSceneMenu;
        class CSceneDungeon;
        class CSceneSelectMap;
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
    }

    //! Namespace for sound and music interfaces
    namespace NSound
    {
        class CMusic;
        class CMusicReference;
        class CMusicSequence;
        class CSoundManager;
        class CSpeaker;
    }
}

#endif
