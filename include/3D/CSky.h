/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SKY_H__
#define __IS06_SKY_H__

#include "../Engine/CEntity.h"

namespace is06
{
namespace N3D
{

class CSky : public NEngine::CEntity
{
  public:
    CSky(const string& textureName);
    ~CSky();

    void update();
    void setLayer(u8 index, const string& textureName);
    void setFrontLayerOpacity(u8 level);
    void setRotationSpeed(u8 index, f32 speed);

  private:
    scene::ISceneNode* Layers[2];
    f32 RotationSpeed[2];
};

}
}

#endif
