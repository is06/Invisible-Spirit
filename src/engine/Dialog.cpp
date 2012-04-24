/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Dialog.h"

namespace is06
{
namespace nEngine
{

//! Default constructor, does nothing
CDialog::CDialog()
{

}

//! Initializes the dialog by an identifier
/**
 *\param string identifier
 */
CDialog::CDialog(const string& identifier)
{
  CurrentIdentifier = identifier;
  CurrentNumber = 0;
}

//! Adds a message in the dialog object using a message string
/**
 * \param string text
 */
void CDialog::addMessage(const string& text)
{
  MessageList[CurrentNumber] = text;
  CurrentNumber++;
}

//! Changes the identifier of the dialog
/**
 * \param string name
 */
void CDialog::setIdentifier(const string& name)
{
  CurrentIdentifier = name;
}

//! Returns the current identifier of the dialog
/**
 * \return string
 */
const string& CDialog::getIdentifier() const
{
  return CurrentIdentifier;
}

//! Returns the number of message in the dialog
/**
 * \return u16
 */
u16 CDialog::getMessageCount()
{
  return MessageList.size();
}

//! Returns a specific message by passing its index number
/**
 * \param u16 index
 */
const string& CDialog::getMessage(u16 index)
{
  return MessageList[index];
}

//! Default destructor, does nothing
CDialog::~CDialog()
{

}

}
}
