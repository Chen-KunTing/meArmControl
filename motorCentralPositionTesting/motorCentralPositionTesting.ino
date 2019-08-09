//define motor pin
#define motorPin 5

//define led pin
#define ledPin 13

int inComingByte = 0;
int motorPosition = 127;
int tempPosition = 127;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  readSerialToInt();
  if (tempPosition != 0) {
    Serial.print("PWM is setting to : ");
    Serial.print(tempPosition);
    Serial.println("");
    sendCommand(tempPosition);
  }

  delay(100);
}

void readSerialToInt() {
  tempPosition = 0;
  while (Serial.available() > 0) {
    inComingByte = Serial.read();

    if (inComingByte == 10)
      return;
    else if (inComingByte >= 0x30 && inComingByte <= 0x39) {
      tempPosition *= 10;
      tempPosition += (inComingByte - 0x30);
    }
    else if (inComingByte == 0x2B)
      tempPosition += 5;
    else if (inComingByte == 0x2D)
      tempPosition -= 5;
  }

}

void sendCommand(int comPosition) {
  while (comPosition != motorPosition) {
    if (comPosition > motorPosition)
      motorPosition++;
    else
      motorPosition--;
      
    analogWrite(motorPin, motorPosition);
    delay(20);
  }
}
