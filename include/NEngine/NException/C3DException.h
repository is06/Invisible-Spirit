/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_EXCEPTION_3D_EXCEPTION_H__
#define __IS06_ENGINE_EXCEPTION_3D_EXCEPTION_H__

namespace is06 { namespace NEngine { namespace NException {

//! 3D exception class
class C3DException : public exception
{
public:
  C3DException(const string& message = "") throw()
  {
    Message = message;
  }

  virtual const char* what() const throw()
  {
    return Message.c_str();
  }

  virtual ~C3DException() throw()
  {

  }

private:
  string Message;
};

}}}

#endif
