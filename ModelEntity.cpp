/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#include "core.h"

using namespace irr;
using namespace std;

/**
 * Initialise les objets liés à l'entité à savoir le mesh, le node, et l'état de mouvement Bullet
 */
ModelEntity::ModelEntity() : Entity() {
  mainMesh = NULL;
  mainNode = NULL;
}

/**
 * Fonction de mise à jour et de rendu des entités Modèles 3D
 */
void ModelEntity::render() { Entity::render();
  updateBody();
  f32 newtMatrix[16] = {};
  NewtonBodyGetMatrix(mainBody, newtMatrix);
  //_matrix_print(newtMatrix);
}

/**
 * Charge un mesh dans l'entité
 * @param stringc& meshFilePath référence vers une chaine désignant le chemin du fichier mesh à charger
 */
void ModelEntity::loadMesh(const core::stringc& meshFilePath) {
  mainMesh = Game::getSceneManager()->getMesh(meshFilePath);
}

/**
 * TODO
 */
void ModelEntity::setCollisionType(CollisionType ct, bool optimizeMesh) {
  if(mainNode) {
    switch(ct) {
      case COLLISION_BOX:
        setBoxCollision(Game::getNewtonWorld());
      break;
      case COLLISION_CYLINDER:
        setCylinderCollision(Game::getNewtonWorld());
      break;
      case COLLISION_MESH:
        setMeshCollision(Game::getNewtonWorld(), optimizeMesh);
      break;
      default:
      break;
    }
  } else {
    // TODO : indiquer en log ou console que le node n'a pas été créé
  }
}

/**
 * Retourne le node Irrlicht de l'entité
 * @return ISceneNode* le noeud de l'entité
 */
scene::ISceneNode* ModelEntity::getNode() {
  return mainNode;
}

NewtonBody* ModelEntity::getMainBody() {
  return mainBody;
}

void ModelEntity::setBoxCollision(NewtonWorld* world) {
  if(mainNode) {
    core::vector3df scale = mainNode->getScale();
    f32 sx = mainNode->getBoundingBox().getExtent().X * scale.X;
    f32 sy = mainNode->getBoundingBox().getExtent().Y * scale.Y;
    f32 sz = mainNode->getBoundingBox().getExtent().Z * scale.Z;
    NewtonCollision* collision = NewtonCreateBox(world, sx, sy, sz, 0, NULL);

    f32 newtMatrix[16] = {};

    mainBody = NewtonCreateBody(world, collision, newtMatrix);
    NewtonBodySetUserData(mainBody, mainNode);

    mainNode->updateAbsolutePosition();

    core::matrix4 irrMatrix = mainNode->getRelativeTransformation();
    NewtonBodySetMatrix(mainBody, irrMatrix.pointer());

    NewtonBodySetTransformCallback(mainBody, setTransformCallback);
    NewtonBodySetForceAndTorqueCallback(mainBody, applyForceAndTorqueCallback);

    NewtonBodySetMassMatrix(mainBody, 0.0f, 0.0f, 0.0f, 0.0f);

    NewtonReleaseCollision(world, collision);
  }
}

void ModelEntity::setCylinderCollision(NewtonWorld* world) {
  if(mainNode) {
    core::vector3df scale = mainNode->getScale();
    f32 sx = mainNode->getBoundingBox().getExtent().X * scale.X;
    f32 sy = mainNode->getBoundingBox().getExtent().Y * scale.Y;
    NewtonCollision* collision = NewtonCreateCylinder(world, (sx / 2), sy, 0, NULL);

    f32 newtMatrix[16] = {};

    mainBody = NewtonCreateBody(world, collision, newtMatrix);
    NewtonBodySetUserData(mainBody, mainNode);

    mainNode->updateAbsolutePosition();

    core::matrix4 irrMatrix = mainNode->getRelativeTransformation();
    NewtonBodySetMatrix(mainBody, irrMatrix.pointer());

    NewtonBodySetTransformCallback(mainBody, setTransformCallback);
    NewtonBodySetForceAndTorqueCallback(mainBody, applyForceAndTorqueCallback);

    NewtonBodySetMassMatrix(mainBody, 0.0f, 0.0f, 0.0f, 0.0f);

    NewtonReleaseCollision(world, collision);
  }
}

void ModelEntity::setMeshCollision(NewtonWorld* world, bool optimize) {
  if(mainNode) {
    NewtonCollision* treeCollision = NewtonCreateTreeCollision(world, 0);

    core::vector3df scale = mainNode->getScale();

    NewtonTreeCollisionBeginBuild(treeCollision);

    // On récupère les meshBuffer, à chaque meshBuffer, on ajoute les informations à la collision
    for(u32 i = 0; i < mainMesh->getMeshBufferCount(); i++) {
      scene::IMeshBuffer* mb = mainMesh->getMeshBuffer(i);
      addMeshToTreeCollision(mb->getVertexType(), mb, treeCollision, mainNode->getScale());
    }

    if(optimize) {
      NewtonTreeCollisionEndBuild(treeCollision, 1);
    } else {
      NewtonTreeCollisionEndBuild(treeCollision, 0);
    }

    // Création du Body Newton
    f32 newtMatrix[16] = {};
    mainBody = NewtonCreateBody(world, treeCollision, newtMatrix);

    mainNode->updateAbsolutePosition();

    core::matrix4 irrMatrix = mainNode->getRelativeTransformation();

    NewtonBodySetMatrix(mainBody, irrMatrix.pointer());

    NewtonReleaseCollision(world, treeCollision);
  }
}

