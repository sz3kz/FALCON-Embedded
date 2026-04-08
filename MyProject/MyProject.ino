//#include <Arduino.h>
//#include <Wire.h>
#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>

const int MY_OUTPUT_PIN = LED_BUILTIN;
const int MY_INTERRUPT_PIN = 2;
const int SERIAL_THROUGHPUT = 9600;
Adafruit_MPU6050 mpu;

// can change behind compiler's back - don't out-optimize 
volatile bool buttonPressed = false;

void buttonEvent() {
  // switch buttonPressed value
  buttonPressed = (digitalRead(MY_INTERRUPT_PIN) == LOW);
}

void setup() {
  Serial.begin(SERIAL_THROUGHPUT);
  pinMode(MY_OUTPUT_PIN, OUTPUT);
  pinMode(MY_INTERRUPT_PIN, INPUT_PULLUP);

  // Register interrupt
  attachInterrupt(digitalPinToInterrupt(MY_INTERRUPT_PIN), buttonEvent, CHANGE);

  // Detect MPU
  if (! mpu.begin()){
    Serial.println("MPU not detected!");
    while (1)
      delay(1000);
  }
  Serial.println("MPU detected!");
}

void loop() {

  sensors_event_t acceleration;
  sensors_event_t gyroscopics;
  sensors_event_t temperature;
  mpu.getEvent(&acceleration, &gyroscopics, &temperature);
  Serial.println(acceleration.acceleration.x);

  if (buttonPressed) {
    digitalWrite(MY_OUTPUT_PIN, LOW);
  } else {
    digitalWrite(MY_OUTPUT_PIN, HIGH);
  }
}
