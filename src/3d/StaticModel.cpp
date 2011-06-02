/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

/**
 * Constructeur
 */
StaticModel::StaticModel() : ModelEntity() {
  mainNode = NULL;
}

/**
 * Fonction de mise à jour et de rendu de toutes les entités statiques présentes dans les scènes
 */
void StaticModel::render() { ModelEntity::render();

}

/**
 * Crée le node et l'ajoute au gestionnaire de scène Irrlicht en fonction de sa position
 * @param vector3df& initPosition référence vers une position initiale du node
 */
void StaticModel::createNode(const core::vector3df& initPosition) {
  mainNode = Game::getSceneManager()->addMeshSceneNode(mainMesh);
  mainNode->setMaterialFlag(video::EMF_LIGHTING, false);
  mainNode->setPosition(initPosition);
  //mainNode->setMaterialFlag(video::EMF_WIREFRAME, true);
}

void StaticModel::loadMeshCollision() {
  cout << "[NWT] StaticModel Loading mesh collision" << endl;

  bool optimize = true;

  if(mainNode) {
    NewtonCollision* treeCollision = NewtonCreateTreeCollision(Game::getNewtonWorld(), 0);

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
    mainBody = NewtonCreateBody(Game::getNewtonWorld(), treeCollision, newtMatrix);

    mainNode->updateAbsolutePosition();

    core::matrix4 irrMatrix = mainNode->getRelativeTransformation();

    NewtonBodySetMatrix(mainBody, irrMatrix.pointer());

    NewtonReleaseCollision(Game::getNewtonWorld(), treeCollision);
  }
}

/**
 * Ajoute un polygone à une collision Newton de type Mesh
 */
void StaticModel::addMeshToTreeCollision(video::E_VERTEX_TYPE vertexType, scene::IMeshBuffer* meshBuffer, NewtonCollision* treeCollision, core::vector3df scale) {
  cout << "[NWT] StaticModel mesh added to tree collision" << endl;
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
      cout << "[NWT] /!\\ StaticModel Vertex type not recognized! [" << meshBuffer << "]" << endl;
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

void StaticModel::clearMeshCollision() {
  cout << "[NWT] StaticModel NewtonBody deleted" << endl;
  NewtonDestroyBody(Game::getNewtonWorld(), mainBody);
}

StaticModel::~StaticModel() {
  if(mainNode) {
    mainNode->remove();
  }
}
