#define IR_Pin 2  
int sensorValue = 0;      

void setup() {
  Serial.begin(9600);      
  pinMode(IR_Pin, INPUT); 
}

void loop() {
  sensorValue = digitalRead(IR_Pin); 
  Serial.println(IR_Pin);          
  delay(500);                           
}
