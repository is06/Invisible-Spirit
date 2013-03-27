/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NSound/CMusic.h"
#include "../../include/NSound/CMusicReference.h"

namespace is06 { namespace NSound {

//! Music interface initialization, loads music info from resource/music/list.ism file
CMusicReference::CMusicReference()
{
  CurrentMusic = NULL;

  fstream fileStream("resource/music/list.ism", ios::in);
  if (fileStream) {
    bool inMusicNameDeclaration = true;
    bool inSeqNumbDeclaration = false;
    bool inSeqLoopDeclaration = false;
    bool inSeqStartDeclaration = false;
    bool inSeqEndDeclaration = false;
    bool inSeqFileDeclaration = false;

    char current = 0;
    string musicName("");
    string sequenceNumber("");
    bool sequenceLooped = true;
    string sequenceLoopStart("");
    string sequenceLoopEnd("");
    string sequenceFileName("");

    while (fileStream.get(current)) {
      if (current == '=') {
        inMusicNameDeclaration = false;
        inSeqNumbDeclaration = true;
        continue;
      } else if (current == ':') {
        if (inSeqNumbDeclaration) {
          inSeqNumbDeclaration = false;
          inSeqLoopDeclaration = true;
          continue;
        }
        if (inSeqLoopDeclaration) {
          inSeqLoopDeclaration = false;
          inSeqStartDeclaration = true;
          continue;
        }
        if (inSeqStartDeclaration) {
          inSeqStartDeclaration = false;
          inSeqEndDeclaration = true;
          continue;
        }
        if (inSeqEndDeclaration) {
          inSeqEndDeclaration = false;
          inSeqFileDeclaration = true;
          continue;
        }
      } else if (current == ';') {
        // Ending a sequence declaration
        inSeqFileDeclaration = false;
        inSeqNumbDeclaration = true;

        u16 sequenceNumberInt;
        u32 loopStartInt;
        u32 loopEndInt;
        istringstream iss(sequenceNumber);
        iss >> sequenceNumberInt;
        iss.clear();
        iss.str(sequenceLoopStart);
        iss >> loopStartInt;
        iss.clear();
        iss.str(sequenceLoopEnd);
        iss >> loopEndInt;

        MusicList[musicName].SequenceInfo[sequenceNumberInt].Number = sequenceNumberInt;
        MusicList[musicName].SequenceInfo[sequenceNumberInt].Looped = sequenceLooped;
        MusicList[musicName].SequenceInfo[sequenceNumberInt].LoopStart = loopStartInt;
        MusicList[musicName].SequenceInfo[sequenceNumberInt].LoopEnd = loopEndInt;
        MusicList[musicName].SequenceInfo[sequenceNumberInt].FileName = sequenceFileName;

        sequenceNumber = "";
        sequenceLoopStart = "";
        sequenceLoopEnd = "";
        sequenceFileName = "";

        continue;
      } else if (current == '\n' || current == '\r') {
        // Ending a music declaration
        inMusicNameDeclaration = true;
        inSeqNumbDeclaration = false;
        inSeqFileDeclaration = false;
        musicName = "";

        continue;
      }

      if (inMusicNameDeclaration) {
        musicName += current;
      }
      if (inSeqNumbDeclaration) {
        sequenceNumber += current;
      }
      if (inSeqLoopDeclaration) {
        sequenceLooped = (current == '1');
      }
      if (inSeqStartDeclaration) {
        sequenceLoopStart += current;
      }
      if (inSeqEndDeclaration) {
        sequenceLoopEnd += current;
      }
      if (inSeqFileDeclaration) {
        sequenceFileName += current;
      }
    }
  }
}

//! Plays a music by its id (name identifier)
/**
 * \param string id the name of the music
 */
void CMusicReference::play(const string& id)
{
  CurrentId = id;

  if (!CurrentMusic) {
    CurrentMusic = new CMusic(id);
    CurrentMusic->addSequences(MusicList[id].SequenceInfo);
    CurrentMusic->playSequences();
  }
}

//! Mutes a specific sequence of the current multi-layer music
/**
 * \param u16 number the sequence layer number
 */
void CMusicReference::muteSequence(u16 number)
{
  if (CurrentMusic->getSequence(number)) {
    CurrentMusic->getSequence(number)->setVolume(0.0f);
  }
}

//! Unmutes a specific sequence of the current multi-layer music
/**
 * \param u16 number the sequence layer number
 */
void CMusicReference::unmuteSequence(u16 number)
{
  if (CurrentMusic->getSequence(number)) {
    CurrentMusic->getSequence(number)->setVolume(1.0f);
  }
}

//! Stops the current music
void CMusicReference::stop()
{
  CurrentMusic->stopSequences();
}

//! Returns the current music pointer
CMusic* CMusicReference::getCurrentMusic()
{
  return CurrentMusic;
}

//! Destructor
CMusicReference::~CMusicReference()
{
  if (CurrentMusic) {
    delete CurrentMusic;
  }
}

}}
