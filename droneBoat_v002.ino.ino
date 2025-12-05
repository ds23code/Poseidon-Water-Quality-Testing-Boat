#define enable 9 
#define input1 4
#define input2 5

#define neutralHiBound 550
#define neutralLoBound 470
#define stallPoint 70

int throttle = 0;

void setup() {
  Serial.begin(115200);
  pinMode(enable, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT); 

}

void loop() {

   //Throttle Control:
  int joystick = analogRead(A0);

  // reverse:
  if (joystick < neutralLoBound){
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
    throttle = map(joystick, neutralLoBound, 0, 0, 255);
  }

  else if (joystick > neutralHiBound){
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    throttle = map(joystick, neutralHiBound, 1023, 0, 255);
  }

  // cut motor when torque insufficient:
  if (throttle < stallPoint){
    throttle = 0;
  }

    //CONSOLE READOUT:
    Serial.print(throttle);
    Serial.print("\n");

  analogWrite(enable, throttle);



}
