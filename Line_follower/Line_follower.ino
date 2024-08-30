#define EN_R 6
#define IN_1 7
#define IN_2 8
#define EN_L 5
#define IN_3 4
#define IN_4 3
 
#define IR_M 13
#define IR_R 11
#define IR_L 12
#define Speed 180

int flag;

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

void Break ()
{
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,HIGH);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,HIGH);
  
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
  delay(1000);
  flag=0;
  TCCR0B = TCCR0B & B11111000 | B00000010 ;

}

// the loop function runs over and over again forever
void loop() {
  while(flag==0)
  {
    if(digitalRead(IR_M) == 1 && digitalRead(IR_L)==0 && digitalRead(IR_R)==0) // middle sensor=1, left and right=0 ; move forward
    {
      Serial.println("for");
      Forward(Speed);
    }
    else if( digitalRead(IR_L)==1 && digitalRead(IR_R)==0) //Left sensor=1, middle and right=0 ; turn left
    {
      Serial.println("left");
      Left(Speed-10);
    }
    else if( digitalRead(IR_L)==0 && digitalRead(IR_R)==1) //Right sensor=1, middle and left=0 ; turn right
    {
      Serial.println("right");
      Right(Speed-10);
    }
    else if (digitalRead(IR_M) == 1 && digitalRead(IR_L)==1 && digitalRead(IR_R)==1)
    {
      Serial.println("stop");
      Break();
      delay(2000);
      Forward(Speed);
      delay(200);
    }

    else if(digitalRead(IR_M) == 0 && digitalRead(IR_L)==1 && digitalRead(IR_R)==1) //middle sensor=0, left and right=1 ; finish
    {
      Serial.println("finish");
      Break();
      flag=1;
    }
    //else Break();
  }

}
