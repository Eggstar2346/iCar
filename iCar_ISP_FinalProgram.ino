//Name: Jennifer Huynh, Naomi Kothiyal, Esther Yoo
//Teacher: Mr Wong
//Date: Submitted Tuesday January 17 2017
//Purpose: This program was uploaded into our iCar so it could navigate a maze. It codes to make it go left, right, or straight according to specific scenarios.

//Initializinng our variables
//Assigning analog pins to our three sensors
int middle = A1;
int right = A2;
int left = A0;
//Asigning pins to our 3 LEDs
int led1 = 4;
int led2 = 2;
int led3 = 3;
//Initializing the variables that are read from the sensors
unsigned int SM = 0; //middle LDR
unsigned int SR = 0; //right LDR
unsigned int SL = 0; //left LDR
//Assigning pins to our motors
//Right motor
const int motorPin1 = 5;
const int motorPin2 = 6;
//Left motor
const int motorPin3 = 10;
const int motorPin4 = 9;

//This function sets the output pins
void setup ()
{
    //Setting motor pins
    pinMode (motorPin1, OUTPUT);
    pinMode (motorPin2, OUTPUT);
    pinMode (motorPin3, OUTPUT);
    pinMode (motorPin4, OUTPUT);
    //Setting LED pins
    pinMode (led1, OUTPUT);
    pinMode (led2, OUTPUT);
    pinMode (led3, OUTPUT);
}

//This function sends signals to the motor pins in a way so the car moves straight, right, and left.
//The value in the analogWrite sets the speed of the motor.
//The parameter 'dir' is used to determine which motors are HIGH and LOW.
void drive (int dir)
{
    if (dir == 1) //move straight
    {
        analogWrite (motorPin1, 100);
        analogWrite (motorPin2, 0);
        analogWrite (motorPin3, 100);
        analogWrite (motorPin4, 0);
    }


    else if (dir == 2) //move right
    {
        analogWrite (motorPin1, 0);
        analogWrite (motorPin2, 100);
        analogWrite (motorPin3, 100);
        analogWrite (motorPin4, 0);
    }


    else if (dir == 3) //move left
    {
        analogWrite (motorPin1, 100);
        analogWrite (motorPin2, 0);
        analogWrite (motorPin3, 0);
        analogWrite (motorPin4, 100);
    }
}

//This function is the main loop for navigating the maze.
//It calls the method 'drive()' with different parameters depending on the sensor values.
void loop ()
{
    //Assigning new sensor values to each LDR every time the loop runs
    SM = analogRead (middle);
    SR = analogRead (right);
    SL = analogRead (left);
    //The LEDs are always on
    digitalWrite (led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, HIGH);

    if (SM < 600)
    {
        if (SL < 600)
        {
            if (SR < 600)
            {
                //If MIDDLE, LEFT, and RIGHT sensors are sensing, go RIGHT
                drive (2);
            }
            else
            {
                //if MIDDLE and LEFT sensors are sensing, go STRAIGHT
                drive (1);
            }
        }
        else
        {
            if (SR < 600)
            {
                //If MIDDLE and RIGHT sensors are sensing, go RIGHT
                drive (2);
            }
            else
            {
                //If MIDDLE sensor is sensing, go STRAIGHT
                drive (1);
            }
        }
    }


    else
    {
        if (SL < 600)
        {
            if (SR < 600)
            {
                //If LEFT and RIGHT sensors are sensing, go RIGHT
                drive (2);
            }
            else
            {
                //If LEFT sensor is sensing, go LEFT
                drive (3);
            }
        }
        else
        {
            if (SR < 600)
            {
                //If RIGHT sensor is sensing, go RIGHT
                drive (2);
            }
            else if (SR < 620)
            {
                //Drives straight to avoid adjustment loop bug
                drive (1);
            }
            else
            {
                //If NONE of the sensors are sensing, go LEFT
                drive (3);
            }
        }
    }
}

