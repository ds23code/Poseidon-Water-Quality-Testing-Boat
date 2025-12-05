#include <Servo.h> 

#define joystick_X A3
#define SERVO_ROT_SPEED 5

Servo rudder;
int currentDir = 90;

void setup() {
  Serial.begin(115200);
  rudder.attach(10);

}

void loop() {

  int joyXInput = analogRead(joystick_X);
  int rudderDir = map(joyXInput, 0, 1023, 0, 180);
  Serial.println (rudderDir);
  currentDir = turnRudder(currentDir, rudderDir);

  //rudder.write(rudderDir);
  delay(1000);
}

int turnRudder(int currentDir, int finalDir){
  if (finalDir > currentDir){
    while (finalDir > currentDir){
      currentDir += 1;
      delay(SERVO_ROT_SPEED);
      rudder.write(currentDir);
    }
  }

  else if (finalDir < currentDir){
    while (finalDir < currentDir){
      currentDir -= 1;
      delay(SERVO_ROT_SPEED);
      rudder.write(currentDir);
    }
  }
  return currentDir;
}
