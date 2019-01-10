int middle = A1;            // select the input pin for the ldr
int right = A2;
int left = A0;
int timer = 0;
int led1 = 4;
int led2 = 2;
int led3 = 3;
unsigned int SM = 0;
unsigned int SR = 0;
unsigned int SL = 0;
//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293

void setup() {
  Serial.begin(9600);
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}

void drive(int dir) //1 = straight, 2 = right, 3 = left
{
  if (dir == 1) //straight
  {
  analogWrite(motorPin1, 100);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 100);
  analogWrite(motorPin4, 0);
  }
  else if (dir == 2) //right
  {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 100);
  analogWrite(motorPin3, 100);
  analogWrite(motorPin4, 0);
  }
  else if (dir == 3) //left
  {
    analogWrite(motorPin1, 100);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 100);
  }
}

void loop() {
  SM = analogRead(middle);
  SR = analogRead(right);
  SL = analogRead(left);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  // put your main code here, to run repeatedly:
  if (SM < 600)
  {
    if (SL < 600)
    {
      if (SR < 600)
      {
        drive(2);
      }
      else
      {
        drive (1);
//        delay (10);
//        if (SM < 400)
//        {
//          drive (1);
//        }
//        else
//        {
//          drive (3);
//        }
      }
     }
     else
     {
      if (SR < 600)
      {
        drive (2);
      }
      else
      {
        drive(1);
      }
     }
    }
    else
    {
      if (SL < 600)
      {
       if (SR < 600)
       {
        drive(2);
       }
       else
       {
        drive(3);
       } 
      }
      else
      {
//        drive(2);
        if (SR < 600)
        {
          drive(2);
          //Serial.print("RIGHT\n");
        }
        else if (SR < 620)
        {
          drive(1);
          //Serial.print("STRAIGHT\n");
        }
        else
        {
          drive (3);
          //Serial.print("LEFT\n");
        }
      }
    }
Serial.print(SR);     // print the value (0 to 1024)
  Serial.println("");
}

