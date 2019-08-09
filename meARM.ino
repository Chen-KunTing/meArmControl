
//define motor pin
int motor[3] = {5, 6, 7};
int motorPosition[3] = {127, 127, 127};
bool motorCW[3] = {true, true, true};

void setup() {
  // put your setup code here, to run once:
  pinMode(motor[0], OUTPUT);
  pinMode(motor[1], OUTPUT);
  pinMode(motor[2], OUTPUT);
  delay(100);

  analogWrite(motor[0], motorPosition[0]);
  analogWrite(motor[1], motorPosition[1]);
  analogWrite(motor[2], motorPosition[2]);
  delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motor[0], motorPosition[0]);
  delay(100);
  if (motorCW[0]) {
    if (motorPosition[0] < 250)
      motorPosition[0] += 10;
    else
      motorCW[0] = false;
  }
  else {
    if (motorPosition[0] > 5)
      motorPosition[0] -= 10;
    else
      motorCW[0] = true;
  }
}
