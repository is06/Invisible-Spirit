/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

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

StaticModel::~StaticModel() {
  if(mainNode) {
    mainNode->remove();
  }
}
