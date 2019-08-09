
//define motor pin
int motor[3] = {5, 6, 7};
int motorPosition[3] = {127, 127, 127};
bool motorCW[3] = {true, true, true};
int ledport = 13;
bool ledOn = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor[0], OUTPUT);
  pinMode(motor[1], OUTPUT);
  pinMode(motor[2], OUTPUT);
  pinMode(ledport, OUTPUT);
  delay(100);

  analogWrite(motor[0], motorPosition[0]);
  analogWrite(motor[1], motorPosition[1]);
  analogWrite(motor[2], motorPosition[2]);
  Serial.begin(9600);
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motor[0], motorPosition[0]);
  digitalWrite(ledport, ledOn);
  Serial.print("motor position: ");
  Serial.println(motorPosition[0]);
  ledOn = !ledOn;
  
  if (motorCW[0]) {
    if (motorPosition[0] < 187)
      motorPosition[0] += 1;
    else
      motorCW[0] = false;
  }
  else {
    if (motorPosition[0] > 67)
      motorPosition[0] -= 1;
    else
      motorCW[0] = true;
  }

  delay(50);
}
