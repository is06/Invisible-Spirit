/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_STATIC_MODEL_H__
#define __IS06_STATIC_MODEL_H__

#include "../../include/3d/ModelEntity.h"

namespace is06
{
namespace model
{

class CStaticModel : public CModelEntity
{
  public:
    CStaticModel();
    ~CStaticModel();

    virtual void update();
    virtual void shaderRender();

    void setVisible(bool value);
    void hide();
    void show();
    void setGhost(bool value);
    void setWireFrame(bool value);
    void setDebugData(bool value);
    void darken();
    void undarken();

    void turnX(irr::f32 speed);
    void turnY(irr::f32 speed);
    void turnZ(irr::f32 speed);
    void moveX(irr::f32 speed);
    void moveY(irr::f32 speed);
    void moveZ(irr::f32 speed);

    irr::video::SMaterial& getMaterial();

    void loadMeshCollision();
    void clearMeshCollision();
    void createNode(const irr::core::vector3df& initPosition);
    irr::scene::IMeshSceneNode* getNode();

    // Shadows
    void setShadowMode(engine::EShadowMode mode = engine::SHADOW_MODE_CAST);

  protected:
    irr::scene::IMeshSceneNode* MainNode;

  private:
    void addMeshToTreeCollision(irr::video::E_VERTEX_TYPE vertexType, irr::scene::IMeshBuffer* meshBuffer, NewtonCollision* treeCollision, irr::core::vector3df scale);
};

}
}

#endif
