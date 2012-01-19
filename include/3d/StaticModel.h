/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_STATIC_MODEL_H__
#define __IS06_STATIC_MODEL_H__

#include "../../include/3d/ModelEntity.h"

using namespace irr;
using namespace std;

class StaticModel : public ModelEntity {
  public:
    StaticModel();
    ~StaticModel();

    virtual void render();

    void setVisible(bool value);
    void hide();
    void show();
    void setGhost(bool value);
    void setWireFrame(bool value);
    void setDebugData(bool value);

    video::SMaterial& getMaterial();

    void loadMeshCollision();
    void clearMeshCollision();
    void createNode(const core::vector3df& initPosition);
    scene::IMeshSceneNode* getNode();

  protected:
    scene::IMeshSceneNode* mainNode;

  private:
    void addMeshToTreeCollision(video::E_VERTEX_TYPE vertexType, scene::IMeshBuffer* meshBuffer, NewtonCollision* treeCollision, core::vector3df scale);
};

#endif