void ModelEntity::addMeshToTreeCollision(video::E_VERTEX_TYPE vertexType, scene::IMeshBuffer* meshBuffer, NewtonCollision* treeCollision, core::vector3df scale) {
  // Tableau qui peut contenir 3 vertices servant à ajouter une face à la collision
  f32 vArray[9];
  bool skipAddMesh = false;
  video::S3DVertex* vertices;

  // On récupère les vertices du mesh dans un tableau
  switch(vertexType) {
    case video::EVT_STANDARD:
      vertices = (video::S3DVertex*) meshBuffer->getVertices();
    break;
    case video::EVT_2TCOORDS:
      vertices = (video::S3DVertex2TCoords*) meshBuffer->getVertices();
    break;
    case video::EVT_TANGENTS:
      vertices = (video::S3DVertexTangents*) meshBuffer->getVertices();
    break;
    default:
      // Type de vertex inconnu, on ne créé pas la collision
      // TODO : l'indiquer dans un log ou la console
      skipAddMesh = true;
    break;
  }

  if(!skipAddMesh) {
    // On récupère tous les indices du mesh dans un tableau
    u16* indices = meshBuffer->getIndices();

    // Les indices permettent de récupérer un vertex précis dans l'ordre ou il a été créé
    // On récupère les vertices par groupe de 3 pour former une face (polygone)
    for(u32 j = 0; j < meshBuffer->getIndexCount(); j += 3) {
      // On récupère les indices des trois vertices courants
      s32 v1i = indices[j];
      s32 v2i = indices[j + 1];
      s32 v3i = indices[j + 2];

      // On récupère les vertices spécifiés par les indices et on applique à leur Position l'échelle du node
      vArray = {
        (vertices[v1i].Pos * scale.X).X,
        (vertices[v1i].Pos * scale.X).Y,
        (vertices[v1i].Pos * scale.X).Z,
        (vertices[v2i].Pos * scale.Y).X,
        (vertices[v2i].Pos * scale.Y).Y,
        (vertices[v2i].Pos * scale.Y).Z,
        (vertices[v3i].Pos * scale.Z).X,
        (vertices[v3i].Pos * scale.Z).Y,
        (vertices[v3i].Pos * scale.Z).Z
      };

      // On ajoute la face à la collision - params(collision, nombreDeVertices, pointeurVersTableauDeVertices, tailleDuVertexEnOctets, ID de la face)
      NewtonTreeCollisionAddFace(treeCollision, 3, vArray, sizeof(f32) * 3, 1);
    }
  }
}

/**
 * Fonction appelée par Newton pour mettre à jour la transformation du node Irrlicht
 * @param NewtonBody* body le body Newton depuis lequel récupérer le node
 * @param float* matrix la matrice de transformation fournie par Newton pour le node
 * @param int threadIndex index du thread pour de l'exécution en parallélisme
 */
void setTransformCallback(const NewtonBody* body, const float* matrix, int threadIndex) {
  // On récupère le node depuis la mémoire UserData du Body Newton
  scene::ISceneNode* node = (scene::ISceneNode*)NewtonBodyGetUserData(body);
  if(node) {
    core::matrix4 irrMatrix;
    memcpy(irrMatrix.pointer(), matrix, sizeof(f32)*16);

    node->setPosition(irrMatrix.getTranslation());
    node->setRotation(irrMatrix.getRotationDegrees());
    node->updateAbsolutePosition();
  }
}

/**
 * Calcule et applique une force de gravité au body Newton
 * @param NewtonBody* body le body Newton auquel on applique la force
 */
void applyForceAndTorqueCallback(const NewtonBody* body, float timestep, int threadIndex) {
  f32 Ixx, Iyy, Izz;
  f32 mass;

  // On récupère l'information de masse du body en passant la variable mass par référence
  // Ixx, Iyy, Izz désignent les valeurs de l'inertie du Body
  // La matrice de masse a été définie par NewtonBodySetMassMatrix() dans ModelEntity::setCollisionBox()
  NewtonBodyGetMassMatrix(body, &mass, &Ixx, &Iyy, &Izz);

  // On applique la force sur le Body { x, y, z, w }
  f32 gravityForce[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
  NewtonBodySetForce(body, gravityForce);
}

void ModelEntity::updateBody() {
  core::matrix4 irrMatrix = mainNode->getRelativeTransformation();
  NewtonBodySetMatrix(mainBody, irrMatrix.pointer());
}

/**
 * Détruit les objets initialisés dans le constructeur
 */
ModelEntity::~ModelEntity() {

}
