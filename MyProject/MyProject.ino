//#include <Arduino.h>
//#include <Wire.h>
//
const int MY_OUTPUT_PIN = LED_BUILTIN;
const int MY_INTERRUPT_PIN = 2;

// can change behind compiler's back - don't out-optimize 
volatile bool buttonPressed = false;

void buttonEvent() {
  // switch buttonPressed value
  buttonPressed = (digitalRead(MY_INTERRUPT_PIN) == LOW);
}

void setup() {
  pinMode(MY_OUTPUT_PIN, OUTPUT);
  pinMode(MY_INTERRUPT_PIN, INPUT_PULLUP);

  // Register interrupt
  attachInterrupt(digitalPinToInterrupt(MY_INTERRUPT_PIN), buttonEvent, CHANGE);
}

void loop() {
  if (buttonPressed) {
    digitalWrite(MY_OUTPUT_PIN, LOW);
  } else {
    digitalWrite(MY_OUTPUT_PIN, HIGH);
  }
}
