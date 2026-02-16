#include "Charlieplex.h"

byte pins[] = {1, 2, 3, 4};
Charlieplex charlie(pins, sizeof(pins));



void setup() {
    charlie.setLed(0, false);    // Turn off LED0
    charlie.setLed(1, false);    // Turn off LED1
    charlie.setLed(2, false);    // Turn off LED2
    charlie.setLed(3, false);    // Turn off LED3
    charlie.setLed(4, false);    // Turn off LED4
    charlie.setLed(5, false);    // Turn off LED5
    charlie.setLed(6, false);    // Turn off LED6
    charlie.setLed(7, false);    // Turn off LED7
    charlie.setLed(8, false);    // Turn off LED8
    charlie.setLed(9, false);    // Turn off LED9
    charlie.setLed(10, false);    // Turn off LED10
    charlie.setLed(11, false);    // Turn off LED11

}
void loop() {
    charlie.loop();
}
