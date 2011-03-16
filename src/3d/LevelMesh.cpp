/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

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
