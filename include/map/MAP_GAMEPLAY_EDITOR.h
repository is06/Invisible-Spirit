/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_GAMEPLAY_EDITOR_H__
#define __IS06_MAP_GAMEPLAY_EDITOR_H__

using namespace irr;
using namespace std;

class MAP_GAMEPLAY_EDITOR : public SceneGameplay {
  public:
    MAP_GAMEPLAY_EDITOR();
    ~MAP_GAMEPLAY_EDITOR();

    void events();

  private:
    map<u32, Light*> lightMap;
    map<u32, Speaker*> speakerMap;
    map<u32, Trigger*> triggerMap;
};

#endif
