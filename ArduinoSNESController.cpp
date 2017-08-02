/*
    ArduinoSNESController.cpp - An Arduino library to read input from SNES controllers.
    SNES data from http://gamesx.com/controldata/snesdat.htm
    Created by Aaron Shappell
*/

#include <ArduinoSNESController.h>

ArduinoSNESController::ArduinoSNESController(int _latchPin, int _clockPin, int _dataPin){
    latchPin = _latchPin;
    clockPin = _clockPin;
    dataPin = _dataPin;
    buttons = 0;
    buttonsOld = 0;

    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
}

bool ArduinoSNESController::isButtonPressed(int button){
    return (buttons & (1 << button)) & (~(buttonsOld & (1 << button)));
}

bool ArduinoSNESController::isButtonDown(int button){
    return buttons & (1 << button);
}

bool ArduinoSNESController::isButtonUp(int button){
    return ~(buttons & (1 << button));
}

void ArduinoSNESController::update(){
    buttonsOld = buttons;

    digitalWrite(latchPin, HIGH);
    delayMicroseconds(12);
    digitalWrite(latchPin, LOW);
    delayMicroseconds(6);
    for(int i = 0; i < 16; i++){
        buttons &= ~(1 << i) | (~(digitalRead(dataPin)) << i);
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(6);
        digitalWrite(clockPin, LOW);
        delayMicroseconds(6);
    }
}

word ArduinoSNESController::getButtons(){
    return buttons;
}

bool ArduinoSNESController::isButtonPressedB(){
    isButtonPressed(0);
}

bool ArduinoSNESController::isButtonPressedY(){
    isButtonPressed(1);
}

bool ArduinoSNESController::isButtonPressedSelect(){
    isButtonPressed(2);
}

bool ArduinoSNESController::isButtonPressedStart(){
    isButtonPressed(3);
}

bool ArduinoSNESController::isButtonPressedUp(){
    isButtonPressed(4);
}

bool ArduinoSNESController::isButtonPressedDown(){
    isButtonPressed(5);
}

bool ArduinoSNESController::isButtonPressedLeft(){
    isButtonPressed(6);
}

bool ArduinoSNESController::isButtonPressedRight(){
    isButtonPressed(7);
}

bool ArduinoSNESController::isButtonPressedA(){
    isButtonPressed(8);
}

bool ArduinoSNESController::isButtonPressedX(){
    isButtonPressed(9);
}

bool ArduinoSNESController::isButtonPressedL(){
    isButtonPressed(10);
}

bool ArduinoSNESController::isButtonPressedR(){
    isButtonPressed(11);
}

bool ArduinoSNESController::isButtonDownB(){
    isButtonDown(0);
}

bool ArduinoSNESController::isButtonDownY(){
    isButtonDown(1);
}

bool ArduinoSNESController::isButtonDownSelect(){
    isButtonDown(2);
}

bool ArduinoSNESController::isButtonDownStart(){
    isButtonDown(3);
}

bool ArduinoSNESController::isButtonDownUp(){
    isButtonDown(4);
}

bool ArduinoSNESController::isButtonDownDown(){
    isButtonDown(5);
}

bool ArduinoSNESController::isButtonDownLeft(){
    isButtonDown(6);
}

bool ArduinoSNESController::isButtonDownRight(){
    isButtonDown(7);
}

bool ArduinoSNESController::isButtonDownA(){
    isButtonDown(8);
}

bool ArduinoSNESController::isButtonDownX(){
    isButtonDown(9);
}

bool ArduinoSNESController::isButtonDownL(){
    isButtonDown(10);
}

bool ArduinoSNESController::isButtonDownR(){
    isButtonDown(11);
}

bool ArduinoSNESController::isButtonUpB(){
    isButtonUp(0);
}

bool ArduinoSNESController::isButtonUpY(){
    isButtonUp(1);
}

bool ArduinoSNESController::isButtonUpSelect(){
    isButtonUp(2);
}

bool ArduinoSNESController::isButtonUpStart(){
    isButtonUp(3);
}

bool ArduinoSNESController::isButtonUpUp(){
    isButtonUp(4);
}

bool ArduinoSNESController::isButtonUpDown(){
    isButtonUp(5);
}

bool ArduinoSNESController::isButtonUpLeft(){
    isButtonUp(6);
}

bool ArduinoSNESController::isButtonUpRight(){
    isButtonUp(7);
}

bool ArduinoSNESController::isButtonUpA(){
    isButtonUp(8);
}

bool ArduinoSNESController::isButtonUpX(){
    isButtonUp(9);
}

bool ArduinoSNESController::isButtonUpL(){
    isButtonUp(10);
}

bool ArduinoSNESController::isButtonUpR(){
    isButtonUp(11);
}