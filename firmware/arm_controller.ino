#include <Servo.h>

Servo servo1;
const int servo1PotPin = A0;
const int servo1Pin = 7;
int servo1Value;

Servo servo2;
const int servo2PotPin = A1;
const int servo2Pin = 6;
int servo2Value;

Servo servo3;
const int servo3PotPin = A2;
const int servo3Pin = 5;
int servo3Value;

Servo servo4;
const int servo4PotPin = A3;
const int servo4Pin = 3;
int servo4Value;

Servo servo5;
const int servo5PotPin = A4;
const int servo5Pin = 4;
int servo5Value;

Servo servo6;
const int servo6buttonPin = 13;
const int servo6Pin = 2;
int pushButton;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  servo5.attach(servo5Pin);
  servo6.attach(servo6Pin);
}

void loop() {
  // Servo 1
  servo1Value = analogRead(servo1PotPin);
  servo1Value = map(servo1Value, 1023, 0, 0, 180);
  servo1.write(servo1Value);
  Serial.print(servo1Value);

  // Servo 2
  servo2Value = analogRead(servo2PotPin);
  servo2Value = map(servo2Value, 0, 1023, 0, 180);
  servo2.write(servo2Value);
  Serial.print(" "); Serial.print(servo2Value);

  // Servo 3
  servo3Value = analogRead(servo3PotPin);
  servo3Value = map(servo3Value, 0, 1023, 0, 180);
  servo3.write(servo3Value);
  Serial.print(" "); Serial.print(servo3Value);

  // Servo 4
  servo4Value = analogRead(servo4PotPin);
  servo4Value = map(servo4Value, 0, 1023, 0, 180);
  servo4.write(servo4Value);
  Serial.print(" "); Serial.print(servo4Value);

  // Servo 5
  servo5Value = analogRead(servo5PotPin);
  servo5Value = map(servo5Value, 0, 1023, 0, 180);
  servo5.write(servo5Value);
  Serial.print(" "); Serial.print(servo5Value);

  // Servo 6 (Gripper Push Button Control)
  pushButton = digitalRead(servo6buttonPin);
  if (pushButton == LOW) {
    servo6.write(0);
    Serial.print(" "); Serial.print("Close");
  } else {
    servo6.write(45);
    Serial.print(" "); Serial.println("Open");
  }

  delay(5);
}