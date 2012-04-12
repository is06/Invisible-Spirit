/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Game.h"
#include "../include/EngineException.h"

#ifdef _IRR_WINDOWS_
#include <windows.h>
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main()
#endif
{
  try {
    is06::engine::CGame::init();
    is06::engine::CGame::run();
    is06::engine::CGame::finish();
  } catch(const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
#ifdef _IRR_WINDOWS_
    MessageBoxA(NULL, e.what(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#endif
    is06::engine::CGame::errorLog(e);
  }
  return 0;
}
