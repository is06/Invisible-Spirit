/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Engine/CGame.h"
#include "../../include/Engine/Resource/CSettings.h"
#include "../../include/3D/CStaticModel.h"
#include "../../include/Scene/CScene.h"
#include "../../include/Sound/CSpeaker.h"

using namespace irr;

namespace is06
{
namespace N3D
{

//! Constructor
CStaticModel::CStaticModel() : CModelEntity()
{
  MainNode = NULL;
}

//! Update method, called every cycle for event testing
void CStaticModel::update()
{
  CModelEntity::update();

  // Attached speaker position update
  if (AttachedSpeaker) {
    AttachedSpeaker->setPosition(MainNode->getPosition());
  }
}

//! Render for shader effect
void CStaticModel::shaderRender()
{
  MainNode->render();
}

//! Loads mesh and creates Irrlicht node
void CStaticModel::createNode(const core::vector3df& initPosition)
{
  if (MainMesh) {
    MainNode = NEngine::CGame::getSceneManager()->addMeshSceneNode(MainMesh);
    MainNode->setMaterialFlag(video::EMF_LIGHTING, false);
    if (NEngine::CGame::Settings->getParamString("model", "anti_aliasing") == "enabled") {
      MainNode->getMaterial(0).AntiAliasing = video::EAAM_LINE_SMOOTH;
    }

    // Initial position
    MainNode->setPosition(initPosition);

    // Texture filtering
    if (NEngine::CGame::Settings->getParamString("model", "texture_filter") == "anisotropic") {
      MainNode->setMaterialFlag(video::EMF_ANISOTROPIC_FILTER, true);
    } else if(NEngine::CGame::Settings->getParamString("model", "texture_filter") == "trilinear") {
      MainNode->setMaterialFlag(video::EMF_TRILINEAR_FILTER, true);
    } else if(NEngine::CGame::Settings->getParamString("model", "texture_filter") == "none") {
      MainNode->setMaterialFlag(video::EMF_BILINEAR_FILTER, false);
    } else {
      MainNode->setMaterialFlag(video::EMF_BILINEAR_FILTER, true);
    }
  } else {
    NEngine::CGame::fatalError(NDebug::ERROR_CODE_30);
  }
}

//! Returns the Irrlicht node of this model
scene::IMeshSceneNode* CStaticModel::getNode()
{
  return MainNode;
}

//! Returns the Irrlicht main material of this model
video::SMaterial& CStaticModel::getMaterial()
{
  return MainNode->getMaterial(0);
}

//! Hides the model
void CStaticModel::hide()
{
  MainNode->setVisible(false);
}

//! Shows the model
void CStaticModel::show()
{
  MainNode->setVisible(true);
}

//! Shows/Hides the model
void CStaticModel::setVisible(bool value)
{
  MainNode->setVisible(value);
}

//! Shows/Hides the model with front face culling method
void CStaticModel::setGhost(bool value)
{
  MainNode->setMaterialFlag(video::EMF_FRONT_FACE_CULLING, !value);
}

//! Sets the wireframe mode for this model
void CStaticModel::setWireFrame(bool value)
{
  MainNode->setMaterialFlag(video::EMF_WIREFRAME, value);
}

//! Shows/Hide Irrlicht debug data for this model
void CStaticModel::setDebugData(bool value)
{
  MainNode->setDebugDataVisible(value);
}

//! Sets the dark mode so the model is totally black for post process effects
void CStaticModel::darken()
{
  MainNode->setMaterialFlag(video::EMF_LIGHTING, true);
}

//! Disable the dark mode for this model
void CStaticModel::undarken()
{
  MainNode->setMaterialFlag(video::EMF_LIGHTING, false);
}

void CStaticModel::lighten()
{

}

void CStaticModel::unlighten()
{

}

void CStaticModel::textureSwitch()
{
  video::ITexture* tempTexture = MainNode->getMaterial(0).getTexture(0);
  MainNode->getMaterial(0).setTexture(0, MainNode->getMaterial(0).getTexture(1));
  MainNode->getMaterial(0).setTexture(1, tempTexture);
}

//! Turns the model along the X axis
void CStaticModel::turnX(f32 speed)
{
  MainNode->setRotation(core::vector3df(
    MainNode->getRotation().X + (speed * NEngine::CGame::getSpeedFactor()),
    MainNode->getRotation().Y,
    MainNode->getRotation().Z
  ));
}

//! Turns the model along the Y axis
void CStaticModel::turnY(f32 speed)
{
  MainNode->setRotation(core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y + (speed * NEngine::CGame::getSpeedFactor()),
    MainNode->getRotation().Z
  ));
}

//! Turns the model along the Z axis
void CStaticModel::turnZ(f32 speed)
{
  MainNode->setRotation(core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y,
    MainNode->getRotation().Z + (speed * NEngine::CGame::getSpeedFactor())
  ));
}

