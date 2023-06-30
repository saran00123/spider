#include <Servo.h>

Servo servo;
Servo servo1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  servo.attach(15); 
  servo.write(90);
  servo1.attach(3);
  servo1.write(180);
  Serial.begin(9600);
  delay(2000);

}

unsigned int degree2ms(unsigned int degrees){
  return  1000 + (degrees * 150  + 13) / 27;
}

int servowrite(float angle1, float angle2,int s){
//  if (s == 0){
//    if (angle1 > angle2){
//      float diff = angle1-angle2;
//      for(float i = angle1;i>=angle2;i= i-(diff/5)){
//        servo.write(degree2ms(i));
//        delay(20);
//      }
//    }
//  else{
//    float diff = angle2-angle1;
//    for(float i = angle1;i<=angle2;i=i+(diff/5)){
//      servo.write(degree2ms(i));
//      delay(20);
//    }  
//  } 
//  }
  if (s == 1){
    if (angle1 > angle2){
      float diff = angle1-angle2;
      for(float i = angle1;i>=angle2;i= i-(diff/70)){
        servo.write(degree2ms(i));
        delay(1);
      }
    }
  else{
    float diff = angle2-angle1;
    for(float i = angle1;i<=angle2;i=i+(diff/70)){
      servo.write(degree2ms(i));
      delay(1);
    }  
  } 
  }
  
  return 0;
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
//  servo.write(45);
//  servo1.write(45);
  servowrite(90,45,0);
  servowrite(90,45,1);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
//  servo.write(135);
//  servo1.write(180);
  servowrite(45,135,0);
  servowrite(45,180,1);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
//  servo.write(90);
//  servo1.write(90);
  servowrite(135,90,0);
  servowrite(180,90,1);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
