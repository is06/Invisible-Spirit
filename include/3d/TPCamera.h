/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TPCAMERA_H__
#define __IS06_TPCAMERA_H__

class TPCamera : public Camera {
  public:
    TPCamera();

    void render();

    void goLeft(s8 speed);
    void goRight(s8 speed);
    void goFar(s8 speed);
    void goNear(s8 speed);

    void linkEntity(Ayron* entity);
    f32 getDistance();

  private:
    Ayron* linkedEntity;
    f32 UAxis;
    f32 height;
    f32 distance;
};

#endif
