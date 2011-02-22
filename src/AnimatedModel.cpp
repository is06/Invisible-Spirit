/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

/**
 * Constructeur de tous les modèles 3D animés créés dans les scènes
 */
AnimatedModel::AnimatedModel() : ModelEntity() {

}

/**
 * Fonction de mise à jour et de rendu de tous les modèles 3D animés
 */
void AnimatedModel::render() { ModelEntity::render();

}

/**
 * Fonction qui crée le node animé et l'ajoute au gestionnaire de scene Irrlicht
 * @param vector3df& initPosition référence vers un vecteur3df qui désigne la position initiale du node
 */
void AnimatedModel::createNode(const core::vector3df& initPosition) {
  mainNode = Game::getSceneManager()->addAnimatedMeshSceneNode((scene::IAnimatedMesh*)mainMesh);
  if(!mainNode) {
    //Game::getErrorManager()->addError(ELL_ERROR, "AnimatedModel:: Node non cree");
  }
  mainNode->setMaterialFlag(video::EMF_LIGHTING, false);
  mainNode->setPosition(initPosition);
  //mainNode->setDebugDataVisible(scene::EDS_FULL);
}

/**
 *
 */
bool AnimatedModel::collidesWithStatic(StaticModel* other) {
  NewtonCollision* mainBodyCollision = NewtonBodyGetCollision(mainBody);
  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  f32 mainBodyMatrix[16] = {};
  f32 otherBodyMatrix[16] = {};

  NewtonBodyGetMatrix(mainBody, mainBodyMatrix);
  NewtonBodyGetMatrix(other->getMainBody(), otherBodyMatrix);

  s32 res = NewtonCollisionCollide(
    Game::getNewtonWorld(),
    Game::MAX_POINT_COLLIDE,
    mainBodyCollision,
    mainBodyMatrix,
    otherBodyCollision,
    otherBodyMatrix,
    Game::contacts,
    Game::normals,
    Game::penetration,
    0
  );

  return (res > 0);
}

/**
 *
 */
f32 AnimatedModel::getFloorCollision(StaticModel* other) {

  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  f32 normals[3];
  s32 faceId;

  core::vector3df origin(
    mainNode->getPosition().X,
    mainNode->getPosition().Y,
    mainNode->getPosition().Z
  );
  core::vector3df end(
    mainNode->getPosition().X,
    mainNode->getPosition().Y - 1.0f,
    mainNode->getPosition().Z
  );

  f32 ray = NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, normals, &faceId);

  return ray;
}

/**
 *
 */
f32 AnimatedModel::getWallCollisionP(StaticModel* other) {

  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  f32 normals[3];
  s32 faceId;

  core::vector3df origin(
    0.5f * cos(mainNode->getRotation().Y),
    mainNode->getPosition().Y,
    0.5f * sin(mainNode->getRotation().Y)
  );
  core::vector3df end(
    mainNode->getPosition().X - 0.5f,
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + 1.0f
  );

  f32 ray = NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, normals, &faceId);

  return ray;
}

/**
 *
 */
f32 AnimatedModel::getWallCollisionQ(StaticModel* other) {

  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  f32 normals[3];
  s32 faceId;

  core::vector3df origin(
    mainNode->getPosition().X + 0.5f,
    mainNode->getPosition().Y,
    mainNode->getPosition().Z
  );
  core::vector3df end(
    mainNode->getPosition().X + 0.5f,
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + 1.0f
  );

  f32 ray = NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, normals, &faceId);

  return ray;
}

/**
 *
 */
bool AnimatedModel::collidesWithAnimated(AnimatedModel* other) {
  return false;
}

/**
 * Destructeur
 */
AnimatedModel::~AnimatedModel() {
  if(mainNode) {
    mainNode->remove();
    mainNode = NULL;
  }
}
