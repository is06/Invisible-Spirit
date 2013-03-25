/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_POST_RENDER_GLOW_H__
#define __IS06_POST_RENDER_GLOW_H__

#include "CPostRenderShader.h"

using namespace irr;

namespace is06 { namespace NShader {

//! Aligned screen quad for post render in order to simulate a light glowing effect
class CPostRenderGlow : public CPostRenderShader
{
public:
  CPostRenderGlow();
  ~CPostRenderGlow();

  void render();

protected:
  video::SColor BackBufferColor;
};

}}

#endif
