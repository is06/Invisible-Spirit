/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/StaticModel.h"
#include "../../include/Game.h"
#include "../../include/Settings.h"
#include "../../include/scene/Scene.h"
#include "../../include/sound/Speaker.h"

namespace is06
{
namespace model
{

/**
 * Constructor
 */
CStaticModel::CStaticModel() : CModelEntity()
{
  MainNode = NULL;
}

/**
 * Fonction de mise à jour et de rendu de toutes les entités statiques présentes dans les scènes
 */
void CStaticModel::update()
{
  CModelEntity::update();

  // Attached speaker position update
  if (AttachedSpeaker) {
    AttachedSpeaker->setPosition(MainNode->getPosition());
  }
}

/**
 * Render for shader effect
 */
void CStaticModel::shaderRender()
{
  MainNode->render();
}

/**
 * Crée le node et l'ajoute au gestionnaire de scène Irrlicht en fonction de sa position
 * @param vector3df& initPosition référence vers une position initiale du node
 */
void CStaticModel::createNode(const irr::core::vector3df& initPosition)
{
  if (MainMesh) {
    MainNode = engine::CGame::getSceneManager()->addMeshSceneNode(MainMesh);
    MainNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    MainNode->setPosition(initPosition);

    if (engine::CGame::Settings->getParamString("model", "texture_filter") == "anisotropic") {
      MainNode->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
    } else if(engine::CGame::Settings->getParamString("model", "texture_filter") == "trilinear") {
      MainNode->setMaterialFlag(irr::video::EMF_TRILINEAR_FILTER, true);
    } else if(engine::CGame::Settings->getParamString("model", "texture_filter") == "none") {
      MainNode->setMaterialFlag(irr::video::EMF_BILINEAR_FILTER, false);
    } else {
      MainNode->setMaterialFlag(irr::video::EMF_BILINEAR_FILTER, true);
    }
  } else {
    engine::CGame::fatalError(debug::ERRCODE_30);
  }
}

/**
 * Retourne le node Irrlicht de l'entité
 * @return ISceneNode* le noeud de l'entité
 */
irr::scene::IMeshSceneNode* CStaticModel::getNode()
{
  return MainNode;
}

/**
 *
 */
irr::video::SMaterial& CStaticModel::getMaterial()
{
  return MainNode->getMaterial(0);
}

/**
 *
 */
void CStaticModel::hide()
{
  MainNode->setVisible(false);
}

/**
 *
 */
void CStaticModel::show()
{
  MainNode->setVisible(true);
}

/**
 *
 */
void CStaticModel::setVisible(bool value)
{
  MainNode->setVisible(value);
}

/**
 *
 */
void CStaticModel::setGhost(bool value)
{
  MainNode->setMaterialFlag(irr::video::EMF_FRONT_FACE_CULLING, !value);
}

/**
 *
 */
void CStaticModel::setWireFrame(bool value)
{
  MainNode->setMaterialFlag(irr::video::EMF_WIREFRAME, value);
}

/**
 *
 */
void CStaticModel::setDebugData(bool value)
{
  MainNode->setDebugDataVisible(value);
}

/**
 *
 */
void CStaticModel::darken()
{
  MainNode->setMaterialFlag(irr::video::EMF_LIGHTING, true);
}

/**
 *
 */
void CStaticModel::undarken()
{
  MainNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

/**
 *
 */
void CStaticModel::turnX(irr::f32 speed)
{
  MainNode->setRotation(irr::core::vector3df(
    MainNode->getRotation().X + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getRotation().Y,
    MainNode->getRotation().Z
  ));
}

/**
 *
 */
void CStaticModel::turnY(irr::f32 speed)
{
  MainNode->setRotation(irr::core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getRotation().Z
  ));
}

/**
 *
 */
void CStaticModel::turnZ(irr::f32 speed)
{
  MainNode->setRotation(irr::core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y,
    MainNode->getRotation().Z + (speed * engine::CGame::getSpeedFactor())
  ));
}

/**
 *
 */
void CStaticModel::moveX(irr::f32 speed)
{
  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getPosition().Y,
    MainNode->getPosition().Z
  ));
}

/**
 *
 */
void CStaticModel::moveY(irr::f32 speed)
{
  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getPosition().Z
  ));
}

/**
 *
 */
void CStaticModel::moveZ(irr::f32 speed)
{
  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y,
    MainNode->getPosition().Z + (speed * engine::CGame::getSpeedFactor())
  ));
}

/**
 *
 */
