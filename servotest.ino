#include <DS3231.h>
#include <Wire.h>
#include <time.h>
#include <Servo.h>

Servo myservo;
DS3231 myRTC;

int stop = 90;

// clock setup

byte theHour;
byte theMinute;
byte theSecond;

// alarm setup 

bool alarmH12;
byte alarmHour;
bool alarmPM;
byte alarmMinute;
byte alarmBits;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  myservo.attach(2);
  myservo.write(stop);
  myRTC.setHour(1);
  myRTC.setMinute(37);
  myRTC.setClockMode(false);

  // alarm setup

  alarmH12 = false; // 24 hr format (true for 12hr)
  alarmHour = 13; // alarm hour
  alarmMinute = 38; // alarm minute
  alarmBits = 0b00001110; // this allows our alarm to function during the exact hour and minute (i think)

  myRTC.setA1Time(0, alarmHour, alarmMinute, alarmBits, alarmH12, alarmPM); // sets alarm
  myRTC.turnOnAlarm(1); // turns alarm on :D
  // i think this allows it so our alarm will activate everyday but not sure lol

}

void loop() {
  theHour = myRTC.getHour(alarmH12);
  theMinute = myRTC.getMinute();
  theSecond = myRTC.getSecond();
  
  // nice time output
  char time_buffer[20];
  sprintf(time_buffer, "Time: %02d:%02d:%02d", theHour, theMinute, theSecond);
  Serial.println(time_buffer);

  if (myRTC.checkIfAlarm(1)) {
    myservo.write(100);
    delay(5000);
    myservo.write(stop);
    delay(5000);

    myRTC.clearAlarm(1); // bascially turns off alarm so it wont repeat
  }

  /*
   * old condiiton:
   *
   * if (theHour == 1 && theMinute == 38){
   *    myservo.write(180);
   *    delay (5000);
   *    myservo.write(stop);
   *    delay (5000);
   * }
   * else {
   *    myservo.write(stop);
   * }
   *
   */

  delay(1000);

}




