// ATTINY85 I2C to LCD demo

#include <TinyWireM.h>                  // I2C Master lib for ATTinys which use USI
#include <LiquidCrystal_I2C.h>          // for LCD w/ GPIO MODIFIED for the ATtiny85

#define GPIO_ADDR     0x27              // (PCA8574A A0-A2 @5V) typ. A0-A3 Gnd 0x20 / 0x38 for A
LiquidCrystal_I2C lcd(GPIO_ADDR, 16, 2); // set address & 16 chars / 2 lines

void setup() {
  TinyWireM.begin();                    // initialize I2C lib
  lcd.init();                           // initialize the lcd
  lcd.backlight();                      // Print a message to the LCD.
  lcd.print("Hello, Temp!");
  delay (2000);
}

void loop() {
  /*
    lcd.clear();                          // display it
    lcd.print("C: ");
    lcd.print(tempC,DEC);
    lcd.setCursor(7,0);
    lcd.print("F: ");
  */
}
