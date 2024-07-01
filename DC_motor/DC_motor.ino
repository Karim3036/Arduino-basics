#define EN  6
#define IN1 8
#define IN2 9

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN, OUTPUT);
}

void loop() {
  analogWrite(EN,128);
  // Move motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000); // Run for 2 seconds

  // Stop motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000); // Stop for 1 second
  analogWrite(EN,255);
  // Move motor backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000); // Run for 2 seconds

  // Stop motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000); // Stop for 1 second
}