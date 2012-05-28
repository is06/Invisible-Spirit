/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_QUAD_H__
#define __IS06_QUAD_H__

#include "../hud/CHud2DElement.h"

using namespace irr;

namespace is06
{
namespace nHud
{

class CQuad : public CHud2DElement
{
  public:
    CQuad(f32 x, f32 y, f32 w, f32 h, video::SColor color);
    ~CQuad();

    void render();

  private:

};

}
}

#endif
