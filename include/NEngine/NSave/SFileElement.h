/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_SAVE_FILE_ELEMENT_H__
#define __IS06_ENGINE_SAVE_FILE_ELEMENT_H__

namespace is06 { namespace NEngine { namespace NSave {

//! Structure for a single save file element
struct SFileElement
{
  u32 Index;
  c8 Type;
  string Value;
};

}}}

#endif
