#define LED 0

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT); //LED on Model B
  //pinMode(1, OUTPUT); //LED on Model A  or Pro

  //pinMode(2, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //if (digitalRead(2) == LOW) 
  {

    digitalWrite(LED, HIGH);
    delay(150);

    digitalWrite(LED, LOW);
    delay(150);

    digitalWrite(LED, HIGH);
    delay(150);

    digitalWrite(LED, LOW);
    delay(1000);
  }
}
