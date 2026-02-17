#include "src/Charlieplex/Charlieplex.h"

#include <SPI.h>
// #include <SD.h> (not using the SD card)
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
// Be sure to install Adafruit seesaw library!
#include <Adafruit_seesaw.h>
#include <Adafruit_TFTShield18.h>

/* 
    Screen - https://learn.adafruit.com/1-8-tft-display/1-8-tft-shield

    Pins
        SCK - SPI Clock
        MOSI - SPI Data
        Digital 10 - Chip Select
        Digital 8 - Data/Command Select

    Required Librarys 
        Adafruit GFX Library
        Adafruit ST7735 Library
        Adafruit seesaw Library (I2C chip for reading buttons and manging backlight).

*/


#define LED_Pin_1 2
#define LED_Pin_2 3
#define LED_Pin_3 4
#define LED_Pin_4 5

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

// TFT display and SD card will share the hardware SPI interface.
// Hardware SPI pins are specific to the Arduino board type and
// cannot be remapped to alternate pins.  For Arduino Uno,
// Duemilanove, etc., pin 11 = MOSI, pin 12 = MISO, pin 13 = SCK.
#define SD_CS    4  // Chip select line for SD card on Shield
#define TFT_CS  10  // Chip select line for TFT display on Shield
#define TFT_DC   8  // Data/command line for TFT on Shield
#define TFT_RST  -1  // Reset line for TFT is handled by seesaw!

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Adafruit_TFTShield18 ss; // Seesaw

const byte LED_pins[] = {LED_Pin_1, LED_Pin_2, LED_Pin_3, LED_Pin_4};

Charlieplex charlie(LED_pins, sizeof(LED_pins));




void setup() {
    Serial.begin(9600);
  
    // start by disabling both SD and TFT
    pinMode(TFT_CS, OUTPUT);
    digitalWrite(TFT_CS, HIGH);
    pinMode(SD_CS, OUTPUT);
    digitalWrite(SD_CS, HIGH);

    // Start seesaw helper chip (this is on the sheild)
    if (!ss.begin()){
        Serial.println("seesaw could not be initialized!");
        while(1);
    }
    Serial.println("seesaw started");
    Serial.print("Version: "); Serial.println(ss.getVersion(), HEX);

    // Start set the backlight off
    ss.setBacklight(TFTSHIELD_BACKLIGHT_OFF);
    // Reset the TFT
    ss.tftReset();

    // Initialize 1.8" TFT
    tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

    Serial.println("TFT OK!");
    tft.setRotation(1);  // the rotation can be 0, 1, 2 or 3, however 1 puts it up the right way :)
    tft.fillScreen(ST77XX_BLACK); // Blanks the screen

    // This prints the word "Initialising." on the blank black screen
    // screen is 26 size 1 char wide, (8 px tall)
    // screen is 13 size 2 char wide, (16 px tall)
    // screen is 8 size 3 char wide,  (24 px tall)

    tft.setTextSize(2);
    tft.setTextColor(ST77XX_WHITE);
    tft.setCursor(0, 0);
    tft.print("Initialising.");
    tft.setCursor(0, 16);
    tft.print("second line");

    charlie.setLed(LED_A1, LED_A1_Status);    // Set initial status for LED_A1
    charlie.setLed(LED_A2, LED_A2_Status);    // Set initial status for LED_A2
    charlie.setLed(LED_A3, LED_A3_Status);    // Set initial status for LED_A3
    charlie.setLed(LED_A4, LED_A4_Status);    // Set initial status for LED_A4
    charlie.setLed(LED_B1, LED_B1_Status);    // Set initial status for LED_B1
    charlie.setLed(LED_B2, LED_B2_Status);    // Set initial status for LED_B2
    charlie.setLed(LED_B3, LED_B3_Status);    // Set initial status for LED_B3
    charlie.setLed(LED_B4, LED_B4_Status);    // Set initial status for LED_B4
    charlie.setLed(LED_C1, LED_C1_Status);    // Set initial status for LED_C1
    charlie.setLed(LED_C2, LED_C2_Status);    // Set initial status for LED_C2
    charlie.setLed(LED_C3, LED_C3_Status);    // Set initial status for LED_C3
    charlie.setLed(LED_C4, LED_C4_Status);    // Set initial status for LED_C4

    // Set backlight on fully
    // ss.setBacklight(TFTSHIELD_BACKLIGHT_ON);
    // Or you can set the backlight one third on
    // ss.setBacklight(TFTSHIELD_BACKLIGHT_ON / 3);
    // Or dim it up
    for (int32_t i=TFTSHIELD_BACKLIGHT_OFF; i<TFTSHIELD_BACKLIGHT_ON; i+=100) {
        ss.setBacklight(i);
        delay(2);
    }





}
void loop() {
    charlie.loop();
}
