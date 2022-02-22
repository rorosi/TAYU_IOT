#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN1             8  //left
#define PIN2             9  // middle
#define PIN3            10  // right
#define NUMPIXELS      10// 제가 사용할 제품이 1미터에 60개짜리 제품이라 제어할 LED는 60 개
#define NUMPIXELS2      7// 제가 사용할 제품이 1미터에 60개짜리 제품이라 제어할 LED는 60 개

SoftwareSerial mySerial(3, 2); //블루투스의 Tx, Rx핀을 2번 3번핀으로 설정
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS2, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS2, PIN3, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(9600);

  mySerial.begin(9600); // baud rate 9600으로 설정
  pinMode(PIN2, OUTPUT);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0)); 
  
  pixels.begin(); // This initializes the NeoPixel library.
  pixels2.begin();
  pixels3.begin();

}

void loop() { 
   if (mySerial.available()) { // 넘어온 데이터가 존재하면
      char data = (char)mySerial.read();
      Serial.print(data);
      if(data == '2'){
            for(int i=0;i<NUMPIXELS2;i++){ //왼쪽
              int randR = 255; 
              int randG = 0; 
              int randB = 0;
    
    
              pixels.setPixelColor(i, pixels.Color(randR,randG,randB)); // Moderately bright green color.
              pixels.show(); // This sends the updated pixel color to the hardware.

            }
            for(int i=NUMPIXELS2;i>=0;i--){
              int randR = 0; 
              int randG = 0; 
              int randB = 0;
    
              pixels.setPixelColor(i, pixels.Color(randR,randG,randB)); // Moderately bright green color.
              pixels.show(); // This sends the updated pixel color to the hardware.
            
          }
          for(int i=0;i<NUMPIXELS;i++){ //가운데
            int randR = 255; 
            int randG = 0; 
            int randB = 0;
  
            pixels2.setPixelColor(i, pixels2.Color(randR,randG,randB)); // Moderately bright green color.
            pixels2.show(); // This sends the updated pixel color to the hardware.
    
          }
          for(int i=0;i<NUMPIXELS;i++){  
            int randR = 0; 
            int randG = 0; 
            int randB = 0;
  
            pixels2.setPixelColor(i, pixels2.Color(randR,randG,randB)); // Moderately bright green color.
            pixels2.show(); // This sends the updated pixel color to the hardware.
        }
        for(int i=0;i<NUMPIXELS2;i++){  //오른쪽
            int randR = 255; 
            int randG = 0; 
            int randB = 0;
  
  
            pixels3.setPixelColor(i, pixels3.Color(randR,randG,randB)); // Moderately bright green color.
            pixels3.show(); // This sends the updated pixel color to the hardware.
  
          }
          for(int i=NUMPIXELS2;i>=0;i--){
            int randR = 0; 
            int randG = 0; 
            int randB = 0;
  
            pixels3.setPixelColor(i, pixels3.Color(randR,randG,randB)); // Moderately bright green color.
            pixels3.show(); // This sends the updated pixel color to the hardware.
        }
      }
      
      else if(data == '1'){
          for(int i=-1;i<NUMPIXELS2;i++){
            int randR = 255; 
            int randG = 0; 
            int randB = 0;
  
  
            pixels.setPixelColor(i, pixels.Color(randR,randG,randB)); // Moderately bright green color.
            pixels.show(); // This sends the updated pixel color to the hardware.
            delay(100);
          }
          for(int i=NUMPIXELS2;i>=0;i--){
            int randR = 0; 
            int randG = 0; 
            int randB = 0;
  
            pixels.setPixelColor(i, pixels.Color(randR,randG,randB)); // Moderately bright green color.
            pixels.show(); // This sends the updated pixel color to the hardware.
        }
      }
      else if(data == '3'){
          for(int i=0;i<NUMPIXELS2;i++){
            int randR = 255; 
            int randG = 0; 
            int randB = 0;
  
  
            pixels3.setPixelColor(i, pixels3.Color(randR,randG,randB)); // Moderately bright green color.
            pixels3.show(); // This sends the updated pixel color to the hardware.
            delay(100);
          }
          for(int i=NUMPIXELS2;i>=0;i--){
            int randR = 0; 
            int randG = 0; 
            int randB = 0;
  
            pixels3.setPixelColor(i, pixels3.Color(randR,randG,randB)); // Moderately bright green color.
            pixels3.show(); // This sends the updated pixel color to the hardware.
        }  
      }
   }
}
