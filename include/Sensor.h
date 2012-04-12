/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SENSOR_H__
#define __IS06_SENSOR_H__

#include "Entity.h"

namespace is06
{
namespace model
{

class CSensor : public engine::CEntity
{
  public:
    CSensor();
    virtual void update() = 0;
};

}
}

#endif
