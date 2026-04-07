//#include <Arduino.h>
//#include <Wire.h>

const int MY_OUTPUT_PIN = LED_BUILTIN;

// "setup()" is a function ran at startup
void setup() {
  // make led take power to light up
  pinMode(MY_OUTPUT_PIN, OUTPUT);
}

// "loop()" is a function ran after startup, continuously
void loop() {
    // light up the led
    digitalWrite(MY_OUTPUT_PIN, HIGH);

    //wait 2 seconds
    delay(2000);

    // light it down
    digitalWrite(MY_OUTPUT_PIN, LOW);

    //wait 2 seconds
    delay(2000);
}
