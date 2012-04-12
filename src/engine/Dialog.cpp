/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/engine/Dialog.h"

namespace is06
{
namespace engine
{

CDialog::CDialog()
{

}

CDialog::CDialog(const std::string& identifier)
{
  CurrentIdentifier = identifier;
  CurrentNumber = 0;
}

void CDialog::addMessage(const std::string& text)
{
  MessageList[CurrentNumber] = text;
  CurrentNumber++;
}

void CDialog::setIdentifier(const std::string& name)
{
  CurrentIdentifier = name;
}

const std::string& CDialog::getIdentifier() const
{
  return CurrentIdentifier;
}

irr::u16 CDialog::getMessageCount()
{
  return MessageList.size();
}

std::string CDialog::getMessage(irr::u16 index)
{
  return MessageList[index];
}

CDialog::~CDialog()
{

}

}
}
