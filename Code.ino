Internal architecture:
Code:
//#include<SoftwareSerial.h> //SoftwareSerial bt(10,11); /* RX,TX */ const int trigPin = 12;
const int echoPin = 13;
const int buzzer = 7;
const int buzzer_gnd = 4;
const int blue_v = 8;
const int blue_gnd = 9;
int flag=0;
void setup() {
pinMode(buzzer, OUTPUT); pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT); pinMode(buzzer_gnd,OUTPUT); pinMode(blue_v,OUTPUT); pinMode(blue_gnd,OUTPUT);
// bt.begin(38400); Serial.begin(9600);
}
 void loop() { digitalWrite(blue_v,HIGH); digitalWrite(buzzer_gnd,LOW); digitalWrite(blue_gnd,LOW); long duration,cm;
int s;
int b;
Serial.println("Enter password"); while(Serial.available()==0)
{}
s=Serial.read();
if(s="777") {
while(true) {
// The sensor is triggered by a HIGH pulse of 10 or more microseconds. // Give a short LOW pulse beforehand to ensure a clean HIGH pulse: digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);

 delayMicroseconds(10); digitalWrite(trigPin, LOW);
// Read the signal from the sensor: a HIGH pulse whose // duration is the time (in microseconds) from the sending // of the ping to the reception of its echo off of an object. pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
// convert the time into a distance
cm = microsecondsToCentimeters(duration);
if(cm<=30)
{
delay(150); digitalWrite(buzzer,HIGH); delay(9*cm); digitalWrite(buzzer,LOW); }
else
{
digitalWrite(buzzer,LOW); }
if(Serial.available()!=0) {

b=Serial.read(); if(b="777") break;
}
}
}
}
long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the object we // take half of the distance travelled.
return microseconds/ 29 / 2;
}
