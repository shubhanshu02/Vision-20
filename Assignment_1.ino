#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); //RX = 10 and TX = 11

char R; //Response from user

void setup() {
  //Right Motor
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  //Left Motor
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

Serial.begin(9600);

void loop() {
  if (bluetooth.available() > 0) {

    R = Serial.read();  //Read data from Bluetooth receiver

    if (R == 'F') { //When we receive F we call the bot to move forward
      //Right Motor
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      analogWrite(6, 150);
      //Left Motor
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(5, 150);
    }
    if (R == 'B') { //When we receive B we call the bot to move backward
      //Right Motor
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      analogWrite(6, 150);
      //Left Motor
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      analogWrite(5, 150);
    }
    if (R == 'R') { //When we receive R we call the bot to move right
      //Right Motor
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      //Left Motor
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(5, 100);
    }
    if (R == 'L') { //When we receive L we call the bot to move left
      //Right Motor
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      analogWrite(6, 100);
      //Left Motor
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      analogWrite(5, 150);
    }

  }

}