void CStaticModel::loadMeshCollision()
{
  bool optimize = true;

  if (MainNode) {
    NewtonCollision* treeCollision = NewtonCreateTreeCollision(engine::CGame::getNewtonWorld(), 0);
    NewtonTreeCollisionBeginBuild(treeCollision);

    // On récupère les meshBuffer, à chaque meshBuffer, on ajoute les informations à la collision
    for (irr::u32 i = 0; i < MainMesh->getMeshBufferCount(); i++) {
      irr::scene::IMeshBuffer* mb = MainMesh->getMeshBuffer(i);
      addMeshToTreeCollision(mb->getVertexType(), mb, treeCollision, MainNode->getScale());
    }

    if (optimize) {
      NewtonTreeCollisionEndBuild(treeCollision, 1);
    } else {
      NewtonTreeCollisionEndBuild(treeCollision, 0);
    }

    // Création du Body Newton
    irr::f32 newtMatrix[16] = {};
    MainBody = NewtonCreateBody(engine::CGame::getNewtonWorld(), treeCollision, newtMatrix);
    MainNode->updateAbsolutePosition();

    irr::core::matrix4 irrMatrix = MainNode->getRelativeTransformation();
    NewtonBodySetMatrix(MainBody, irrMatrix.pointer());
    NewtonReleaseCollision(engine::CGame::getNewtonWorld(), treeCollision);
  }
}

/**
 * Ajoute un polygone à une collision Newton de type Mesh
 */
void CStaticModel::addMeshToTreeCollision(irr::video::E_VERTEX_TYPE vertexType, irr::scene::IMeshBuffer* meshBuffer,
  NewtonCollision* treeCollision, irr::core::vector3df scale)
{
  // Tableau qui peut contenir 3 vertices servant à ajouter une face à la collision
  irr::f32 vArray[9];
  bool skipAddMesh = false;
  irr::video::S3DVertex* vertices;

  // On récupère les vertices du mesh dans un tableau
  switch (vertexType) {
    case irr::video::EVT_STANDARD:
      vertices = (irr::video::S3DVertex*) meshBuffer->getVertices();
      break;
    case irr::video::EVT_2TCOORDS:
      vertices = (irr::video::S3DVertex2TCoords*) meshBuffer->getVertices();
      break;
    case irr::video::EVT_TANGENTS:
      vertices = (irr::video::S3DVertexTangents*) meshBuffer->getVertices();
      break;
    default:
      // Type de vertex inconnu, on ne créé pas la collision
      skipAddMesh = true;
      break;
  }

  if (!skipAddMesh) {
    // On récupère tous les indices du mesh dans un tableau
    irr::u16* indices = meshBuffer->getIndices();

    // Les indices permettent de récupérer un vertex précis dans l'ordre ou il a été créé
    // On récupère les vertices par groupe de 3 pour former une face (polygone)
    for (irr::u32 j = 0; j < meshBuffer->getIndexCount(); j += 3) {
      // On récupère les indices des trois vertices courants
      irr::s32 v1i = indices[j];
      irr::s32 v2i = indices[j + 1];
      irr::s32 v3i = indices[j + 2];

      // On récupère les vertices spécifiés par les indices et on applique à leur Position l'échelle du node
      vArray[0] = (vertices[v1i].Pos * scale.X).X;
      vArray[1] = (vertices[v1i].Pos * scale.X).Y;
      vArray[2] = (vertices[v1i].Pos * scale.X).Z;
      vArray[3] = (vertices[v2i].Pos * scale.Y).X;
      vArray[4] = (vertices[v2i].Pos * scale.Y).Y;
      vArray[5] = (vertices[v2i].Pos * scale.Y).Z;
      vArray[6] = (vertices[v3i].Pos * scale.Z).X;
      vArray[7] = (vertices[v3i].Pos * scale.Z).Y;
      vArray[8] = (vertices[v3i].Pos * scale.Z).Z;

      // On ajoute la face à la collision - params(collision, nombreDeVertices, pointeurVersTableauDeVertices, tailleDuVertexEnOctets, ID de la face)
      NewtonTreeCollisionAddFace(treeCollision, 3, vArray, sizeof(irr::f32) * 3, 1);
    }
  }
}

/**
 *
 */
void CStaticModel::clearMeshCollision()
{
  NewtonDestroyBody(engine::CGame::getNewtonWorld(), MainBody);
}

/**
 *
 */
void CStaticModel::setShadowMode(engine::EShadowMode mode)
{
  engine::CGame::getCurrentScene()->getShadowProcessor()->setEntity(MainNode, mode);
}

/**
 *
 */
CStaticModel::~CStaticModel()
{
  if (MainNode) {
    MainNode->remove();
    MainNode = NULL;
  }
}

}
}
