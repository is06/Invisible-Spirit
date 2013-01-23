/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_LEVEL_MESH_H__
#define __IS06_LEVEL_MESH_H__

#include "../../include/model/CStaticModel.h"

namespace is06
{
namespace n3D
{

//! Static model with collision mask loading function
class CLevelMesh : public CStaticModel
{
  public:
    CLevelMesh();
    ~CLevelMesh();

    void update();
    void loadCollisionMask();
};

}
}

#endif
