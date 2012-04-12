/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/sound/Music.h"
#include "../../include/sound/MusicReference.h"

namespace is06
{
namespace sound
{

CMusicReference::CMusicReference()
{
  CurrentMusic = NULL;

  std::fstream fileStream("resource/music/list.ism", std::ios::in);
  if (fileStream) {
    bool inMusicNameDeclaration = true;
    bool inSeqNumbDeclaration = false;
    bool inSeqLoopDeclaration = false;
    bool inSeqStartDeclaration = false;
    bool inSeqEndDeclaration = false;
    bool inSeqFileDeclaration = false;

    char current = 0;
    std::string musicName("");
    std::string sequenceNumber("");
    bool sequenceLooped = true;
    std::string sequenceLoopStart("");
    std::string sequenceLoopEnd("");
    std::string sequenceFileName("");

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

        irr::u16 sequenceNumberInt;
        irr::u32 loopStartInt;
        irr::u32 loopEndInt;
        std::istringstream iss(sequenceNumber);
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

void CMusicReference::play(const std::string& id)
{
  CurrentId = id;

  if (!CurrentMusic) {
    CurrentMusic = new CMusic(id);
    CurrentMusic->addSequences(MusicList[id].SequenceInfo);
    CurrentMusic->playSequences(MusicList[id].SequenceInfo);
  }
}

void CMusicReference::muteSequence(const std::string& id, irr::u16 number)
{
  if (CurrentMusic->getSequence(number)) {
    CurrentMusic->getSequence(number)->setVolume(0.0f);
  }
}

void CMusicReference::unmuteSequence(const std::string& id, irr::u16 number)
{
  if (CurrentMusic->getSequence(number)) {
    CurrentMusic->getSequence(number)->setVolume(1.0f);
  }
}

void CMusicReference::stop()
{

}

CMusic* CMusicReference::getCurrentMusic()
{
  return CurrentMusic;
}

CMusicReference::~CMusicReference()
{

}

}
}
