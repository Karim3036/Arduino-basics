#define EN_R 6
#define IN_1 7
#define IN_2 8
#define EN_L 5
#define IN_3 4
#define IN_4 3
 
#define trig 11
#define echo 12

#define Speed 180
float distance,duration;
int c=0;

void Forward(int speed)
{   // Right wheel forward
    analogWrite(EN_R,speed);
    digitalWrite(IN_1,LOW);
    digitalWrite(IN_2,HIGH);

    // Left wheel forward
    analogWrite(EN_L,speed);
    digitalWrite(IN_3,LOW);
    digitalWrite(IN_4,HIGH);
    
}


void Left(int speed)
{
  // Right wheel forward
    analogWrite(EN_R,speed);
    digitalWrite(IN_1,HIGH);
    digitalWrite(IN_2,LOW);

    // Left wheel backward
    analogWrite(EN_L,speed);
    digitalWrite(IN_3,LOW);
    digitalWrite(IN_4,HIGH);
    delay(50);
    
}


void Right(int speed)
{
  // Right wheel backward
    analogWrite(EN_R,speed);
    digitalWrite(IN_1,LOW);
    digitalWrite(IN_2,HIGH);

  // Left wheel forward
    analogWrite(EN_L,speed);
    digitalWrite(IN_3,HIGH);
    digitalWrite(IN_4,LOW);
    delay(50);
}

void Stop ()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);
  
}

void Brake ()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,HIGH);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,HIGH);
  
}

float Ultra_distance ()
{
  digitalWrite(trig,LOW);

  delayMicroseconds(2);

  digitalWrite(trig,HIGH);

  delayMicroseconds(10);

  digitalWrite(trig,LOW);

  duration=pulseIn(echo,HIGH);

  distance= (duration*0.0343)/2;

  return distance;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(EN_R, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(EN_L, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Forward(speed);
  x=0;
  while (Ultra_distance() <= 20); 
  
 Brake();

  Right(speed);
 
  delay(1000);

}





