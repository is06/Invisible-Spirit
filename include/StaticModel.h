/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_STATIC_MODEL_H__
#define __IS06_STATIC_MODEL_H__

class StaticModel : public ModelEntity {
  public:
    StaticModel();
    ~StaticModel();

    virtual void render();

    void createNode(const core::vector3df& initPosition);
};

#endif
