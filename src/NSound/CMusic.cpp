/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Sound/CMusic.h"

namespace is06 { namespace NSound {

//! Constructor
CMusic::CMusic(const string& id)
{

}

//! Adds a multi-layer music sequence
void CMusic::addSequences(const map<u16, SMusicSequenceInfo>& list)
{
  map<u16, SMusicSequenceInfo>::const_iterator msIt;
  for (msIt = list.begin(); msIt != list.end(); msIt++) {
    Sequences[msIt->second.Number] = new CMusicSequence(msIt->second);
  }
}

//! Plays all the music sequences
void CMusic::playSequences()
{
  map<u16, CMusicSequence*>::const_iterator msIt;
  for (msIt = Sequences.begin(); msIt != Sequences.end(); msIt++) {
    if (msIt->second) {
      msIt->second->play();
    }
  }
}

//! Stops all the music sequences
void CMusic::stopSequences()
{
  map<u16, CMusicSequence*>::const_iterator msIt;
  for (msIt = Sequences.begin(); msIt != Sequences.end(); msIt++) {
    if (msIt->second) {
      msIt->second->stop();
    }
  }
}

//! Returns a reference to the sequences map
map<u16, CMusicSequence*>& CMusic::getSequenceMap()
{
  return Sequences;
}

//! Returns a pointer to a sequence specified by number
CMusicSequence* CMusic::getSequence(u16 number)
{
  if (Sequences[number]) {
    return Sequences[number];
  } else {
    return NULL;
  }
}

//! Destructor
CMusic::~CMusic()
{
  map<u16, CMusicSequence*>::const_iterator msIt;
  for (msIt = Sequences.begin(); msIt != Sequences.end(); msIt++) {
    if (msIt->second) {
      delete msIt->second;
    }
  }
}

}}
