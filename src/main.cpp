#include <Arduino.h>
#include <ps2x_control.h>
#include <motor_control.h>

void (*resetFunc)(void) = 0;

void setup() {
    Serial.begin(9600);
    MotorControl::init();
    PS2xControl::init();
}

void loop() {
    if (error == 1) {
        resetFunc();
    }
    PS2xControl::controller();
}
