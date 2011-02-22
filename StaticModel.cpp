/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "core.h"

using namespace irr;
using namespace std;

/**
 * Constructeur
 */
StaticModel::StaticModel() : ModelEntity() {

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
  //mainNode->setDebugDataVisible(scene::EDS_FULL);
  //mainNode->setMaterialFlag(video::EMF_WIREFRAME, true);
}

