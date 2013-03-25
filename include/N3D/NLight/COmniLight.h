/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_LIGHT_OMNI_LIGHT_H__
#define __IS06_3D_LIGHT_OMNI_LIGHT_H__

#include "../../../include/3D/CLight.h"

namespace is06 { namespace N3D { namespace NLight {

//! A light entity that emits in all directions
class COmniLight : public CLight
{
public:
  COmniLight();
  ~COmniLight();
};

}}}

#endif
