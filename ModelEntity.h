/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#ifndef __IS06_MODEL_ENTITY_H__
#define __IS06_MODEL_ENTITY_H__

using namespace irr;

void applyForceAndTorqueCallback(const NewtonBody*, float timestep, int threadIndex);
void setTransformCallback(const NewtonBody*, const float* matrix, int threadIndex);

class ModelEntity : public Entity {

  public:
    ModelEntity();
    virtual ~ModelEntity();

    virtual void render();
    virtual void createNode(const core::vector3df& initPosition) = 0;

    void loadMesh(const core::stringc& meshFilePath);
    void setCollisionType(CollisionType ct = COLLISION_BOX, bool optimizeMesh=false);
    void setCollisionTarget(ModelEntity* other);
    void updateBody();

    scene::ISceneNode* getNode();
    NewtonBody* getMainBody();

  protected:
    scene::IMesh* mainMesh;
    scene::ISceneNode* mainNode;
    NewtonBody* mainBody;

  private:
    void setBoxCollision(NewtonWorld* world);
    void setCylinderCollision(NewtonWorld* world);
    void setMeshCollision(NewtonWorld* world, bool optimize=false);
    void addMeshToTreeCollision(video::E_VERTEX_TYPE vertexType, scene::IMeshBuffer* meshBuffer, NewtonCollision* treeCollision, core::vector3df scale);
};

#endif
