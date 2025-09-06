#ifndef PARAMETERS_H
#define PARAMETERS_H

#define SERIAL_BAUD 115200
#define MOTOR_PIN 3
#define DIRECTION_PIN 4
#define SERVOMOTOR_PIN 6
// Initial angle of the servomotor
#define INITIAL_THETA 110
// Min and max values for motors
#define THETA_MIN 60
#define THETA_MAX 150
#define SPEED_MAX 100
// If DEBUG is set to true, the arduino will send back all the received messages
#define DEBUG false

// Set speeds  zero if no messages where received after 500ms
#define TIMEOUT 500

// Pin Functions and numbers

#define ESC_1_PIN 8
#define ESC_2_PIN 9
#define ESC_3_PIN 10
#define ESC_4_PIN 11
#define ESC_5_PIN 12
#define ESC_6_PIN 13
#define ESC_7_PIN 18
#define ESC_8_PIN 19

#define LED_1_PIN 16
#define LED_2_PIN 17

#define SERVO_1_Pin 2
#define SERVO_2_Pin 3
#define SERVO_3_Pin 4
#define SERVO_4_Pin 5

#define ADC_I_PIN 0
#define ADC_V_PIN 1

#endif
