#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);

#define hiz_a 5
#define hiz_b 6
#define motor1_1 7
#define motor1_2 8
#define motor2_1 9
#define motor2_2 12

#define sol_sensor A0
#define orta_sensor A1
#define sag_sensor A2

char mod = 'm'; 
char komut;


void ileri_git() {
  digitalWrite(motor1_1, HIGH);
  digitalWrite(motor1_2, LOW);
  digitalWrite(motor2_1, HIGH);
  digitalWrite(motor2_2, LOW);
}

void geri_git() {
  digitalWrite(motor1_1, LOW);
  digitalWrite(motor1_2, HIGH);
  digitalWrite(motor2_1, LOW);
  digitalWrite(motor2_2, HIGH);
}

void sola_don() {
  digitalWrite(motor1_1, LOW);
  digitalWrite(motor1_2, HIGH);
  digitalWrite(motor2_1, HIGH);
  digitalWrite(motor2_2, LOW);
}

void saga_don() {
  digitalWrite(motor1_1, HIGH);
  digitalWrite(motor1_2, LOW);
  digitalWrite(motor2_1, LOW);
  digitalWrite(motor2_2, HIGH);
}

void dur() {
  digitalWrite(motor1_1, LOW);
  digitalWrite(motor1_2, LOW);
  digitalWrite(motor2_1, LOW);
  digitalWrite(motor2_2, LOW);
}


void setup() {
  pinMode(hiz_a, OUTPUT);
  pinMode(hiz_b, OUTPUT);

  pinMode(motor1_1, OUTPUT);
  pinMode(motor1_2, OUTPUT);
  pinMode(motor2_1, OUTPUT);
  pinMode(motor2_2, OUTPUT);

  pinMode(sol_sensor, INPUT);
  pinMode(orta_sensor, INPUT);
  pinMode(sag_sensor, INPUT);

  bluetooth.begin(9600);

  analogWrite(hiz_a, 150);
  analogWrite(hiz_b, 150);
}

void loop() {

  if (bluetooth.available()) {
    komut = bluetooth.read();

    if (komut == 'A') mod = 'a';
    if (komut == 'M') mod = 'm';

    if (mod == 'm') {
      if (komut == 'I') ileri_git();
      else if (komut == 'G') geri_git();
      else if (komut == 'S') sola_don();
      else if (komut == 'D') saga_don();
      else if (komut == 'H') dur();
    }
  }

  if (mod == 'a') {

    int sol = digitalRead(sol_sensor);
    int orta = digitalRead(orta_sensor);
    int sag = digitalRead(sag_sensor);

    if (orta == LOW) {
      ileri_git();
    }
    else if (sol == LOW) {
      sola_don();
    }
    else if (sag == LOW) {
      saga_don();
    }
    else {
      dur();
    }
  }
}