#include <Arduino.h>
#include "motor_control.h"

/* 电机引脚初始化 */
void MotorControl::init() {
    pinMode(MOTOR_EN_A_PIN, OUTPUT);
    pinMode(MOTOR_IN1_A_PIN, OUTPUT);
    pinMode(MOTOR_IN2_A_PIN, OUTPUT);

    pinMode(MOTOR_EN_B_PIN, OUTPUT);
    pinMode(MOTOR_IN1_B_PIN, OUTPUT);
    pinMode(MOTOR_IN2_B_PIN, OUTPUT);

    // 停止电机，确保所有引脚初始为 LOW
    motor_pins(LOW, LOW, LOW, LOW);
}

/* 设置电机引脚状态 */
void MotorControl::motor_pins(const int in1_A, const int in2_A, const int in1_B, const int in2_B) {
    digitalWrite(MOTOR_IN1_A_PIN, in1_A);
    digitalWrite(MOTOR_IN2_A_PIN, in2_A);
    digitalWrite(MOTOR_IN1_B_PIN, in1_B);
    digitalWrite(MOTOR_IN2_B_PIN, in2_B);
}

/* 电机控制 */
void MotorControl::move(const CarCommand cmd) const {
    switch (cmd) {
        case CarCommand::FORWARD:
            motor_pins(HIGH, LOW, LOW, HIGH);
            Serial.println("FORWARD");
            break;
        case CarCommand::BACKWARD:
            motor_pins(LOW, HIGH, HIGH, LOW);
            Serial.println("BACKWARD");
            break;
        case CarCommand::TURN_LEFT:
            motor_pins(LOW, HIGH, LOW, HIGH);
            Serial.println("TURN_LEFT");
            break;
        case CarCommand::TURN_RIGHT:
            motor_pins(HIGH, LOW, HIGH, LOW);
            Serial.println("TURN_RIGHT");
            break;
        default:
            motor_pins(LOW, LOW, LOW, LOW);
            Serial.println("STOP");
    }
    motor_speed(carSpeed);
}

void MotorControl::motor_speed(const int speed) {
    analogWrite(MOTOR_EN_A_PIN, speed);
    analogWrite(MOTOR_EN_B_PIN, speed);
}

/* 调整速度 */
void MotorControl::adjust_speed(const int adjustment) {
    carSpeed += adjustment;
    if (carSpeed > maxSpeed) carSpeed = maxSpeed;
    if (carSpeed < minSpeed) carSpeed = minSpeed;
    Serial.print("Adjusted carSpeed: ");
    Serial.println(carSpeed);
}
