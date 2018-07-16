 //import servo library for controls
#include <Servo.h>

//create servo objects
Servo pinky;
Servo ring;
Servo middle;
Servo pointer;
Servo thumb;

//tells arduino which analog input pin to measure flex from
const int pinkypin = 0;
const int ringpin = 1;
const int middlepin = 2;
const int pointerpin = 3;
const int thumbpin = 4;

void setup() {
  //use serial monitor to debug
  Serial.begin(9600);

  //enable control of servos on digital pins

  pinky.attach(11);
  ring.attach(10);
  middle.attach(9);
  pointer.attach(5);
  thumb.attach(3);
}

void loop() {
  //set up values you want to read as integers
  int flexpinky; //input value from analog pin
  int servopinky; //output value to servo
  int flexring;
  int servoring;
  int flexmiddle;
  int servomiddle;
  int flexpointer;
  int servopointer;
  int flexthumb;
  int servothumb;

  //assign values to ints
  flexpinky = analogRead(pinkypin);
  flexring = analogRead(ringpin);
  flexmiddle = analogRead(middlepin);
  flexpointer = analogRead(pointerpin);
  flexthumb = analogRead(thumbpin);

  //need to map range of analogRead() to servo's range of 0-180 degrees
  //flex sensors are typically within 200-600 range
  servopinky = map(flexpinky, 225, 300, 180, 0);//for pinky, turns flex range 200 to 500 into range 180 to 0
  servopinky = constrain(servopinky, 0, 180); //limits servo range to 0-180 degrees
  servoring = map(flexring, 200, 275, 270, 0);
  servoring = constrain(servoring, 0, 270);
  servomiddle = map(flexmiddle, 125, 200, 180, 0);
  servomiddle = constrain(servomiddle, 0, 180);
  servopointer = map(flexpointer, 250, 325, 180, 0);
  servopointer = constrain(servopointer, 0, 180);
  servothumb = map(flexthumb, 200, 300, 180, 0);
  servothumb = constrain(servothumb, 0, 180);

//servo controls
  pinky.write(servopinky);
  ring.write(servoring);
  middle.write(servomiddle);
  pointer.write(servopointer);
  thumb.write(servothumb);

  //print values to debug
    Serial.print("flexpinky: ");
    Serial.print(flexpinky);
    Serial.print("servopinky: ");
    Serial.println(servopinky);

    Serial.print("flexring: ");
    Serial.print(flexring);
    Serial.print("servoring: ");
    Serial.println(servoring);

    Serial.print("flexmiddle: ");
    Serial.print(flexmiddle);
    Serial.print("servomiddle: ");
    Serial.println(servomiddle);

    Serial.print("flexpointer: ");
    Serial.print(flexpointer);
    Serial.print("servopointer: ");
    Serial.println(servopointer);

    Serial.print("flexthumb: ");
    Serial.print(flexthumb);
    Serial.print("servothumb: ");
    Serial.println(servothumb);
}