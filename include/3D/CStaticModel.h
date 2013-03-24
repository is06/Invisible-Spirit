/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_STATIC_MODEL_H__
#define __IS06_3D_STATIC_MODEL_H__

#include "../../include/3D/CModelEntity.h"

namespace is06
{
namespace N3D
{

//! A static model entity base class, the mesh has no animation
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
    void lighten();
    void unlighten();
    void textureSwitch();

    void turnX(f32 speed);
    void turnY(f32 speed);
    void turnZ(f32 speed);
    void moveX(f32 speed);
    void moveY(f32 speed);
    void moveZ(f32 speed);

    video::SMaterial& getMaterial();

    void loadMeshCollision();
    void clearMeshCollision();
    void createNode(const core::vector3df& initPosition);
    scene::IMeshSceneNode* getNode();

    // Shadows
    void setShadowMode(NShader::EShadowMode mode = NShader::ESM_CAST);

  protected:
    scene::IMeshSceneNode* MainNode;

  private:
    void addMeshToTreeCollision(video::E_VERTEX_TYPE vertexType, scene::IMeshBuffer* meshBuffer, NewtonCollision* treeCollision, core::vector3df scale);
};

}
}

#endif
