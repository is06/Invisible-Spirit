/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis � disposition selon
les termes de la licence Creative Commons Paternit� - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales � l'Identique (BY-NC-SA) 3.0
Unported. Bas�(e) sur une oeuvre � www.is06.com.  Les autorisations au-del� du
champ de cette licence peuvent �tre obtenues � http://www.is06.com.
*******************************************************************************/

#ifndef GAMEPAD_H
#define GAMEPAD_H

class Gamepad {
  public:
    Gamepad();

    u8 getLeftJoystickForce();
    f32 getLeftJoystickAngle();
    s8 getLeftJoystickXAxis();
    s8 getLeftJoystickYAxis();

    u8 getRightJoystickForce();
    f32 getRightJoystickAngle();
    s8 getRightJoystickXAxis();
    s8 getRightJoystickYAxis();

    bool buttonPressed(u16 buttons);
    bool dirPressed(GamepadDirection direction);
};

#endif
