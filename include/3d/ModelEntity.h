/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MODEL_ENTITY_H__
#define __IS06_MODEL_ENTITY_H__

#include "../Entity.h"

using namespace irr;

class ModelEntity : public Entity {

  public:
    ModelEntity();
    virtual ~ModelEntity();

    virtual void render();
    virtual void createNode(const core::vector3df& initPosition) = 0;

    void setVisible(bool value);
    void hide();
    void show();

    // TODO :
    //void setGhost(bool value);
    //void setWireFrame(bool value);
    //void setDebugData(bool value);

    void loadMesh(const core::stringc& meshFilePath);

    scene::ISceneNode* getNode();
    scene::IMesh* getMesh();
    video::SMaterial& getMaterial();
    NewtonBody* getMainBody();

  protected:
    scene::IMesh* mainMesh;
    scene::ISceneNode* mainNode;
    NewtonBody* mainBody;
};

#endif
