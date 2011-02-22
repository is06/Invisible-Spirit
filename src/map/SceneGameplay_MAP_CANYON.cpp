/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "../../include/core.h"

using namespace std;
using namespace irr;

/**
 * Constructeur de la map en cours, définition du mesh du décor, création du node et de
 * son masque de collision
 */
SceneGameplay_MAP_CANYON::SceneGameplay_MAP_CANYON() : SceneGameplay() {
  level->loadMesh("resource/mesh/level/test2.obj");
  level->createNode(core::vector3df(0, 0, 0));
  level->loadMeshCollision();
}

/**
 * Fonction de test des événements spécifiques à cette map
 */
void SceneGameplay_MAP_CANYON::events() { SceneGameplay::events();


}

/**
 * Detruit les objets définis dans le constructeur
 */
SceneGameplay_MAP_CANYON::~SceneGameplay_MAP_CANYON() {

}
