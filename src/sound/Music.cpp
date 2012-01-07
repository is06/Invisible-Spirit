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

Music::Music(const core::stringc& id) {

}

void Music::addSequences(const map<u8, MusicSequenceInfo>& list) {
  map<u8, MusicSequenceInfo>::const_iterator msIt;
  for(msIt = list.begin(); msIt != list.end(); msIt++) {
    cout << "added sequence : " << msIt->second.fileName.c_str() << endl;
    sequences[msIt->first] = new MusicSequence(msIt->second);
  }
}

void Music::playSequences(const map<u8, MusicSequenceInfo>& list) {
  map<u8, MusicSequenceInfo>::const_iterator msIt;
  for(msIt = list.begin(); msIt != list.end(); msIt++) {
    sequences[msIt->first]->play();
  }
}

map<u8, MusicSequence*>& Music::getSequences() {
  return sequences;
}

Music::~Music() {

}
