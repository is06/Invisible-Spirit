/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NPart/CHudPart.h"
#include "../../../include/NHud/NPart/CCommands.h"

namespace is06 { namespace NHud { namespace NPart {

CHudPart::CHudPart() : NCore::CHudEntity()
{
    Buttons = new NPart::CCommands();
}

void CHudPart::render()
{
    NCore::CHudEntity::render();
    Buttons->render();
}

void CHudPart::hide()
{
    Buttons->hide();
}

void CHudPart::show()
{
    Buttons->show();
}

void CHudPart::setOpacity(f32 value)
{
    Opacity = value;
    Buttons->setOpacity(Buttons->getOpacity() * Opacity);
}

void CHudPart::addOpacity(f32 value)
{
    Opacity += value;
    Buttons->setOpacity(Buttons->getOpacity() * Opacity);
}

void CHudPart::subOpacity(f32 value)
{
    Opacity -= value;
    Buttons->setOpacity(Buttons->getOpacity() * Opacity);
}

f32 CHudPart::getOpacity()
{
    return Opacity;
}

CHudPart::~CHudPart()
{
    delete Buttons;
}

}}}
