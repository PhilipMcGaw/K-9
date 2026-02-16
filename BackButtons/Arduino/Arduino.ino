#include "Charlieplex.h"



#define LED_A1 0
#define LED_A2 1
#define LED_A3 2
#define LED_A4 3

#define LED_B1 4
#define LED_B2 5
#define LED_B3 6
#define LED_B4 7

#define LED_C1 8
#define LED_C2 9
#define LED_C3 10
#define LED_C4 11

bool LED_A1_Status, LED_A2_Status, LED_A3_Status, LED_A4_Status  = false;
bool LED_B1_Status, LED_B2_Status, LED_B3_Status, LED_B4_Status  = false;
bool LED_C1_Status, LED_C2_Status, LED_C3_Status, LED_C4_Status  = false;

bool Switch_A1_Status, Switch_A2_Status, Switch_A3_Status, Switch_A4_Status  = false;
bool Switch_B1_Status, Switch_B2_Status, Switch_B3_Status, Switch_B4_Status  = false;
bool Switch_C1_Status, Switch_C2_Status, Switch_C3_Status, Switch_C4_Status  = false;

byte LED_pins[] = {1, 2, 3, 4};
Charlieplex charlie(LED_pins, sizeof(LED_pins));

void setup() {
    charlie.setLed(LED_A1, LED_A1_Status);    // Turn off LED_A1
    charlie.setLed(LED_A2, LED_A2_Status);    // Turn off LED_A2
    charlie.setLed(LED_A3, LED_A3_Status);    // Turn off LED_A3
    charlie.setLed(LED_A4, LED_A4_Status);    // Turn off LED_A4
    charlie.setLed(LED_B1, LED_B1_Status);    // Turn off LED_B1
    charlie.setLed(LED_B2, LED_B2_Status);    // Turn off LED_B2
    charlie.setLed(LED_B3, LED_B3_Status);    // Turn off LED_B3
    charlie.setLed(LED_B4, LED_B4_Status);    // Turn off LED_B4
    charlie.setLed(LED_C1, LED_C1_Status);    // Turn off LED_C1
    charlie.setLed(LED_C2, LED_C2_Status);    // Turn off LED_C2
    charlie.setLed(LED_C3, LED_C3_Status);    // Turn off LED_C3
    charlie.setLed(LED_C4, LED_C4_Status);    // Turn off LED_C4

}
void loop() {
    charlie.loop();
}
