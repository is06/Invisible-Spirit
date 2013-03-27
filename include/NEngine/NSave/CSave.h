/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_SAVE_SAVE_H__
#define __IS06_ENGINE_SAVE_SAVE_H__

#include "../../NScene/ESceneIdentifier.h"
#include "../../NEngine/NGameplay/EDifficultyLevel.h"
#include "../../NEngine/NGameplay/ETrophyIdentifier.h"

namespace is06 { namespace NEngine { namespace NSave {

//! Class for storing variables and using them in scenes or maps
class CSave
{
public:
  CSave();
  ~CSave();

  void loadPrimitiveInfo(u8 slot);
  void load(u8 slot);
  void save(u8 slot);
  void newGame(NEngine::NGameplay::EDifficultyLevel difficultyLevel);

  s32& getInteger(u32 index);
  bool& getBoolean(u32 index);
  string& getString(u32 index);

  void setInteger(u32 index, s32 value);
  void incInteger(u32 index, s32 value);
  void decInteger(u32 index, s32 value);
  void setBoolean(u32 index, bool value);
  void setString(u32 index, const string& value);

  void earnTrophy(NGameplay::ETrophyIdentifier trophy);

private:
  // Data maps
  map<u32, s32> IntegerList;
  map<u32, bool> BooleanList;
  map<u32, string> StringList;

  // Default values
  void setGeneralDefaultValues(NEngine::NGameplay::EDifficultyLevel difficultyLevel);
};

}}}

#endif
