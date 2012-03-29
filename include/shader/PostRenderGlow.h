/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_POST_RENDER_GLOW_H__
#define __IS06_POST_RENDER_GLOW_H__

#include "../gui/Hud2DElement.h"

using namespace irr;

class PostRenderGlow : public Hud2DElement
{
  public:
    PostRenderGlow();
    ~PostRenderGlow();

    void render();

  private:
    //video::IRenderTarget* rt1st;
    //video::IRenderTarget* rt2nd;
};

#endif
