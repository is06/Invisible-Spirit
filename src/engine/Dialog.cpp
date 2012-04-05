/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/engine/Dialog.h"

Dialog::Dialog()
{

}

Dialog::Dialog(const string& identifier)
{
  currentIdentifier = identifier;
  currentNumber = 0;
}

void Dialog::addMessage(const string& text)
{
  messageList[currentNumber] = text;
  currentNumber++;
}

void Dialog::setIdentifier(const string& name)
{
  currentIdentifier = name;
}

const string& Dialog::getIdentifier() const
{
  return currentIdentifier;
}

string Dialog::getMessage(u16 index)
{
  return messageList[index];
}

Dialog::~Dialog()
{

}
