/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_EVENT_MANAGER_H__
#define __IS06_EVENT_MANAGER_H__

namespace is06
{
namespace engine
{

/**
 * Cette classe gère les événements du jeu (clavier, souris...)
 */
class CEventManager : public irr::IEventReceiver
{
  public:
    CEventManager();
    bool isKeyDown(irr::EKEY_CODE code);
    bool isKeyDownOnce(irr::EKEY_CODE code);
    bool anyKeyDown();
    bool anyKeyDownOnce();
    bool click();
    bool mouseRelease();
    bool mouseDown();
    const irr::core::position2di& getMousePosition() const;

    irr::u8 getLeftJoystickForce();
    irr::f32 getLeftJoystickAngle();
    irr::s8 getLeftJoystickXAxis();
    irr::s8 getLeftJoystickYAxis();

    irr::u8 getRightJoystickForce();
    irr::f32 getRightJoystickAngle();
    irr::s8 getRightJoystickXAxis();
    irr::s8 getRightJoystickYAxis();

    irr::u16 getPressedButtons();
    irr::u32 getPovValue();

    const irr::SEvent::SGUIEvent& getGUIEvent();

    bool OnEvent(const irr::SEvent& event);

  private:
    bool KeyDown[irr::KEY_KEY_CODES_COUNT];
    bool KeyOnce[irr::KEY_KEY_CODES_COUNT];
    bool AnyDown;
    bool AnyOnce;
    bool MouseLeftDown;
    bool MouseLeftOnce;
    bool MouseRightDown;
    bool MouseRightOnce;

    irr::SEvent::SGUIEvent GuiEvent;

    irr::f32 LeftJoystickAngle;
    irr::u8 LeftJoystickForce;
    irr::s16 LeftJoystickXAxis;
    irr::s16 LeftJoystickYAxis;

    irr::f32 RightJoystickAngle;
    irr::u8 RightJoystickForce;
    irr::s16 RightJoystickXAxis;
    irr::s16 RightJoystickYAxis;

    irr::u16 ButtonStates;
    irr::u32 PovValue;
    irr::core::position2di MousePosition;
};

}
}

#endif
