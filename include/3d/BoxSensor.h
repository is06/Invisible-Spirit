/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BOX_SENSOR_H__
#define __IS06_BOX_SENSOR_H__

#include "../Sensor.h"

using namespace irr;

class BoxSensor : public Sensor
{
  public:
    BoxSensor(const core::aabbox3df& initBox);
    void render();
    const core::aabbox3df& getBox() const;

  private:
    core::aabbox3df box;
};

#endif
