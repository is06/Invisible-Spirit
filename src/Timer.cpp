/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Timer.h"
#include "../include/Game.h"

namespace is06
{
namespace engine
{

/**
 * @param f32 end duration
 * @param VoidCallback method to call
 * @param s32 loopLimit number of calls (-1 = infinite)
 */
CTimer::CTimer(f32 end, TVoidCallback callback, s32 loopLimit)
{
  Running = true;
  reinit(end, callback, loopLimit);
}

/**
 *
 */
void CTimer::update()
{
  if (Running && CurrentLoop < CurrentLoopLimit) {
    CurrentTime += (CGame::getSpeedFactor());
    if (CurrentTime >= EndTime) {
      bool called = true;
      // Appel du callback
      EndCall();
      if (called) {
        if (CurrentLoopLimit > 0) {
          CurrentLoop++;
          CurrentTime = 0.0f;
        } else if (CurrentLoopLimit == -1) {
          CurrentTime = 0.0f;
        } else {
          stop();
        }
      }
    }
  }
}

/**
 *
 */
void CTimer::start()
{
  Running = true;
}

/**
 *
 */
void CTimer::stop()
{
  Running = false;
}

/**
 *
 */
void CTimer::reset()
{
  CurrentTime = 0.0f;
}

/**
 * @param f32 end duration
 * @param VoidCallback method to call
 * @param s32 loopLimit number of calls (-1 = infinite)
 */
void CTimer::reinit(f32 end, TVoidCallback callback, s32 loopLimit)
{
  EndCall = callback;
  CurrentTime = 0.0f;
  EndTime = end;
  CurrentLoop = 0;
  CurrentLoopLimit = loopLimit;
  start();
}

/**
 *
 */
void CTimer::setTime(f32 val)
{
  CurrentTime = val;
}

/**
 *
 */
f32 CTimer::getTime()
{
  return CurrentTime;
}

}
}
