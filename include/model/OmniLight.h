#ifndef __IS06_OMNI_LIGHT_H__
#define __IS06_OMNI_LIGHT_H__

#include "../../include/model/Light.h"

namespace is06
{
namespace model
{

//! A light entity that emits in all directions
class COmniLight : public CLight
{
  public:
    COmniLight();
    ~COmniLight();
};

}
}

#endif
