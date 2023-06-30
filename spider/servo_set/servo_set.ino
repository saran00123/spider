/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/faq/how-to-control-speed-of-servo-motor
 */

#include <Servo.h>

Servo myServo;
unsigned long MOVING_TIME = 1000
; // moving time is 3 seconds
unsigned long moveStartTime;
int startAngle = 0; // 30°
int stopAngle  = 180; // 90°

void setup() {
  myServo.attach(3);
  myServo.write(45);
  delay(1000);
  moveStartTime = millis(); // start moving

  // TODO: other code
}

void loop() {
  unsigned long progress = millis() - moveStartTime;

  if (progress <= MOVING_TIME) {
    long angle = map(progress, 0, MOVING_TIME, startAngle, stopAngle);
    myServo.write(angle); 
  }

  // TODO: other code
}
