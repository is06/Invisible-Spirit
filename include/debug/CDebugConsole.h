/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DEBUG_CONSOLE_H__
#define __IS06_DEBUG_CONSOLE_H__

using namespace irr;

namespace is06
{
namespace nDebug
{

class CDebugConsole
{
  public:
    CDebugConsole();
    ~CDebugConsole();

    void render();
    void executeCurrentCommand();

  private:
    void manageSceneInterface(const vector<string>& elements);
    s32 stringToInt(const string& str);

    void execute_scene_set_light_color(u8 alpha, u8 red, u8 green, u8 blue);

    gui::IGUIEditBox* CommandTextInput;
};

}
}

#endif
