/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MODEL_ENTITY_H__
#define __IS06_MODEL_ENTITY_H__

#include "../engine/Entity.h"
#include "../engine/ShadowMode.h"

namespace is06
{
namespace n3D
{

//! Abstract class for all 3D models entities
class CModelEntity : public nEngine::CEntity
{
  public:
    CModelEntity();
    virtual ~CModelEntity();

    virtual void update() = 0;
    virtual void shaderRender();
    virtual void createNode(const core::vector3df& initPosition) = 0;

    virtual void setVisible(bool value) = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void setGhost(bool value) = 0;
    virtual void setWireFrame(bool value) = 0;
    virtual void setDebugData(bool value) = 0;
    virtual void darken() = 0;
    virtual void undarken() = 0;

    virtual video::SMaterial& getMaterial() = 0;

    virtual void turnX(f32 speed) = 0;
    virtual void turnY(f32 speed) = 0;
    virtual void turnZ(f32 speed) = 0;
    virtual void moveX(f32 speed) = 0;
    virtual void moveY(f32 speed) = 0;
    virtual void moveZ(f32 speed) = 0;

    virtual void setShadowMode(nEngine::EShadowMode mode = nEngine::SHADOW_MODE_CAST) = 0;

    void loadMesh(const string& meshFilePath);

    void attachSpeaker(nSound::CSpeaker* speaker);
    void detachSpeaker();

    scene::IMesh* getMesh();
    NewtonBody* getMainBody();

  protected:
    scene::IMesh* MainMesh;
    NewtonBody* MainBody;
    nSound::CSpeaker* AttachedSpeaker;
};

}
}

#endif
