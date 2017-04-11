// ATtiny RGB Fading for Common Anode Rgb Leds

// Defining ATtiny pins with RGB Led pins
const int redPin = 2;
const int grnPin = 1;
const int bluPin = 0;

// Setup for outputs
void setup()
{
  pinMode(redPin, OUTPUT);    
  pinMode(grnPin, OUTPUT);    
  pinMode(bluPin, OUTPUT);
}

// Loop for fading
void loop() {
  redtoyellow();
  yellowtogreen();
  greentocyan();
  cyantoblue();
  bluetomagenta();
  magentatored();
}

// Functions for fade between 2 colors
void redtoyellow()
{
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, HIGH);

  // fade up green
  for(byte i=1; i<100; i++) {
  byte on  = i;
  byte off = 100-on;
  for( byte a=0; a<100; a++ ) {
    digitalWrite(grnPin, LOW);
    delayMicroseconds(on);
    digitalWrite(grnPin, HIGH);
    delayMicroseconds(off);
  }
  }
}

void yellowtogreen()
{
  digitalWrite(grnPin, LOW);
  digitalWrite(bluPin, HIGH);

  // fade down red
  for(byte i=1; i<100; i++) {
  byte on  = 100-i;
  byte off = i;
  for( byte a=0; a<100; a++ ) {
    digitalWrite(redPin, LOW);
    delayMicroseconds(on);
    digitalWrite(redPin, HIGH);
    delayMicroseconds(off);
  }
  }
}

void greentocyan()
{
  digitalWrite(grnPin, LOW);
  digitalWrite(redPin, HIGH);

  // fade up blue
  for(byte i=1; i<100; i++) {
  byte on  = i;
  byte off = 100-on;
  for( byte a=0; a<100; a++ ) {
    digitalWrite(bluPin, LOW);
    delayMicroseconds(on);
    digitalWrite(bluPin, HIGH);
    delayMicroseconds(off);
  }
  }
}

void cyantoblue()
{
  digitalWrite(bluPin, LOW);
  digitalWrite(redPin, HIGH);

  // fade down green
  for(byte i=1; i<100; i++) {
  byte on  = 100-i;
  byte off = i;
  for( byte a=0; a<100; a++ ) {
    digitalWrite(grnPin, LOW);
    delayMicroseconds(on);
    digitalWrite(grnPin, HIGH);
    delayMicroseconds(off);
  }
  }
}

void bluetomagenta()
{
  digitalWrite(bluPin, LOW);
  digitalWrite(grnPin, HIGH);

  // fade up red
  for(byte i=1; i<100; i++) {
  byte on  = i;
  byte off = 100-on;
  for( byte a=0; a<100; a++ ) {
    digitalWrite(redPin, LOW);
    delayMicroseconds(on);
    digitalWrite(redPin, HIGH);
    delayMicroseconds(off);
  }
  }
}

void magentatored()
{
  digitalWrite(redPin, LOW);
  digitalWrite(grnPin, HIGH);

  // fade down blue
  for(byte i=1; i<100; i++) {
  byte on  = 100-i;
  byte off = i;
  for( byte a=0; a<100; a++ ) {
    digitalWrite(bluPin, LOW);
    delayMicroseconds(on);
    digitalWrite(bluPin, HIGH);
    delayMicroseconds(off);
  }
  }
}



