/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_H__
#define __IS06_SAVE_H__

using namespace irr;
using namespace std;

class Save {
  public:
    Save();
    ~Save();

    void load();
    void write();
    void createNewFile();

    // Set data
    void powerLevelUp(PowerType type, const core::stringc& id, u32 value);
    void powerExpUp(PowerType type, const core::stringc& id, u32 value);
    void powerGet(PowerType type, const core::stringc& id);
    void playerLevelUp(u32 value);
    void playerExpUp(u32 value);

    // General information
    u8 slot;
    u8 difficultyLevel;

    // Map information
    SceneIdentifier currentMap;

    // Player information
    PlayerData playerData;
    PowerData powerData;

  private:
    void initFightPowers();
    void initMagicPowers();
    void initStatePowers();

};

#endif
