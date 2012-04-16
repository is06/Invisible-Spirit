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
namespace nEngine
{

//! Main exception class
class CEngineException : public exception
{
  public:
    CEngineException(u32 code = 0, const string& message = "", s32 level = 3) throw()
    {
      Code = code;
      Message = message;
      Level = level;
    }

    virtual const char* what() const throw()
    {
      return Message.c_str();
    }

    u32 getCode() const throw()
    {
      return Code;
    }

    u32 getLevel() const throw()
    {
      return Level;
    }

    virtual ~CEngineException() throw()
    {

    }

  private:
    u32 Code;
    string Message;
    s32 Level;
};

}
}

#endif
