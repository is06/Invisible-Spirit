Scenes
======

class **CScene**
----------------

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
* Music
* GlobalTranslations
* SceneTranslations
* ShadowProcessor

### Data

* BackBufferColor
* SceneTime
* StartTime
* SpeedFactor

class **CSceneMenu**
--------------------
(inherits from CScene)

class **CSceneGameplay**
------------------------
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

class **CSceneDungeon**
-----------------------
(inherits from CSceneGameplay)