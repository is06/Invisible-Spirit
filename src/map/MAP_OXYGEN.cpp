/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/LevelMesh.h"

#include "../../include/map/MAP_OXYGEN.h"

namespace is06
{
namespace map
{

/**
 * Constructeur de la map en cours, définition du mesh du décor, création du node et de
 * son masque de collision
 */
MAP_OXYGEN::MAP_OXYGEN() : scene::CSceneGameplay()
{
  Level->loadMesh("resource/mesh/level/oxygen.obj");
  Level->createNode(irr::core::vector3df(0, 0, 0));
  Level->loadMeshCollision();
}

/**
 * Fonction de test des événements spécifiques à cette map
 */
void MAP_OXYGEN::events()
{
  scene::CSceneGameplay::events();
}

/**
 * Detruit les objets définis dans le constructeur
 */
MAP_OXYGEN::~MAP_OXYGEN()
{

}

}
}
