/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/BarCounter.h"
#include "../../include/gui/Picture.h"
#include "../../include/Game.h"

using namespace std;
using namespace irr;

BarCounter::BarCounter(s32 init, s32 min, s32 max, f32 x, f32 y, f32 w, f32 h, BarStyle style) : Counter(init, min, max) {
  core::stringc texturePath = "resource/hud/bar/";
  sub = NULL;
  oldValue = currentValue + 1;
  subValue = currentValue;
  decreaseFactor = 200.0f;
  decreaseTimer = 0.0f;
  initWidth = w;
  initX = x;
  animate = false;
  decrease = false;

  switch(style) {
    case BAR_STYLE_LIFE:
      texturePath.append("life.bmp");
      sub = new Picture(x, y, w, h, "resource/hud/bar/life_gain.bmp");
      sub->loadSecondTexture("resource/hud/bar/life_loss.bmp");
    break;
    default:
      texturePath.append("default.bmp");
    break;
  }

  bar = new Picture(x, y, w, h, texturePath);
}

void BarCounter::render() {
  if(oldValue != currentValue) {
    if(oldValue < currentValue) {
      sub->changeTexture("resource/hud/bar/life_gain.bmp");
      decrease = false;
    } else {
      sub->changeTexture("resource/hud/bar/life_loss.bmp");
      decrease = true;
    }
    oldValue = currentValue;
    bar->setWidth((currentValue / 100.0f) * initWidth);
    bar->setX(initX + (bar->getWidth() / 2.0f));
    if(sub) {
      animate = true;
      sub->setX(initX + (sub->getWidth() / 2.0f));
    }
  }
  if(animate) {
    if(decreaseTimer >= 100.0f) {
      if(decrease) {
        // Perte de vie
        if(subValue < (currentValue + (0.3f * (maxValue - currentValue)))) {
          decreaseFactor = ((subValue - currentValue) / (maxValue - currentValue)) * 500.0f;
        }
        if(decreaseFactor > 0.0f) {
          subValue -= (decreaseFactor * Game::getSpeedFactor());
        }
      } else {
        // Gain de vie
        subValue += (decreaseFactor * Game::getSpeedFactor());
      }
    } else {
      // Evolution du timer
      decreaseTimer += 100.0f * Game::getSpeedFactor();
    }
    if((s32)subValue <= currentValue) {
      // Sub arrivée au niveau du compteur
      subValue = currentValue;
      animate = false;
      decrease = false;
      decreaseFactor = 200.0f;
      decreaseTimer = 0.0f;
    }
    sub->setWidth((subValue / 100.0f) * initWidth);
    sub->setX(initX + (sub->getWidth() / 2.0f));
  }

  if(sub) {
    sub->render();
  }

  bar->render();
}

BarCounter::~BarCounter() {
  delete bar;
  if(sub) {
    delete sub;
  }
}
