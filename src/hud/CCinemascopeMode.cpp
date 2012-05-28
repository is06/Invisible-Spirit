/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/hud/CCinemascopeMode.h"
#include "../../include/hud/CQuad.h"

using namespace irr;

namespace is06
{
namespace nHud
{

CCinemascopeMode::CCinemascopeMode() : CHud()
{
  SlideSpeed = 0.0f;
  SlidingIn = false;
  SlidingOut = false;

  FadeSpeed = 0.0f;
  FadeValue = 0.0f;
  FadingIn = false;
  FadingOut = false;

  Bars[0] = new CQuad(0, (nEngine::CGame::ScreenPos.Top + 44), 1280, 88, video::SColor(255, 0, 0, 0));
  Bars[1] = new CQuad(0, (nEngine::CGame::ScreenPos.Bottom - 44), 1280, 88, video::SColor(255, 0, 0, 0));
}

void CCinemascopeMode::render()
{

}

void CCinemascopeMode::render(f32 speedFactor)
{
  CHud::render();

  if (SlidingIn) {
    if (Bars[0]->getY() > (nEngine::CGame::ScreenPos.Top - 44)) {
      Bars[0]->subY(speedFactor * SlideSpeed);
      Bars[1]->addY(speedFactor * SlideSpeed);
    } else {
      SlidingIn = false;
    }
  } else if (SlidingOut) {
    if (Bars[0]->getY() < (nEngine::CGame::ScreenPos.Top + 44)) {
      Bars[0]->addY(speedFactor * SlideSpeed);
      Bars[1]->subY(speedFactor * SlideSpeed);
    } else {
      SlidingOut = false;
    }
  }

  if (FadingIn) {
    Bars[0]->setY(nEngine::CGame::ScreenPos.Top - 44);
    Bars[1]->setY(nEngine::CGame::ScreenPos.Bottom + 44);
    if (FadeValue < 255.0f) {
      FadeValue += (speedFactor * FadeSpeed);
    } else {
      FadeValue = 255.0f;
      FadingIn = false;
    }
    cout << FadeValue << endl;
    Bars[0]->setOpacity((u8)FadeValue);
    Bars[1]->setOpacity((u8)FadeValue);
  } else if (FadingOut) {
    if (FadeValue > 0.0f) {
      FadeValue -= (speedFactor * FadeSpeed);
    } else {
      FadeValue = 0.0f;
      FadingOut = false;
      Bars[0]->setY(nEngine::CGame::ScreenPos.Top + 44);
      Bars[1]->setY(nEngine::CGame::ScreenPos.Bottom - 44);
    }
    Bars[0]->setOpacity((u8)FadeValue);
    Bars[1]->setOpacity((u8)FadeValue);
  }

  Bars[0]->render();
  Bars[1]->render();
}

void CCinemascopeMode::show()
{
  Bars[0]->show();
  Bars[1]->show();
}

void CCinemascopeMode::hide()
{
  Bars[0]->hide();
  Bars[1]->hide();
}

void CCinemascopeMode::setOpacity(u8 value)
{
  Bars[0]->setOpacity(value);
  Bars[1]->setOpacity(value);
}

void CCinemascopeMode::fadeIn(f32 speed)
{
  FadeSpeed = speed;
  FadingIn = true;
}

void CCinemascopeMode::fadeOut(f32 speed)
{
  FadeSpeed = speed;
  FadingOut = true;
}

void CCinemascopeMode::slideIn(f32 speed)
{
  SlideSpeed = speed;
  SlidingIn = true;
}

void CCinemascopeMode::slideOut(f32 speed)
{
  SlideSpeed = speed;
  SlidingOut = true;
}

CCinemascopeMode::~CCinemascopeMode()
{
  delete Bars[0];
  delete Bars[1];
}

}
}
