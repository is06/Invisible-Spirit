/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NHud/NPart/CCinemascopeMode.h"
#include "../../../include/NHud/NPrimitive/CQuad.h"

using namespace irr;

namespace is06 { namespace NHud { namespace NPart {

CCinemascopeMode::CCinemascopeMode() : NCore::CHudEntity()
{
  SlideSpeed = 0.0f;
  SlidingIn = false;
  SlidingOut = false;

  FadeSpeed = 0.0f;
  FadeValue = 0.0f;
  FadingIn = false;
  FadingOut = false;

  Bars[0] = new NPrimitive::CQuad(0, (NEngine::NCore::CGame::ScreenPos.Hud.Top + 44), 1280, 88, video::SColor(255, 0, 0, 0));
  Bars[1] = new NPrimitive::CQuad(0, (NEngine::NCore::CGame::ScreenPos.Hud.Bottom - 44), 1280, 88, video::SColor(255, 0, 0, 0));
}

void CCinemascopeMode::render()
{

}

void CCinemascopeMode::render(f32 speedFactor)
{
  NCore::CHudEntity::render();

  if (SlidingIn) {
    if (Bars[0]->getY() > (NEngine::NCore::CGame::ScreenPos.Hud.Top - 44)) {
      Bars[0]->subY(speedFactor * SlideSpeed);
      Bars[1]->addY(speedFactor * SlideSpeed);
    } else {
      SlidingIn = false;
    }
  } else if (SlidingOut) {
    if (Bars[0]->getY() < (NEngine::NCore::CGame::ScreenPos.Hud.Top + 44)) {
      Bars[0]->addY(speedFactor * SlideSpeed);
      Bars[1]->subY(speedFactor * SlideSpeed);
    } else {
      SlidingOut = false;
    }
  }

  if (FadingIn) {
    Bars[0]->setY(NEngine::NCore::CGame::ScreenPos.Hud.Top - 44);
    Bars[1]->setY(NEngine::NCore::CGame::ScreenPos.Hud.Bottom + 44);
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
      Bars[0]->setY(NEngine::NCore::CGame::ScreenPos.Hud.Top + 44);
      Bars[1]->setY(NEngine::NCore::CGame::ScreenPos.Hud.Bottom - 44);
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

void CCinemascopeMode::setOpacity(f32 value)
{
  Opacity = value;
  Bars[0]->setOpacity(Bars[0]->getOpacity() * Opacity);
  Bars[1]->setOpacity(Bars[1]->getOpacity() * Opacity);
}

void CCinemascopeMode::addOpacity(f32 value)
{
  Opacity += value;
  Bars[0]->setOpacity(Bars[0]->getOpacity() * Opacity);
  Bars[1]->setOpacity(Bars[1]->getOpacity() * Opacity);
}

void CCinemascopeMode::subOpacity(f32 value)
{
  Opacity -= value;
  Bars[0]->setOpacity(Bars[0]->getOpacity() * Opacity);
  Bars[1]->setOpacity(Bars[1]->getOpacity() * Opacity);
}

f32 CCinemascopeMode::getOpacity()
{
  return Opacity;
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

}}}
