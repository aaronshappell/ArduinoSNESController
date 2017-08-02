/*
    ReadController.ino - Example for ArduinoSNESController library
    Created by Aaron Shappell
*/

#include <ArduinoSNESController.h>

//Define pins
int latchPin = 9;
int clockPin = 10;
int dataPin = 11;

ArduinoSNESController controller(latchPin, clockPin, dataPin);

void setup(){
    Serial.begin(9600);
}

void loop(){
    //Update the controller
    controller.update();

    //Check if a button has been pressed
    if(controller.isButtonPressedA()){
        Serial.println("Button A has been Pressed!");
    }

    //Check if a button is down
    if(controller.isButtonDownA()){
        Serial.println("Button A is down!");
    }

    //Check if a button is up
    if(controller.isButtonUpA()){
        Serial.println("Button A is up!");
    }

    //Get word that represents all button states
    word buttons = controller.getButtons();
}