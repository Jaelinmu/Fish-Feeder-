#include <HCSR04.h>


// microsecond = 10^-6 (for hannah because im stupid)

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop () {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;  // this is in cm

    Serial.println("Distance: ", distance);  
    /*

    if (distance >= [some value idk]) {
        send some sort of notification to phone/app/etc
        output msg on lcd display
    }

    */

	delay(100);  


}