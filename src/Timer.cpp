/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Timer.h"
#include "../include/Game.h"

using namespace irr;
using namespace std;

/**
 * @param f32 end duration
 * @param VoidCallback method to call
 * @param s32 loopLimit number of calls (-1 = infinite)
 */
Timer::Timer(f32 end, VoidCallback callback, s32 loopLimit)
{
  running = true;
  reinit(end, callback, loopLimit);
}

/**
 *
 */
void Timer::update()
{
  if (running && currentLoop < currentLoopLimit) {
    currentTime += (Game::getSpeedFactor());
    if (currentTime >= endTime) {
      bool called = true;
      // Appel du callback
      endCall();
      if (called) {
        if (currentLoopLimit > 0) {
          currentLoop++;
          currentTime = 0.0f;
        } else if (currentLoopLimit == -1) {
          currentTime = 0.0f;
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
void Timer::start()
{
  running = true;
}

/**
 *
 */
void Timer::stop()
{
  running = false;
}

/**
 *
 */
void Timer::reset()
{
  currentTime = 0.0f;
}

/**
 * @param f32 end duration
 * @param VoidCallback method to call
 * @param s32 loopLimit number of calls (-1 = infinite)
 */
void Timer::reinit(f32 end, VoidCallback callback, s32 loopLimit)
{
  endCall = callback;
  currentTime = 0.0f;
  endTime = end;
  currentLoop = 0;
  currentLoopLimit = loopLimit;
  start();
}

/**
 *
 */
void Timer::setTime(f32 val)
{
  currentTime = val;
}

/**
 *
 */
f32 Timer::getTime()
{
  return currentTime;
}
