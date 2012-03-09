/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/sound/Music.h"

using namespace std;
using namespace irr;

Music::Music(const string& id)
{

}

void Music::addSequences(const map<u16, MusicSequenceInfo>& list)
{
  map<u16, MusicSequenceInfo>::const_iterator msIt;
  for (msIt = list.begin(); msIt != list.end(); msIt++) {
    sequences[msIt->second.number] = new MusicSequence(msIt->second);
  }
}

/**
 * Plays all the music sequences
 */
void Music::playSequences(const map<u16, MusicSequenceInfo>& list)
{
  map<u16, MusicSequenceInfo>::const_iterator msIt;
  for (msIt = list.begin(); msIt != list.end(); msIt++) {
    sequences[msIt->second.number]->play();
  }
}

/**
 * Returns a reference to the sequences map
 */
map<u16, MusicSequence*>& Music::getSequenceMap()
{
  return sequences;
}

/**
 * Returns a pointer to a sequence specified by number
 */
MusicSequence* Music::getSequence(u16 number)
{
  if (sequences[number]) {
    return sequences[number];
  } else {
    return NULL;
  }
}

/**
 * @todo Delete sequences
 */
Music::~Music()
{

}
