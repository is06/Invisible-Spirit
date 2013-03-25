/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Hud/CWindow.h"
#include "../../include/Hud/CPicture.h"

namespace is06 { namespace NHud { namespace NWindow {

CWindow::CWindow(f32 x, f32 y, f32 w, f32 h, f32 borderWidth, EWindowStyle style) : CHud()
{
  Pos = core::position2df(x, y);
  Size = core::dimension2df(w, h);

  switch (style) {
    case EWS_STD: applyStyleStd(x, y, w, h, borderWidth); break;
    default: applyStyleNone(); break;
  }
}

void CWindow::applyStyleStd(f32 x, f32 y, f32 w, f32 h, f32 borderWidth)
{
  string texturePath = "resource/hud/window/window1.bmp";

  f32 sideW = w - borderWidth;
  f32 sideH = h - borderWidth;
  f32 sideWMin = x + (w / 2) * -1;
  f32 sideWMax = x + (w / 2);
  f32 sideHMin = y + (h / 2) * -1;
  f32 sideHMax = y + (h / 2);

  CornerTL = new CPicture(sideWMin, sideHMin, borderWidth, borderWidth, texturePath);
  CornerTR = new CPicture(sideWMax, sideHMin, borderWidth, borderWidth, texturePath);
  CornerBL = new CPicture(sideWMin, sideHMax, borderWidth, borderWidth, texturePath);
  CornerBR = new CPicture(sideWMax, sideHMax, borderWidth, borderWidth, texturePath);

  CornerBL->setTextureOffset(core::vector2df(0.0f, 0.0f), core::vector2df(0.0625f, 0.0625f));
  CornerBR->setTextureOffset(core::vector2df(0.9375f, 0.0f), core::vector2df(1.0f, 0.0625f));
  CornerTL->setTextureOffset(core::vector2df(0.0f, 0.9375f), core::vector2df(0.0625f, 1.0f));
  CornerTR->setTextureOffset(core::vector2df(0.9375f, 0.9375f), core::vector2df(1.0f, 1.0f));

  SideTop = new CPicture(x, sideHMax, sideW, borderWidth, texturePath);
  SideLeft = new CPicture(sideWMin, y, borderWidth, sideH, texturePath);
  SideRight = new CPicture(sideWMax, y, borderWidth, sideH, texturePath);
  SideBottom = new CPicture(x, sideHMin, sideW, borderWidth, texturePath);

  SideTop->setTextureOffset(core::vector2df(0.0625f, 0.0f), core::vector2df(0.9375f, 0.0625f));
  SideLeft->setTextureOffset(core::vector2df(0.0f, 0.0625f), core::vector2df(0.0625f, 0.9375f));
  SideRight->setTextureOffset(core::vector2df(0.9375f, 0.0625f), core::vector2df(1.0f, 0.9375f));
  SideBottom->setTextureOffset(core::vector2df(0.0625f, 0.9375f), core::vector2df(0.9375f, 1.0f));

  Center = new CPicture(x, y, sideW, sideH, texturePath);
  Center->setTextureOffset(core::vector2df(0.0625f, 0.0625f), core::vector2df(0.9375f, 0.9375f));
}

void CWindow::applyStyleNone()
{
  Center = NULL;
}

void CWindow::render()
{
  CHud::render();
  if (Center) {
    CornerTL->render();
    CornerTR->render();
    CornerBL->render();
    CornerBR->render();
    SideTop->render();
    SideLeft->render();
    SideRight->render();
    SideBottom->render();
    Center->render();
  }
}

void CWindow::show()
{
  CornerTL->show();
  CornerTR->show();
  CornerBL->show();
  CornerBR->show();
  SideTop->show();
  SideLeft->show();
  SideRight->show();
  SideBottom->show();
  Center->show();
}

void CWindow::hide()
{
  CornerTL->hide();
  CornerTR->hide();
  CornerBL->hide();
  CornerBR->hide();
  SideTop->hide();
  SideLeft->hide();
  SideRight->hide();
  SideBottom->hide();
  Center->hide();
}

void CWindow::setOpacity(f32 value)
{
  CornerTL->setOpacity(value);
  CornerTR->setOpacity(value);
  CornerBL->setOpacity(value);
  CornerBR->setOpacity(value);
  SideTop->setOpacity(value);
  SideLeft->setOpacity(value);
  SideRight->setOpacity(value);
  SideBottom->setOpacity(value);
  Center->setOpacity(value);
}

void CWindow::addOpacity(f32 value)
{
  CornerTL->addOpacity(value);
  CornerTR->addOpacity(value);
  CornerBL->addOpacity(value);
  CornerBR->addOpacity(value);
  SideTop->addOpacity(value);
  SideLeft->addOpacity(value);
  SideRight->addOpacity(value);
  SideBottom->addOpacity(value);
  Center->addOpacity(value);
}

void CWindow::subOpacity(f32 value)
{
  CornerTL->subOpacity(value);
  CornerTR->subOpacity(value);
  CornerBL->subOpacity(value);
  CornerBR->subOpacity(value);
  SideTop->subOpacity(value);
  SideLeft->subOpacity(value);
  SideRight->subOpacity(value);
  SideBottom->subOpacity(value);
  Center->subOpacity(value);
}

f32 CWindow::getOpacity()
{
  return Center->getOpacity();
}

CWindow::~CWindow()
{
  if (Center) {
    delete CornerTL;
    delete CornerTR;
    delete CornerBL;
    delete CornerBR;
    delete SideTop;
    delete SideLeft;
    delete SideRight;
    delete SideBottom;
    delete Center;
  }
}

}}}
