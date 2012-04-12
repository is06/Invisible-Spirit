/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/sound/Music.h"

namespace is06
{
namespace sound
{

CMusic::CMusic(const std::string& id)
{

}

void CMusic::addSequences(const std::map<irr::u16, SMusicSequenceInfo>& list)
{
  std::map<irr::u16, SMusicSequenceInfo>::const_iterator msIt;
  for (msIt = list.begin(); msIt != list.end(); msIt++) {
    Sequences[msIt->second.Number] = new CMusicSequence(msIt->second);
  }
}

/**
 * Plays all the music sequences
 */
void CMusic::playSequences(const std::map<irr::u16, SMusicSequenceInfo>& list)
{
  std::map<irr::u16, SMusicSequenceInfo>::const_iterator msIt;
  for (msIt = list.begin(); msIt != list.end(); msIt++) {
    Sequences[msIt->second.Number]->play();
  }
}

/**
 * Returns a reference to the sequences map
 */
std::map<irr::u16, CMusicSequence*>& CMusic::getSequenceMap()
{
  return Sequences;
}

/**
 * Returns a pointer to a sequence specified by number
 */
CMusicSequence* CMusic::getSequence(irr::u16 number)
{
  if (Sequences[number]) {
    return Sequences[number];
  } else {
    return NULL;
  }
}

/**
 * @todo Delete sequences
 */
CMusic::~CMusic()
{

}

}
}
