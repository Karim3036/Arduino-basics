#define LED_PIN 9
#define Button_PIN 10

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_PIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(Button_PIN, INPUT);  //pulldown
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(LED_PIN, HIGH);
  } else {
    // turn LED off:
    digitalWrite(LED_PIN, LOW);
  }
}
