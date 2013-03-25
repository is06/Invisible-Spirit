/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/Hud/Counter/CBar.h"
#include "../../../include/Hud/CPicture.h"

namespace is06 { namespace NHud { namespace NCounter {

CBar::CBar(s32 init, s32 min, s32 max, f32 x, f32 y, f32 w, f32 h, EBarStyle style) : CCounter(init, min, max)
{
  string texturePath = "resource/hud/bar/";
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
    case EBS_LIFE:
      texturePath += "life.bmp";
      Sub = new CPicture(x, y, w, h, "resource/hud/bar/life_gain.bmp", false);
      Sub->loadSecondTexture("resource/hud/bar/life_loss.bmp");
      break;
    default:
      texturePath += "default.bmp";
      break;
  }

  Bar = new CPicture(x, y, w, h, texturePath, false);
}

void CBar::render()
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
          BehindValue -= (DecreaseFactor * NEngine::CGame::getSpeedFactor());
        }
      } else {
        // Gain de vie
        BehindValue += (DecreaseFactor * NEngine::CGame::getSpeedFactor());
      }
    } else {
      // Evolution du timer
      DecreaseTimer += 100.0f * NEngine::CGame::getSpeedFactor();
    }
    if ((s32)BehindValue <= CurrentValue) {
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

void CBar::setPosition(f32 x, f32 y)
{
  InitX = x;
  InitY = y;
}

void CBar::setX(f32 value)
{
  InitX = value;
}

void CBar::setY(f32 value)
{
  InitY = value;
}

void CBar::hide()
{
  Bar->hide();
  if (Sub) {
    Sub->hide();
  }
}

void CBar::show()
{
  Bar->show();
  if (Sub) {
    Sub->show();
  }
}

void CBar::setOpacity(f32 value)
{
  Bar->setOpacity(value);
  if (Sub) {
    Sub->setOpacity(value);
  }
}

void CBar::addOpacity(f32 value)
{
  Bar->addOpacity(value);
  if (Sub) {
    Sub->addOpacity(value);
  }
}

void CBar::subOpacity(f32 value)
{
  Bar->subOpacity(value);
  if (Sub) {
    Sub->subOpacity(value);
  }
}

f32 CBar::getOpacity()
{
  return Bar->getOpacity();
}

CBar::~CBar()
{
  delete Bar;
  if (Sub) {
    delete Sub;
  }
}

}}}
