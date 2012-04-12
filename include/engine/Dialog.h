/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DIALOG_H__
#define __IS06_DIALOG_H__

namespace is06
{
namespace engine
{

class CDialog
{
  public:
    CDialog();
    CDialog(const std::string& identifier);
    ~CDialog();

    void addMessage(const std::string& text);
    void setIdentifier(const std::string& name);

    std::string getMessage(irr::u16 index);
    const std::string& getIdentifier() const;
    irr::u16 getMessageCount();

  private:
    irr::u16 CurrentNumber;
    std::string CurrentIdentifier;
    std::map<irr::u16, std::string> MessageList;
};

}
}

#endif
