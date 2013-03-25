/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MINI_MAP_ARROW_H__
#define __IS06_MINI_MAP_ARROW_H__

#include "../Hud/CHud.h"

using namespace irr;

namespace is06 { namespace NHud { namespace NPart {

class CMiniMapArrow : public CHud
{
public:
  CMiniMapArrow(video::SColor color);
  ~CMiniMapArrow();

  void render();
  void hide();
  void show();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();
  void setPosition(f32 x, f32 y);
  void setRotation(f32 value);

private:
  bool Visible;
  f32 Opacity;
  video::S3DVertex Vertices[3];
  u16 Indices[3];
  core::matrix4 AbsoluteTransformation;
  video::SMaterial Material;
};

}}}

#endif
