#include "../../include/ref/core.h"

using namespace irr;

Speaker::Speaker(StreamIdentifier, const core::vector3df& initPos, const core::stringw& text, f32 radius) : Entity() {
  video::ITexture* iconTexture = Game::getVideoDriver()->getTexture("resource/debug/icons/speaker.bmp");

  //gui::IGUIFont* font = Game::getDebugGUI()->addFont(

  icon = Game::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(1.0f, 1.0f), initPos);
  icon->setMaterialTexture(0, iconTexture);
  //textBB = Game::getSceneManager()->addBillboardTextSceneNode(0, text, 0, core::dimension2df(1.0f, 1.0f), core::vector3df(initPos.X, initPos.Y + 1.0f, initPos.Z));
}

void Speaker::render() { Entity::render();

}

Speaker::~Speaker() {
  icon->remove();
  //textBB->remove();
}
