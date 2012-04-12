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

namespace is06
{
namespace model
{

class CModelEntity : public engine::CEntity
{
  public:
    CModelEntity();
    virtual ~CModelEntity();

    virtual void update() = 0;
    virtual void shaderRender();
    virtual void createNode(const irr::core::vector3df& initPosition) = 0;

    virtual void setVisible(bool value) = 0;
    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void setGhost(bool value) = 0;
    virtual void setWireFrame(bool value) = 0;
    virtual void setDebugData(bool value) = 0;
    virtual void darken() = 0;
    virtual void undarken() = 0;

    virtual irr::video::SMaterial& getMaterial() = 0;

    virtual void turnX(irr::f32 speed) = 0;
    virtual void turnY(irr::f32 speed) = 0;
    virtual void turnZ(irr::f32 speed) = 0;
    virtual void moveX(irr::f32 speed) = 0;
    virtual void moveY(irr::f32 speed) = 0;
    virtual void moveZ(irr::f32 speed) = 0;

    virtual void setShadowMode(engine::EShadowMode mode = engine::SHADOW_MODE_CAST) = 0;

    void loadMesh(const std::string& meshFilePath);

    void attachSpeaker(sound::CSpeaker* speaker);
    void detachSpeaker();

    irr::scene::IMesh* getMesh();
    NewtonBody* getMainBody();

  protected:
    irr::scene::IMesh* MainMesh;
    NewtonBody* MainBody;
    sound::CSpeaker* AttachedSpeaker;
};

}
}

#endif
