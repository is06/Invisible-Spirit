/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_WORLD_TIME_COUNTER_H__
#define __IS06_WORLD_TIME_COUNTER_H__

#include "Counter.h"

using namespace std;

class WorldTimeCounter : public Counter
{
  public:
    WorldTimeCounter();
    ~WorldTimeCounter();

    void render();
    void render(s32 worldTime);
    void hide();
    void show();
    void setOpacity(u8 value);

  private:
    wstring minutes;
    wstring hours;

    Text* counterText;

    void updateValues(s32 time);
    void updateDigits();
};

#endif

