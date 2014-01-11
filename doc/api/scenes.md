Scenes
======

class is06::NScene::CScene
--------------------------

### Interface methods

* fadeIn
* fadeOut
* getBackBufferColor
* getActiveCamera
* getShadowProcessor

### Interface objects

* Cinemascope
* Camera
* Sky
* Control
* GameSave
* Dialog
* [Music](/doc/api/music_reference.md)
* GlobalTranslations
* SceneTranslations
* ShadowProcessor

### Data

* BackBufferColor
* SceneTime
* StartTime
* SpeedFactor

class is06::NScene::CSceneMenu
------------------------------
(inherits from CScene)

class is06::NScene::CSceneGameplay
----------------------------------
(inherits from CScene)

### Interface objects

* Hero
* HudEnsemble
* HudEnergyEnsemble
* MiniMap
* WorldTime
* PauseScreen
* MapSections
* NPCInterface
* EverySecondTimer

class is06::NScene::CSceneDungeon
---------------------------------
(inherits from CSceneGameplay)