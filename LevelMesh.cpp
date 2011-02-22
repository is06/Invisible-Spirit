/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#include "core.h"

using namespace irr;

/**
 * Initialise le mesh Bullet qui permet de créer la forme complexe
 */
LevelMesh::LevelMesh() : StaticModel() {

}

/**
 * Fonction de mise à jour et de rendu de tous les levelMesh créés
 */
void LevelMesh::render() { StaticModel::render();

}

/**
 * Chargement du masque de collision du mesh Irrlicht dans le mesh Bullet
 */
void LevelMesh::loadCollisionMask() {

}

/**
 * Détruit les objets définis par le constructeur
 */
LevelMesh::~LevelMesh() {

}
