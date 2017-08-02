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
    
}

word ArduinoSNESController::getButtons(){

}