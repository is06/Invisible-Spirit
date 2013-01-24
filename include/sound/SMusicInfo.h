/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MUSIC_INFO_H__
#define __IS06_MUSIC_INFO_H__

#include "SMusicSequenceInfo.h"

namespace is06
{
namespace NSound
{

//! Structure for music sequence information
struct SMusicInfo
{
  map<u16, SMusicSequenceInfo> SequenceInfo;
};

}
}

#endif
