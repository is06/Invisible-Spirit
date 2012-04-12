/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Window.h"
#include "../../include/gui/Picture.h"

namespace is06
{
namespace hud
{

CWindow::CWindow(irr::f32 x, irr::f32 y, irr::f32 w, irr::f32 h, irr::f32 borderWidth, EWindowStyle style) : CHud()
{
  Pos = irr::core::position2df(x, y);
  Size = irr::core::dimension2df(w, h);

  switch (style) {
    case WIN_STYLE_STD: applyStyleStd(x, y, w, h, borderWidth); break;
    default: applyStyleNone(); break;
  }
}

/**
 *
 */
void CWindow::applyStyleStd(irr::f32 x, irr::f32 y, irr::f32 w, irr::f32 h, irr::f32 borderWidth)
{
  std::string texturePath = "resource/hud/window/window1.bmp";

  irr::f32 sideW = w - borderWidth;
  irr::f32 sideH = h - borderWidth;
  irr::f32 sideWMin = x + (w / 2) * -1;
  irr::f32 sideWMax = x + (w / 2);
  irr::f32 sideHMin = y + (h / 2) * -1;
  irr::f32 sideHMax = y + (h / 2);

  CornerTL = new CPicture(sideWMin, sideHMin, borderWidth, borderWidth, texturePath);
  CornerTR = new CPicture(sideWMax, sideHMin, borderWidth, borderWidth, texturePath);
  CornerBL = new CPicture(sideWMin, sideHMax, borderWidth, borderWidth, texturePath);
  CornerBR = new CPicture(sideWMax, sideHMax, borderWidth, borderWidth, texturePath);

  CornerBL->setTextureOffset(irr::core::vector2df(0.0f, 0.0f), irr::core::vector2df(0.0625f, 0.0625f));
  CornerBR->setTextureOffset(irr::core::vector2df(0.9375f, 0.0f), irr::core::vector2df(1.0f, 0.0625f));
  CornerTL->setTextureOffset(irr::core::vector2df(0.0f, 0.9375f), irr::core::vector2df(0.0625f, 1.0f));
  CornerTR->setTextureOffset(irr::core::vector2df(0.9375f, 0.9375f), irr::core::vector2df(1.0f, 1.0f));

  SideTop = new CPicture(x, sideHMax, sideW, borderWidth, texturePath);
  SideLeft = new CPicture(sideWMin, y, borderWidth, sideH, texturePath);
  SideRight = new CPicture(sideWMax, y, borderWidth, sideH, texturePath);
  SideBottom = new CPicture(x, sideHMin, sideW, borderWidth, texturePath);

  SideTop->setTextureOffset(irr::core::vector2df(0.0625f, 0.0f), irr::core::vector2df(0.9375f, 0.0625f));
  SideLeft->setTextureOffset(irr::core::vector2df(0.0f, 0.0625f), irr::core::vector2df(0.0625f, 0.9375f));
  SideRight->setTextureOffset(irr::core::vector2df(0.9375f, 0.0625f), irr::core::vector2df(1.0f, 0.9375f));
  SideBottom->setTextureOffset(irr::core::vector2df(0.0625f, 0.9375f), irr::core::vector2df(0.9375f, 1.0f));

  Center = new CPicture(x, y, sideW, sideH, texturePath);
  Center->setTextureOffset(irr::core::vector2df(0.0625f, 0.0625f), irr::core::vector2df(0.9375f, 0.9375f));
}

/**
 *
 */
void CWindow::applyStyleNone()
{
  Center = NULL;
}

/**
 *
 */
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

void CWindow::setOpacity(irr::u8 value)
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

/**
 *
 */
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

}
}
