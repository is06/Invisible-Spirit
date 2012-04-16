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
namespace nEngine
{

/**
 * Cette classe gère les événements du jeu (clavier, souris...)
 */
class CEventManager : public IEventReceiver
{
  public:
    CEventManager();
    bool isKeyDown(EKEY_CODE code);
    bool isKeyDownOnce(EKEY_CODE code);
    bool anyKeyDown();
    bool anyKeyDownOnce();
    bool click();
    bool mouseRelease();
    bool mouseDown();
    const core::position2di& getMousePosition() const;

    u8 getLeftJoystickForce();
    f32 getLeftJoystickAngle();
    s8 getLeftJoystickXAxis();
    s8 getLeftJoystickYAxis();

    u8 getRightJoystickForce();
    f32 getRightJoystickAngle();
    s8 getRightJoystickXAxis();
    s8 getRightJoystickYAxis();

    u16 getPressedButtons();
    u32 getPovValue();

    const SEvent::SGUIEvent& getGUIEvent();

    bool OnEvent(const SEvent& event);

  private:
    bool KeyDown[KEY_KEY_CODES_COUNT];
    bool KeyOnce[KEY_KEY_CODES_COUNT];
    bool AnyDown;
    bool AnyOnce;
    bool MouseLeftDown;
    bool MouseLeftOnce;
    bool MouseRightDown;
    bool MouseRightOnce;

    SEvent::SGUIEvent GuiEvent;

    f32 LeftJoystickAngle;
    u8 LeftJoystickForce;
    s16 LeftJoystickXAxis;
    s16 LeftJoystickYAxis;

    f32 RightJoystickAngle;
    u8 RightJoystickForce;
    s16 RightJoystickXAxis;
    s16 RightJoystickYAxis;

    u16 ButtonStates;
    u32 PovValue;
    core::position2di MousePosition;
};

}
}

#endif
