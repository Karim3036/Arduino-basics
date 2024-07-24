#define EN_R 3
#define IN_1 2
#define IN_2 4
#define EN_L 6
#define IN_3 5
#define IN_4 7
 
#define IR_M 8
#define IR_R 9
#define IR_L 10
// 1 black
// 0 white

#define trig 11
#define echo 12

float distance,duration;

void Forward(int speed)
{   // Right wheel forward
    analogWrite(EN_R,speed);
    digitalWrite(IN_1,HIGH);
    digitalWrite(IN_2,LOW);

    // Left wheel forward
    analogWrite(EN_L,speed);
    digitalWrite(IN_3,HIGH);
    digitalWrite(IN_4,LOW);
    
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
}

void Stop ()
{
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,LOW);
  
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
  
  Serial.begin(9600);
  pinMode(EN_R, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(EN_L, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  
  pinMode(IR_M, INPUT);
  pinMode(IR_R, INPUT);
  pinMode(IR_L, INPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

// the loop function runs over and over again forever
void loop() {
  
  while (Ultra_distance <= 20) //ultrasonic reads less than 15 cm
  {
    if(IR_M == 1 && IR_L==0 && IR_R==0) // middle sensor=1, left and right=0 ; move forward
    {
      Forward(128);
    }
    else if(IR_M == 0 && IR_L==1 && IR_R==0) //Left sensor=1, middle and right=0 ; turn left
    {
      Left(128);
    }
    else if(IR_M == 0 && IR_L==0 && IR_R==1) //Right sensor=1, middle and left=0 ; turn right
    {
      Right(128);
    }
    else if(IR_M == 0 && IR_L==1 && IR_R==1) //middle sensor=0, left and right=1 ; stop
    {
      Stop();
    }
    
  }
}
