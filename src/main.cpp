/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"
#include "../include/NEngine/NCore/CGame.h"
#include "../include/NEngine/NException/CEngineException.h"

using namespace is06;
using namespace NEngine;
using namespace NCore;

#ifdef _IRR_WINDOWS_
#include <windows.h>
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main()
#endif
{
  try {
    CGame::init();
    CGame::run();
    CGame::finish();
  } catch(const exception& e) {
    cerr << "Exception: " << e.what() << endl;
#ifdef _IRR_WINDOWS_
    MessageBoxA(NULL, e.what(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#endif
    CGame::writeErrorToLogFile(e);
  }
  return 0;
}
