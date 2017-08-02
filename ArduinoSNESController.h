/*
    ArduinoSNESController.h - An Arduino library to read input from SNES controllers.
    SNES data from http://gamesx.com/controldata/snesdat.htm
    Created by Aaron Shappell
*/

#ifndef ArduinoSNESController_h
#define ArduinoSNESController_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ArduinoSNESController{
    private:
        int latchPin;
        int clockPin;
        int dataPin;
        word buttons;
        word buttonsOld;
        bool isButtonPressed(int button);
        bool isButtonDown(int button);
        bool isButtonUp(int button);
    public:
        ArduinoSNESController(int _latchPin, int _clockPin, int _dataPin);
        void update();
        word getButtons();
        bool isButtonPressedB();
        bool isButtonPressedY();
        bool isButtonPressedSelect();
        bool isButtonPressedStart();
        bool isButtonPressedUp();
        bool isButtonPressedDown();
        bool isButtonPressedLeft();
        bool isButtonPressedRight();
        bool isButtonPressedA();
        bool isButtonPressedX();
        bool isButtonPressedL();
        bool isButtonPressedR();
        bool isButtonDownB();
        bool isButtonDownY();
        bool isButtonDownSelect();
        bool isButtonDownStart();
        bool isButtonDownUp();
        bool isButtonDownDown();
        bool isButtonDownLeft();
        bool isButtonDownRight();
        bool isButtonDownA();
        bool isButtonDownX();
        bool isButtonDownL();
        bool isButtonDownR();
        bool isButtonUpB();
        bool isButtonUpY();
        bool isButtonUpSelect();
        bool isButtonUpStart();
        bool isButtonUpUp();
        bool isButtonUpDown();
        bool isButtonUpLeft();
        bool isButtonUpRight();
        bool isButtonUpA();
        bool isButtonUpX();
        bool isButtonUpL();
        bool isButtonUpR();
};

#endif
