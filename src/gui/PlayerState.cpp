/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

PlayerState::PlayerState() {
  playerName = new Text("Ayron", 0, 0);
  levelLabel = new Text("niv.", 0, -24);
  levelInfo = new Text("1", 100, -24);

  hpInfo = new MainStateInfo();
}

void PlayerState::render() {
  playerName->render();
  levelLabel->render();
  levelInfo->render();

  hpInfo->render();
}

PlayerState::~PlayerState() {
  delete playerName;
  delete levelLabel;
  delete levelInfo;

  delete hpInfo;
}
