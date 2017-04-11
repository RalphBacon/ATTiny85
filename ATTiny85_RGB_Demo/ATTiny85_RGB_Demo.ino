// RGB_Tiny Board Testing for Common Anode Rgb Leds
// with LOW it lgiths up the led and with HIGH it lights off because its INVERTED due to common anode rgb led

// Defining ATtiny pins with RGB Led pins
const int redPin = 2; 
const int grnPin = 1; 
const int bluPin = 0;
int del = 500; // delay

// Setup for outputs
void setup()
{

pinMode(redPin, OUTPUT); 
pinMode(grnPin, OUTPUT); 
pinMode(bluPin, OUTPUT);

digitalWrite(redPin, HIGH);
digitalWrite(bluPin, HIGH);
digitalWrite(grnPin, HIGH);

}

// Loop for fading
void loop() {
digitalWrite(redPin, LOW);
delay(del);
digitalWrite(redPin, HIGH);
delay(del/2);
digitalWrite(bluPin, LOW);
delay(del);
digitalWrite(bluPin, HIGH);
delay(del/2);
digitalWrite(grnPin, LOW);
delay(del);
digitalWrite(grnPin, HIGH);
delay(del/2);
digitalWrite(redPin, LOW);
digitalWrite(bluPin, LOW);
digitalWrite(grnPin, LOW);
delay(del);
digitalWrite(redPin, HIGH);
digitalWrite(bluPin, HIGH);
digitalWrite(grnPin, HIGH);
delay(del/2);
}
