/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MODEL_ENTITY_H__
#define __IS06_MODEL_ENTITY_H__

#include "../Entity.h"
#include "../enums/engine/ShadowMode.h"

using namespace irr;
using namespace std;

class ModelEntity : public Entity
{
  public:
    ModelEntity();
    virtual ~ModelEntity();

    virtual void update() = 0;
    virtual void shaderRender();
    virtual void createNode(const core::vector3df& initPosition) = 0;

    virtual void setVisible(bool value) = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void setGhost(bool value) = 0;
    virtual void setWireFrame(bool value) = 0;
    virtual void setDebugData(bool value) = 0;

    virtual video::SMaterial& getMaterial() = 0;

    virtual void turnX(f32 speed) = 0;
    virtual void turnY(f32 speed) = 0;
    virtual void turnZ(f32 speed) = 0;
    virtual void moveX(f32 speed) = 0;
    virtual void moveY(f32 speed) = 0;
    virtual void moveZ(f32 speed) = 0;

    virtual void setShadowMode(ShadowMode mode = SHADOW_MODE_CAST) = 0;

    void loadMesh(const string& meshFilePath);

    void attachSpeaker(Speaker* spk);
    void detachSpeaker();

    scene::IMesh* getMesh();
    NewtonBody* getMainBody();

  protected:
    scene::IMesh* mainMesh;
    NewtonBody* mainBody;
    Speaker* attachedSpeaker;

    bool renderForGlow;
    bool renderForShadowPass1;
    bool renderForShadowPass2;
};

#endif
