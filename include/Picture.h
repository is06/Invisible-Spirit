/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PICTURE_H__
#define __IS06_PICTURE_H__

using namespace irr;
using namespace std;

class Picture : public Hud2DElement {
  public:
    Picture(f32 w, f32 h, f32 x, f32 y, const core::stringc& filePath);
    ~Picture();

    void render();
};

#endif
