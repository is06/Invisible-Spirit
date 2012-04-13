/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BOX_SENSOR_H__
#define __IS06_BOX_SENSOR_H__

#include "Sensor.h"

namespace is06
{
namespace model
{

//! A concrete but invisible box sensor with collision and presence detection functions
class CBoxSensor : public CSensor
{
  public:
    CBoxSensor(const core::aabbox3df& initBox);
    void update();
    const core::aabbox3df& getBox() const;

  private:
    core::aabbox3df Box;
};

}
}

#endif