//! Moves the model along the X axis
void CStaticModel::moveX(f32 speed)
{
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X + (speed * NEngine::CGame::getSpeedFactor()),
    MainNode->getPosition().Y,
    MainNode->getPosition().Z
  ));
}

//! Moves the model along the Y axis
void CStaticModel::moveY(f32 speed)
{
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y + (speed * NEngine::CGame::getSpeedFactor()),
    MainNode->getPosition().Z
  ));
}

//! Moves the model along the Z axis
void CStaticModel::moveZ(f32 speed)
{
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y,
    MainNode->getPosition().Z + (speed * NEngine::CGame::getSpeedFactor())
  ));
}

//! Generates the geometry complex collision mask for this model
void CStaticModel::loadMeshCollision()
{
  bool optimize = true;

  if (MainNode) {
    NewtonCollision* treeCollision = NewtonCreateTreeCollision(NEngine::CGame::getNewtonWorld(), 0);
    NewtonTreeCollisionBeginBuild(treeCollision);

    // On récupère les meshBuffer, à chaque meshBuffer, on ajoute les informations à la collision
    for (u32 i = 0; i < MainMesh->getMeshBufferCount(); i++) {
      scene::IMeshBuffer* mb = MainMesh->getMeshBuffer(i);
      addMeshToTreeCollision(mb->getVertexType(), mb, treeCollision, MainNode->getScale());
    }

    if (optimize) {
      NewtonTreeCollisionEndBuild(treeCollision, 1);
    } else {
      NewtonTreeCollisionEndBuild(treeCollision, 0);
    }

    // Création du Body Newton
    f32 newtMatrix[16] = {};
    MainBody = NewtonCreateBody(NEngine::CGame::getNewtonWorld(), treeCollision, newtMatrix);
    MainNode->updateAbsolutePosition();

    core::matrix4 irrMatrix = MainNode->getRelativeTransformation();
    NewtonBodySetMatrix(MainBody, irrMatrix.pointer());
    NewtonReleaseCollision(NEngine::CGame::getNewtonWorld(), treeCollision);
  }
}

//! Generates a collision mask for an Irrlicht mesh buffer (needed for loadMeshCollision)
void CStaticModel::addMeshToTreeCollision(video::E_VERTEX_TYPE vertexType, scene::IMeshBuffer* meshBuffer,
  NewtonCollision* treeCollision, core::vector3df scale)
{
  // Tableau qui peut contenir 3 vertices servant à ajouter une face à la collision
  f32 vArray[9];
  bool skipAddMesh = false;
  video::S3DVertex* vertices;

  // On récupère les vertices du mesh dans un tableau
  switch (vertexType) {
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
      skipAddMesh = true;
      break;
  }

  if (!skipAddMesh) {
    // On récupère tous les indices du mesh dans un tableau
    u16* indices = meshBuffer->getIndices();

    // Les indices permettent de récupérer un vertex précis dans l'ordre ou il a été créé
    // On récupère les vertices par groupe de 3 pour former une face (polygone)
    for (u32 j = 0; j < meshBuffer->getIndexCount(); j += 3) {
      // On récupère les indices des trois vertices courants
      s32 v1i = indices[j];
      s32 v2i = indices[j + 1];
      s32 v3i = indices[j + 2];

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
      NewtonTreeCollisionAddFace(treeCollision, 3, vArray, sizeof(f32) * 3, 1);
    }
  }
}

//! Erases the collision mask
void CStaticModel::clearMeshCollision()
{
  if (MainBody) {
    NewtonDestroyBody(NEngine::CGame::getNewtonWorld(), MainBody);
  }
}

//! Changes the shadow mode between cast, receive, both or none
void CStaticModel::setShadowMode(NShader::EShadowMode mode)
{

}

//! Destructor
CStaticModel::~CStaticModel()
{
  if (MainNode) {
    MainNode->remove();
    MainNode = NULL;
  }
}

}
}
