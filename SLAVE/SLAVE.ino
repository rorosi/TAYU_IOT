#include <SoftwareSerial.h>

const int buttonPin = 5;
int Switch1 = 8; // switch를 9번 pin으로 설정
int Switch3 = 10; // switch를 9번 pin으로 설정

SoftwareSerial mySerial(3, 2); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(Switch1,OUTPUT);     // 스위치를 입력으로 설정
  pinMode(Switch3,OUTPUT);     // 스위치를 입력으로 설정
  Serial.begin(9600);
  mySerial.begin(9600); // baud rate 9600으로 설정
}



void loop() {
 
  char left;
  char middle;
  char right;
  char neutrality;


   if ( digitalRead(buttonPin) == 0 ) { 
     middle = '2';
     mySerial.println(middle);
     delay(700);
 } else if ( digitalRead(Switch1) == 1) { 
     left = '1';
     Serial.println(left);
     mySerial.println(left);
     delay(700);
 } else if ( digitalRead(Switch3) == 1) { 
     right = '3';
     Serial.println(right);
     mySerial.println(right);
     delay(700);
 } else {
     neutrality = '0';
     mySerial.println(neutrality);
     delay(100);
 }
} 
