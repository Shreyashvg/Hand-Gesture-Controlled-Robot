#include "BluetoothSerial.h"
#include <String.h>
BluetoothSerial SerialBT;


String dir;

int dir1 = 16; //32
int leftfront = 17; //21

int dir2 = 25; //33
int rightfront = 26; //19

int dir3 = 14; //25
int leftback = 27; //18

int PWM = 150;
int count1 = 800;


const int freq = 5000;
const int res = 8;

const int ledChannel0 = 0;
const int ledChannel1 = 1;
const int ledChannel2 = 2;
const int ledChannel3 = 3;
const int ledChannel4 = 4;

const int resolution = 8;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP329"); // Set the name of this device

  pinMode(dir1, OUTPUT);   //FOR MOTOR
//  ledcSetup(ledChannel0, freq, resolution);
//  ledcAttachPin(leftfront, ledChannel0);
  ledcAttach(leftfront,freq,res);


  pinMode(dir2, OUTPUT);
//  ledcSetup(ledChannel1, freq, resolution);
//  ledcAttachPin(rightfront, ledChannel1);
  ledcAttach(rightfront,freq,res);  


  pinMode(dir3, OUTPUT);
//  ledcSetup(ledChannel2, freq, resolution);
//  ledcAttachPin(leftback, ledChannel2);
  ledcAttach(leftback,freq,res);

  Serial.println("Finished Setup");
}

void loop() {
//  dir = "stop";

  if (SerialBT.available()) {
    dir = SerialBT.readStringUntil('\n');
    Serial.println(dir);
  }

//  if (Serial.available()){
//    dir = Serial.readStringUntil('\n');
//    Serial.println(dir);
//  }
  
  if (dir == "forward") {

      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(leftfront, PWM);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(rightfront, PWM);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(leftback, 0);
      
      Serial.println("hello");
    }
    else if (dir == "back") {
      digitalWrite(dir1, LOW);        //LEFT MOTOR 137
      ledcWrite(leftfront, PWM);

      digitalWrite(dir2, LOW);        //LEFT MOTOR 137
      ledcWrite(rightfront, PWM);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(leftback, 0);
    }
    else if (dir == "left") {

      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(leftfront, PWM - 70);

      digitalWrite(dir2, LOW);        //LEFT MOTOR 137
      ledcWrite(rightfront, PWM - 30);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(leftback, PWM + 38);

    }
    else if (dir == "right") {
      digitalWrite(dir1, LOW);        //LEFT MOTOR 137
      ledcWrite(leftfront, PWM - 70);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(rightfront, PWM - 30);

      digitalWrite(dir3, LOW);        //LEFT MOTOR 137
      ledcWrite(leftback, PWM + 38);
    }
    else if (dir == "rotate") {

      digitalWrite(dir1, LOW);       //LEFT MOTOR 137
      ledcWrite(leftfront, PWM);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(rightfront, PWM);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(leftback, PWM);
    }
    else if (dir == "stop") {

      digitalWrite(dir1, LOW);       //LEFT MOTOR 137
      ledcWrite(leftfront, 0);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(rightfront, 0);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(leftback, 0);
    }
//  else {
//    digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
//    ledcWrite(0, 0);
//
//    digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
//    ledcWrite(1, 0);
//
//    digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
//    ledcWrite(2, 0);
//  }
}
