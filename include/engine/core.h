/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CORE_H__
#define __IS06_CORE_H__

#include <irrlicht/irrlicht.h>
#include <newton/Newton.h>
#include <fmodex/fmod.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <cmath>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "classes.h"
#include "maps.h"

using namespace std;
using namespace irr;

namespace is06
{
  //! A string map indexed by u16
  typedef map<u16, string> TStringMap16;
  //! A string map indexed by u32
  typedef map<u32, string> TStringMap32;
  //! A string map indexed by strings
  typedef map<string, string> TStringMap;
  //! Boost void function callback type
  typedef boost::function<void()> TVoidCallback;

  namespace hud
  {
    //! A CDialog map indexed by strings
    typedef map<string, engine::CDialog> TDialogMap;
  }
}

#endif
