/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MUSIC_SEQUENCE_INFO_H__
#define __IS06_MUSIC_SEQUENCE_INFO_H__

namespace is06
{
namespace sound
{

//! Structure for sequence information like loop bounds
struct SMusicSequenceInfo
{
  u16 Number;
  bool Looped;
  u32 LoopStart;
  u32 LoopEnd;
  string FileName;
};

}
}

#endif
