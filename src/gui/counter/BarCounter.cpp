/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/counter/BarCounter.h"
#include "../../../include/gui/Picture.h"
#include "../../../include/Game.h"

namespace is06
{
namespace hud
{

CBarCounter::CBarCounter(irr::s32 init, irr::s32 min, irr::s32 max, irr::f32 x, irr::f32 y, irr::f32 w, irr::f32 h, EBarStyle style) : CCounter(init, min, max)
{
  std::string texturePath = "resource/hud/bar/";
  Sub = NULL;
  OldValue = CurrentValue + 1;
  BehindValue = CurrentValue;
  DecreaseFactor = 200.0f;
  DecreaseTimer = 0.0f;
  InitWidth = w;
  InitX = x;
  InitY = y;
  Animate = false;
  Decrease = false;

  switch (style) {
    case BAR_STYLE_LIFE:
      texturePath += "life.bmp";
      Sub = new CPicture(x, y, w, h, "resource/hud/bar/life_gain.bmp");
      Sub->loadSecondTexture("resource/hud/bar/life_loss.bmp");
      break;
    default:
      texturePath += "default.bmp";
      break;
  }

  Bar = new CPicture(x, y, w, h, texturePath);
}

void CBarCounter::render()
{
  if (OldValue != CurrentValue) {
    if (OldValue < CurrentValue) {
      Sub->changeTexture("resource/hud/bar/life_gain.bmp");
      Decrease = false;
    } else {
      Sub->changeTexture("resource/hud/bar/life_loss.bmp");
      Decrease = true;
    }
    OldValue = CurrentValue;

    if (Decrease) {
      Bar->setWidth((CurrentValue / 100.0f) * InitWidth);
      Bar->setX(InitX + (Bar->getWidth() / 2.0f));
    } else {
      Sub->setWidth((CurrentValue / 100.0f) * InitWidth);
      Sub->setX(InitX + (Bar->getWidth() / 2.0f));
    }

    if (Sub) {
      Animate = true;
      Sub->setX(InitX + (Sub->getWidth() / 2.0f));
    }
  }
  if (Animate) {
    if (DecreaseTimer >= 100.0f) {
      if (Decrease) {
        // Perte de vie
        if (BehindValue < (CurrentValue + (0.3f * (MaxValue - CurrentValue)))) {
          DecreaseFactor = ((BehindValue - CurrentValue) / (MaxValue - CurrentValue)) * 500.0f;
        }
        if (DecreaseFactor > 0.0f) {
          BehindValue -= (DecreaseFactor * engine::CGame::getSpeedFactor());
        }
      } else {
        // Gain de vie
        BehindValue += (DecreaseFactor * engine::CGame::getSpeedFactor());
      }
    } else {
      // Evolution du timer
      DecreaseTimer += 100.0f * engine::CGame::getSpeedFactor();
    }
    if ((irr::s32)BehindValue <= CurrentValue) {
      // Sub arrivée au niveau du compteur
      BehindValue = CurrentValue;
      Animate = false;
      Decrease = false;
      DecreaseFactor = 200.0f;
      DecreaseTimer = 0.0f;
    }
    if (Decrease) {
      Sub->setWidth((BehindValue / 100.0f) * InitWidth);
      Sub->setX(InitX + (Sub->getWidth() / 2.0f));
    }
  }

  Bar->setY(InitY);
  Sub->setY(InitY);

  if (Sub) {
    Sub->render();
  }
  Bar->render();
}

void CBarCounter::setPosition(irr::f32 x, irr::f32 y)
{
  InitX = x;
  InitY = y;
}

void CBarCounter::setX(irr::f32 value)
{
  InitX = value;
}

void CBarCounter::setY(irr::f32 value)
{
  InitY = value;
}

void CBarCounter::hide()
{
  Bar->hide();
  if (Sub) {
    Sub->hide();
  }
}

void CBarCounter::show()
{
  Bar->show();
  if (Sub) {
    Sub->show();
  }
}

void CBarCounter::setOpacity(irr::u8 value)
{
  Bar->setOpacity(value);
  if (Sub) {
    Sub->setOpacity(value);
  }
}

CBarCounter::~CBarCounter()
{
  delete Bar;
  if (Sub) {
    delete Sub;
  }
}

}
}
