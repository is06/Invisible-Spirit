/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/sound/Music.h"
#include "../../include/sound/MusicReference.h"

using namespace std;
using namespace irr;

MusicReference::MusicReference()
{
  currentMusic = NULL;

  fstream fileStream("resource/music/list.data", ios::in);
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
        std::istringstream iss(sequenceNumber);
        iss >> sequenceNumberInt;
        iss.str(sequenceLoopStart);
        iss >> loopStartInt;
        iss.str(sequenceLoopEnd);
        iss >> loopEndInt;

        musicList[musicName].sequenceInfo[sequenceNumberInt].number = sequenceNumberInt;
        musicList[musicName].sequenceInfo[sequenceNumberInt].looped = sequenceLooped;
        musicList[musicName].sequenceInfo[sequenceNumberInt].loopStart = loopStartInt;
        musicList[musicName].sequenceInfo[sequenceNumberInt].loopEnd = loopEndInt;
        musicList[musicName].sequenceInfo[sequenceNumberInt].fileName = sequenceFileName;

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

void MusicReference::play(const string& id)
{
  currentId = id;

  if (!currentMusic) {
    currentMusic = new Music(id);
    currentMusic->addSequences(musicList[id].sequenceInfo);
    currentMusic->playSequences(musicList[id].sequenceInfo);
  }
}

void MusicReference::muteSequence(const string& id, u16 number)
{
  if (currentMusic->getSequence(number)) {
    currentMusic->getSequence(number)->setVolume(0.0f);
  }
}

void MusicReference::unmuteSequence(const string& id, u16 number)
{
  if (currentMusic->getSequence(number)) {
    currentMusic->getSequence(number)->setVolume(1.0f);
  }
}

void MusicReference::stop()
{

}

Music* MusicReference::getCurrentMusic()
{
  return currentMusic;
}

MusicReference::~MusicReference()
{

}
