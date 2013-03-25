/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PICTURE_H__
#define __IS06_PICTURE_H__

#include "Primitive/CFlatElement.h"

using namespace irr;

namespace is06 { namespace NHud { namespace NPrimitive {

class CPicture : public NPrimitive::CFlatElement
{
public:
  CPicture(f32 x = 0, f32 y = 0, f32 w = 32, f32 h = 32, const string& filePath = "resource/hud/default.bmp", bool useAlphaBlending = true);
  ~CPicture();

  void render();
  void loadSecondTexture(const string& filePath);
  void changeTexture(const string& filePath);
  void setRenderTarget(video::ITexture* renderTargetTexture);
};

}}}

#endif

