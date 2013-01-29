/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PAUSE_SUB_SCREEN_STORY_H__
#define __IS06_PAUSE_SUB_SCREEN_STORY_H__

#include "../CSubScreen.h"

namespace is06
{
namespace NHud
{
namespace NPauseScreen
{
namespace NSubScreen
{

class CStory : public CSubScreen
{
  public:
    CStory();
    ~CStory();

    void render();
};

}
}
}
}

#endif