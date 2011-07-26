/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/LevelMesh.h"
#include "../../include/sound/Speaker.h"
#include "../../include/3d/OmniLight.h"

#include "../../include/map/MAP_ALPHA_ZONE.h"

using namespace std;
using namespace irr;

/**
 * Constructeur de la map en cours, définition du mesh du décor, création du node et de
 * son masque de collision
 */
MAP_ALPHA_ZONE::MAP_ALPHA_ZONE() : SceneGameplay() {
  level->loadMesh("resource/mesh/level/alphazone.obj");
  level->createNode(core::vector3df(0, 0, 0));
  level->loadMeshCollision();

  spk = new Speaker(STREAM_TEST, core::vector3df(0,1,0), "hola", 10);
  lt = new OmniLight();
}

/**
 * Fonction de test des événements spécifiques à cette map
 */
void MAP_ALPHA_ZONE::events() { SceneGameplay::events();
  spk->render();
}

void MAP_ALPHA_ZONE::postRender() { SceneGameplay::postRender();

}

/**
 * Detruit les objets définis dans le constructeur
 */
MAP_ALPHA_ZONE::~MAP_ALPHA_ZONE() {
  level->clearMeshCollision();
  delete spk;
  delete lt;
}
