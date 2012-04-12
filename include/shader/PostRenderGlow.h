/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_POST_RENDER_GLOW_H__
#define __IS06_POST_RENDER_GLOW_H__

#include "../gui/Hud2DElement.h"

namespace is06
{
namespace shader
{

class CPostRenderGlow : public hud::CHud2DElement
{
  public:
    CPostRenderGlow();
    ~CPostRenderGlow();

    void render();
};

}
}

#endif
