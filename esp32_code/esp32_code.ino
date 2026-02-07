#include "Wire.h"
#include "Adafruit_TCS34725.h"
#include "RTClib.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_600MS, TCS34725_GAIN_4X);
RTC_DS1307 rtc;

uint16_t r,g,b,c;
float blue_ratio;

int led1 = 25;
int led2 = 26;
int led3 = 27; 


void setup() {
  ledcAttach(led1,5000,8);
  ledcAttach(led2,5000,8);
  ledcAttach(led3,5000,8);
  Serial.begin(115200);
  Wire.begin(21,22);

  if (tcs.begin() && rtc.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("check your connections");
    while (1);
  }

}

void loop() {
  tcs.getRawData(&r, &g, &b, &c);
  uint32_t total= r+g+b;
  int blue_ratio = ((float)b/total)*100;
  int blue_pwm_ava = map(blue_ratio,0,100,10,250);
  int blue_pwm_req = 0;
  DateTime now = rtc.now();
  int hour = now.hour();

  if(hour==4){
    blue_pwm_req = 0;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
  }

  else if(hour==5){
    blue_pwm_req = 5;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else if(hour==6){
    blue_pwm_req = 20;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else if(hour==7 || hour==8){
    blue_pwm_req = 70;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else if(hour==9 ||hour==10 || hour==11){
    blue_pwm_req = 30;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else if(hour==12 || hour==13){
    blue_pwm_req = 120;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else if(hour==14 || hour==15){
    blue_pwm_req = 80;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else if(hour==16 || hour==17){
    blue_pwm_req = 90;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else if(hour==18 || hour==19){
    blue_pwm_req = 10;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  else {
    blue_pwm_req = 0;
    if(blue_pwm_ava>=blue_pwm_req){
      Serial.println("No Need...");
      ledcWrite(led1,0);
      ledcWrite(led2,0);
      ledcWrite(led3,0);
    }
    else{
      ledcWrite(led1,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led2,blue_pwm_req-blue_pwm_ava);
      ledcWrite(led3,blue_pwm_req-blue_pwm_ava);
    }
  }

  Serial.print("Blue parameter:");Serial.print(blue_ratio);Serial.print(",");Serial.println(blue_pwm_ava);
  Serial.println(hour);
  delay(1000);

  

}
