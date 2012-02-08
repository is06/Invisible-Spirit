/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/ModelEntity.h"
#include "../../include/Game.h"

using namespace irr;
using namespace std;

/**
 * Initialise les objets liés à l'entité à savoir le mesh, le node, et l'état de mouvement Bullet
 */
ModelEntity::ModelEntity() : Entity()
{
  mainMesh = NULL;
  mainBody = NULL;
}

/**
 * Fonction de mise à jour et de rendu des entités Modèles 3D
 */
void ModelEntity::render()
{
  Entity::render();
}

/**
 * Charge un mesh dans l'entité
 * @param stringc& meshFilePath référence vers une chaine désignant le chemin du fichier mesh à charger
 */
void ModelEntity::loadMesh(const core::stringc& meshFilePath)
{
  mainMesh = Game::getSceneManager()->getMesh(meshFilePath);
}

scene::IMesh* ModelEntity::getMesh()
{
  return mainMesh;
}

NewtonBody* ModelEntity::getMainBody()
{
  return mainBody;
}

/**
 * Détruit les objets initialisés dans le constructeur
 */
ModelEntity::~ModelEntity()
{

}
