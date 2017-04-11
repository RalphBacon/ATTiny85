/*
 * Demo sketch for ATTiny85 using I2C driving a standard 16 x 2 LCD
 * with PCF8574AT driver chip (that uses the I2C to communicatate with
 * both the Tiny85 and the LCD - a middleman)
 */
// This library is modified to serve standard Arduino boards AND ATTiny85
// The main difference is that the Wire.h library is included for standard
// Arduino boards, but the TinyWireM.h library is used for ATTiny85
#include <LiquidCrystal_I2C.h>

// Measure temp using a DS18B20 one wire device
#include <OneWire.h>
#include <DallasTemperature.h>

// Pin connections (also for ATTiny85 Development board)
/*
 * Connect your LCD display as follows to the Tiny85 (pin numbers refer
 * to the physical pins of the chip starting with pin 1 in top left corner
 * and working round the chip ANTI-CLOCKWISE with pin 8 top right corner.
 * 
 * SDA - pin 5
 * SCL - pin 7
 * 
 * ATTiny85 Pin Use Summary:
 *    
 * ATtiny Pin 1 = (RESET) Not Used  ATtiny Pin 2 = (D3) Not used
 * ATtiny Pin 3 = (D4) to LED1      ATtiny Pin 4 = GND
 * ATtiny Pin 5 = SDA & GPIO        ATtiny Pin 6 = (D1) to LED2
 * ATtiny Pin 7 = SCL & GPIO        ATtiny Pin 8 = VCC (2.7-5.5V)
*/

/* 
 * Set the LCD address for a 16 chars and 2 line display.
 * 
 * This is determined by whether the pads on the backpack PCF8574AT
 * has had any of the A0/A1/A2 solder pads bridged
 *  
 * None bridged: 0x3F
 * 
 * Address can range from 0x38 to 0x3F depending on which pads are
 * bridged. See http://www.nxp.com/documents/data_sheet/PCF8574_PCF8574A.pdf
 * section 7.11 for further details.
 */
uint8_t hexAddr = 0x3F;

// It's a 16 x 2 LCD device in this demo.
uint8_t rows = 2;
uint8_t cols = 16;

// Instantiate the LCD object with all these parameters
LiquidCrystal_I2C lcd(hexAddr, cols, rows);

// One wire on GPIO pin
OneWire onewire(1);
DallasTemperature tempSensor(&onewire);

// -------------------------------------------------------------------
// 
// -------------------------------------------------------------------
void setup()
{
  // initialize the LCD. NB do not use begin() use init() now.
  lcd.init();

  // Start the temperature sensor
  tempSensor.begin();

  // Turn on the blacklight, clear the display and print a message.
  lcd.backlight();
  lcd.clear();  
  
  lcd.print("Found: ");
  lcd.print(String(tempSensor.getDeviceCount()));
}

// -------------------------------------------------------------------
// 
// -------------------------------------------------------------------
void loop()
{
  tempSensor.requestTemperatures();
  delay(1000);
  float celsius = tempSensor.getTempCByIndex(0);
  
  lcd.setCursor(0,1); // column, row (zero based)
  lcd.print(celsius);
}
