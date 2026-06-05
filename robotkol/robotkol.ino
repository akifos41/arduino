#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
}

void loop() {

  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);
  int pot3 = analogRead(A2);
  int pot4 = analogRead(A3);

  int aci1 = map(pot1, 0, 1023, 0, 180);
  int aci2 = map(pot2, 0, 1023, 0, 180);
  int aci3 = map(pot3, 0, 1023, 0, 180);
  int aci4 = map(pot4, 0, 1023, 0, 180);

  servo1.write(aci1);
  servo2.write(aci2);
  servo3.write(aci3);
  servo4.write(aci4);

  delay(15);
}
