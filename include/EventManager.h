/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_EVENT_MANAGER_H__
#define __IS06_EVENT_MANAGER_H__

using namespace irr;

/**
 * Cette classe gère les événements du jeu (clavier, souris...)
 */
class EventManager : public IEventReceiver {
  public:
    EventManager();
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

    bool OnEvent(const SEvent& event);

  private:
    bool keyDown[KEY_KEY_CODES_COUNT];
    bool keyOnce[KEY_KEY_CODES_COUNT];
    bool anyDown;
    bool anyOnce;
    bool mouseLeftDown;
    bool mouseLeftOnce;
    bool mouseRightDown;
    bool mouseRightOnce;

    f32 leftJoystickAngle;
    u8 leftJoystickForce;
    s16 leftJoystickXAxis;
    s16 leftJoystickYAxis;

    f32 rightJoystickAngle;
    u8 rightJoystickForce;
    s16 rightJoystickXAxis;
    s16 rightJoystickYAxis;

    u16 buttonStates;
    u32 povValue;
    core::position2di mousePosition;
};

#endif
