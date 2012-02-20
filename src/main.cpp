/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Game.h"
#include "../include/EngineException.h"

int main()
{
  try {
    Game::init();
    Game::run();
    Game::finish();
  } catch(const std::exception& e) {
    cerr << "Exception: " << e.what() << endl;
    Game::errorLog(e);
  }
  return 0;
}
