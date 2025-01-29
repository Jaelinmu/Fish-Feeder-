#include <DS3231.h>
#include <Wire.h>
#include <time.h>
#include <Servo.h>

Servo myservo;

int stop = 90;
DS3231 myRTC;

bool h12;
bool hPM;

byte theHour;
byte theMinute;
byte theSecond;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  myservo.attach(2);
  myservo.write(stop);
  myRTC.setHour(1);
  myRTC.setMinute(37);
  myRTC.setClockMode(false);

}

void loop() {
  theHour = myRTC.getHour(h12, hPM);
  theMinute = myRTC.getMinute();
  theSecond = myRTC.getSecond();
  Serial.println(theHour);
  Serial.print(theMinute);
  Serial.print(theSecond);

  if (theHour == 1 && theMinute == 38){
    myservo.write(180);
    delay (5000);
    myservo.write(stop);
    delay (5000);
  }
  else {
      myservo.write(stop);
  }
}
