#define RED_LED_PIN 7
#define YELLOW_LED_PIN 8 
#define GREEN_LED_PIN 9 

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(GREEN_LED_PIN, HIGH); 
  delay(1000);                      
  digitalWrite(GREEN_LED_PIN, LOW);   
  digitalWrite(YELLOW_LED_PIN, HIGH); 
  delay(1000);                      
  digitalWrite(YELLOW_LED_PIN, LOW);  
  digitalWrite(RED_LED_PIN, HIGH); 
  delay(1000);                      
  digitalWrite(RED_LED_PIN, LOW);                   
}
