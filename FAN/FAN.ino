#define PB1 3 //off
#define PB2 4 //Speed 1
#define PB3 5 //Speed 2
#define PB4 6 //backward
#define IN1 7 
#define IN2 8
#define EN  9


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(PB1, INPUT);
  pinMode(PB2, INPUT);
  pinMode(PB3, INPUT);
  pinMode(PB4, INPUT);
}

void loop() {  

  if (digitalRead(PB1)) //stop
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  else if (digitalRead(PB2)) //Speed 1
  {
    analogWrite(EN,128);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else if (digitalRead(PB3)) //Speed 2
  {
    analogWrite(EN,255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else if (digitalRead(PB4)) //backward
  {
    analogWrite(EN,255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
}
