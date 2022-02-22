#include <SoftwareSerial.h>

#include <Servo.h>

#define shk 5

#define buzzer 3

 

Servo servo; 

SoftwareSerial hc06(7,8); //Tx, Rx

int servoPin = 11;

int min_value = 544;

int max_value = 2400;

int angle = 0;

int shock = 0;

void setup() {

  Serial.begin(9600);

  hc06.begin(9600);

  pinMode(buzzer, INPUT);

  servo.attach(servoPin);

  servo.detach();

 

}

 

void loop() {

 

  shock = digitalRead(shk);

  Serial.println(shock);

  if(hc06.available())

  {

    byte key = hc06.read();

    if(key == 1){

      servo_ON();

    }

    else if(key == 0)

      servo_OFF();

  }

  if(shock == HIGH){

    tone(buzzer, 391,2000);

  }

  else{

    noTone(buzzer);

  }

  sendPacket(shock);

  delay(1000);

 

}

 

void sendPacket(int shock)

{

    byte data[3] = {0,};

    data[0] = 0xF0;

    data[1] = (byte)shock;

    data[2] = 0xFl;

    hc06.write(data,3);

}

 

void servo_ON(){

  servo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

  servo.writeMicroseconds(1700);

  delay(1170);

  servo.detach();

}

 

void servo_OFF(){

  servo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

  servo.write(1300);

  delay(1170);

  servo.detach();

}
