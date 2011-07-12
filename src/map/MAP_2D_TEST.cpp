/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Keyboard.h"
#include "../../include/3d/LevelMesh.h"
#include "../../include/3d/Ayron.h"
#include "../../include/gui/BarCounter.h"
#include "../../include/gui/GameplayInterface.h"

using namespace std;
using namespace irr;

/**
 * Constructeur de la map en cours, définition du mesh du décor, création du node et de
 * son masque de collision
 */
MAP_2D_TEST::MAP_2D_TEST() : SceneGameplay() {
  level->loadMesh("resource/mesh/level/alphazone.obj");
  level->createNode(core::vector3df(0, 0, 0));
  level->loadMeshCollision();

  gpInterface->hide();
  ayron->hide();
  level->hide();

  bar = new BarCounter(100, 0, 100, 0, 0, 150, 10, BAR_STYLE_LIFE);
}

/**
 * Fonction de test des événements spécifiques à cette map
 */
void MAP_2D_TEST::events() { SceneGameplay::events();
  bar->render();

  if(keyboard->pressed(KEY_KEY_L, EVENT_ONCE)) {
    bar->subValue(30);
  }
  if(keyboard->pressed(KEY_KEY_G, EVENT_ONCE)) {
    bar->addValue(50);
  }
}

void MAP_2D_TEST::postRender() { SceneGameplay::postRender();

}

/**
 * Detruit les objets définis dans le constructeur
 */
MAP_2D_TEST::~MAP_2D_TEST() {
  level->clearMeshCollision();
  delete bar;
}

