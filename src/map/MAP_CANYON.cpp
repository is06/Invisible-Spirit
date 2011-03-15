/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"

using namespace std;
using namespace irr;

/**
 * Constructeur de la map en cours, définition du mesh du décor, création du node et de
 * son masque de collision
 */
MAP_CANYON::MAP_CANYON() : SceneGameplay() {
  level->loadMesh("resource/mesh/level/test2.obj");
  level->createNode(core::vector3df(0, 0, 0));
  level->loadMeshCollision();

  translatedText = new Translation("MAP_CANYON.txt");

  message = new Text(translatedText->getTranslation("test"), Game::screenPos.left + 10, Game::screenPos.top - 10, FONT_STD_REGULAR, 1.0f);
}

/**
 * Fonction de test des événements spécifiques à cette map
 */
void MAP_CANYON::events() { SceneGameplay::events();

}

void MAP_CANYON::postRender() { SceneGameplay::postRender();
  message->render();
}

/**
 * Detruit les objets définis dans le constructeur
 */
MAP_CANYON::~MAP_CANYON() {
  delete translatedText;
  //delete message;
}
