Text file format
================

File name extension: ist (for "Invisible Spirit Text")

Description
-----------

There are two distinct type of text files : global and maps text files.
The name of the global one is "global.ist" and is located in bin/resource/text/{locale} (for example {locale} can be "eng-GB").
The name of the map one contains the name of the map: "MAP_ALPHA_ZONE.ist" for example. Same location as global.ist.

File format
-----------

Thoses files are plain text files, it's just a list of text items with an identifier and a value:

identifier1=value1  
identifier2=value2  
...

Identifiers can be used directly in the C++ code or in dialogs.

### Use in code

(File src/NHud/NPauseScreen/CPauseScreen.cpp)

`GlobalTranslations->getTranslation("gameplay_menu_swords")`

This line retrieves a text defined in global.ist (because the object **GlobalTranslation** reads the file at the game start)
The same C++ methods can be used with **SceneTranslations** object defined in scenes:

Defines the SceneTranslations object in a map:

`SceneTranslations = new NEngine::NResource::CTranslation("MAP_ALPHA_ZONE.ist");`

Use a specific-map text:

`SceneTranslations->getTranslation("norya_time_and_space");`

### Use in dialogs

Sets the dialog interface for this scene with map texts:

`Dialog = new NEngine::NGameplay::CDialogInterface("MAP_ALPHA_ZONE.isd", SceneTranslations, Control);`

Notice that SceneTranslations object is passed in the CDialogInterface constructor because it'll use it.

Start a dialog:

`Dialog->start("norya_first_start");`