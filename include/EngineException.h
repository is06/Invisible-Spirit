/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_EXCEPTION_H__
#define __IS06_ENGINE_EXCEPTION_H__

namespace is06
{
namespace engine
{

class CEngineException : public std::exception
{
  public:
    CEngineException(irr::u32 code = 0, const std::string& message = "", irr::s32 level = 3) throw()
    {
      Code = code;
      Message = message;
      Level = level;
    }

    virtual const char* what() const throw()
    {
      return Message.c_str();
    }

    irr::u32 getCode() const throw()
    {
      return Code;
    }

    irr::u32 getLevel() const throw()
    {
      return Level;
    }

    virtual ~CEngineException() throw()
    {

    }

  private:
    irr::u32 Code;
    std::string Message;
    irr::s32 Level;
};

}
}

#endif
