/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DIALOG_H__
#define __IS06_DIALOG_H__

using namespace irr;
using namespace std;

namespace is06
{
namespace engine
{

//! A single dialog which can contains several messages
class CDialog
{
  public:
    CDialog();
    CDialog(const string& identifier);
    ~CDialog();

    void addMessage(const string& text);
    void setIdentifier(const string& name);

    const string& getMessage(u16 index);
    const string& getIdentifier() const;
    u16 getMessageCount();

  private:
    u16 CurrentNumber;
    string CurrentIdentifier;
    TStringMap16 MessageList;
};

}
}

#endif
