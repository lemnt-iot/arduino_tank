#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#define MOTOR_EN_A_PIN 3
#define MOTOR_IN1_A_PIN 4
#define MOTOR_IN2_A_PIN 5
#define MOTOR_EN_B_PIN 6
#define MOTOR_IN1_B_PIN 7
#define MOTOR_IN2_B_PIN 8

/* 定义五种运动状态 */
enum class CarCommand {
    STOP,
    FORWARD,
    BACKWARD,
    TURN_LEFT,
    TURN_RIGHT
};

constexpr int maxSpeed = 255; // 定义最大速度
constexpr int minSpeed = 0; // 定义最小速度
constexpr int speedStep = 10; // 定义速度步长

class MotorControl {
public:
    static void init();

    void move(CarCommand cmd) const;

    void adjust_speed(int adjustment);

    static void motor_speed(int speed);

private:
    static void motor_pins(int in1_A, int in2_A, int in1_B, int in2_B);

    int carSpeed = 128; // 默认速度为 128，可动态调整
};

#endif //MOTOR_CONTROL_H
