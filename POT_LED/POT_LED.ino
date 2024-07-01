#define POT_Pin A3
#define LED_PIN 9
int potVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(POT_Pin);
  analogWrite(LED_PIN,map(potVal,0,1023,0,255));
}
