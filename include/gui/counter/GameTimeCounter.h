/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAME_TIME_COUNTER_H__
#define __IS06_GAME_TIME_COUNTER_H__

#include "Counter.h"

using namespace std;

class GameTimeCounter : public Counter
{
  public:
    GameTimeCounter();
    ~GameTimeCounter();

    void render();
    void render(s32 totalGameTime);
    void hide();
    void show();
    void setOpacity(u8 value);

  private:
    string seconds;
    string minutes;
    string hours;

    Text* counterText;

    void updateValues(s32 time);
    void updateDigits();
};

#endif