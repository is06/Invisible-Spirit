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
  behindValue = currentValue;
  decreaseFactor = 200.0f;
  decreaseTimer = 0.0f;
  initWidth = w;
  initX = x;
  initY = y;
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

    if(decrease) {
      bar->setWidth((currentValue / 100.0f) * initWidth);
      bar->setX(initX + (bar->getWidth() / 2.0f));
    } else {
      sub->setWidth((currentValue / 100.0f) * initWidth);
      sub->setX(initX + (bar->getWidth() / 2.0f));
    }

    if(sub) {
      animate = true;
      sub->setX(initX + (sub->getWidth() / 2.0f));
    }
  }
  if(animate) {
    if(decreaseTimer >= 100.0f) {
      if(decrease) {
        // Perte de vie
        if(behindValue < (currentValue + (0.3f * (maxValue - currentValue)))) {
          decreaseFactor = ((behindValue - currentValue) / (maxValue - currentValue)) * 500.0f;
        }
        if(decreaseFactor > 0.0f) {
          behindValue -= (decreaseFactor * Game::getSpeedFactor());
        }
      } else {
        // Gain de vie
        behindValue += (decreaseFactor * Game::getSpeedFactor());
      }
    } else {
      // Evolution du timer
      decreaseTimer += 100.0f * Game::getSpeedFactor();
    }
    if((s32)behindValue <= currentValue) {
      // Sub arrivée au niveau du compteur
      behindValue = currentValue;
      animate = false;
      decrease = false;
      decreaseFactor = 200.0f;
      decreaseTimer = 0.0f;
    }
    if(decrease) {
      sub->setWidth((behindValue / 100.0f) * initWidth);
      sub->setX(initX + (sub->getWidth() / 2.0f));
    }
  }

  bar->setY(initY);
  sub->setY(initY);

  if(sub) {
    sub->render();
  }
  bar->render();
}

void BarCounter::setPosition(f32 x, f32 y) {
  initX = x;
  initY = y;
}

void BarCounter::setX(f32 value) {
  initX = value;
}

void BarCounter::setY(f32 value) {
  initY = value;
}

BarCounter::~BarCounter() {
  delete bar;
  if(sub) {
    delete sub;
  }
}
