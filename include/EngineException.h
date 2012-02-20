/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_EXCEPTION_H__
#define __IS06_ENGINE_EXCEPTION_H__

class EngineException : public exception
{
  public:
    EngineException(u32 code = 0, const string& message = "", s32 level = 3) throw()
    {
      _code = code;
      _message = message;
      _level = level;
    }

    virtual const char* what() const throw()
    {
      return _message.c_str();
    }

    u32 getCode() const throw()
    {
      return _code;
    }

    u32 getLevel() const throw()
    {
      return _level;
    }

    virtual ~EngineException() throw()
    {

    }

  private:
    u32 _code;
    string _message;
    s32 _level;
};

#endif
