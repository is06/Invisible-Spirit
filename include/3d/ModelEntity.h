/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MODEL_ENTITY_H__
#define __IS06_MODEL_ENTITY_H__

using namespace irr;

class ModelEntity : public Entity {

  public:
    ModelEntity();
    virtual ~ModelEntity();

    virtual void render();
    virtual void createNode(const core::vector3df& initPosition) = 0;

    void loadMesh(const core::stringc& meshFilePath);
    void loadMeshCollision();

    scene::ISceneNode* getNode();
    NewtonBody* getMainBody();

  protected:
    scene::IMesh* mainMesh;
    scene::ISceneNode* mainNode;
    NewtonBody* mainBody;

  private:
    void addMeshToTreeCollision(video::E_VERTEX_TYPE vertexType, scene::IMeshBuffer* meshBuffer, NewtonCollision* treeCollision, core::vector3df scale);
};

#endif
