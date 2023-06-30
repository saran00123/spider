void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
}

unsigned int degree2ms(unsigned int degrees){
  return  1000 + (degrees * 150  + 13) / 27;
}

void loop() {
  int angle = 93;
  int ms = degree2ms(angle);
  Serial.println(ms);
  // put your main code here, to run repeatedly:

}
