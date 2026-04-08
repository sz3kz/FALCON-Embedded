//#include <Arduino.h>
//#include <Wire.h>
#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>

const int MY_OUTPUT_PIN = LED_BUILTIN;
const int MY_INTERRUPT_PIN = 2;
const int SERIAL_THROUGHPUT = 9600;
const float THRESHOLD = 10;
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
  static int state = LOW;
  static long last_flickering = 0;
  static long last_button = 0;
  unsigned long now = millis();


  sensors_event_t acceleration;
  sensors_event_t gyroscopics;
  sensors_event_t temperature;
  mpu.getEvent(&acceleration, &gyroscopics, &temperature);

  if (abs(acceleration.acceleration.x) >= THRESHOLD &&
      now - last_flickering >= 200){
    last_flickering = now;
    if (state == LOW){
      digitalWrite(MY_OUTPUT_PIN, HIGH);
      state = HIGH;
      Serial.println("Set pin to high.");
    }
    else if (state == HIGH){
      digitalWrite(MY_OUTPUT_PIN, LOW);
      state = LOW;
      Serial.println("Set pin to low.");
    }
  }
  if (buttonPressed && now - last_button >= 1000){
    last_button = now;
    Serial.print("X acceleration: ");
    Serial.println(acceleration.acceleration.x);
  }
}
