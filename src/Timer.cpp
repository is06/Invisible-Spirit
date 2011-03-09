/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

/**
 *
 */
Timer::Timer(f32 end, Callback function) {
  running = true;
  reinit(end, function);
}

/**
 *
 */
void Timer::update() {
  if(running) {
    currentTime += (1.0f / Game::getFramerate());
    if(currentTime >= endTime) {
      stop();
      // Appel du callback
      endCallback();
    }
  }
}

/**
 *
 */
void Timer::start() {
  running = true;
}

/**
 *
 */
void Timer::stop() {
  running = false;
}

/**
 *
 */
void Timer::reset() {
  currentTime = 0.0f;
}

/**
 *
 */
void Timer::reinit(f32 end, Callback function) {
  currentTime = 0.0f;
  endTime = end;
  endCallback = function;
  start();
}

/**
 *
 */
void Timer::setTime(f32 val) {
  currentTime = val;
}

/**
 *
 */
f32 Timer::getTime() {
  return currentTime;
}

/**
 *
 */
Timer::~Timer() {
  endCallback = NULL;
}
