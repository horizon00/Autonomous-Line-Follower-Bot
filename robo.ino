/*
Connections:
Arduino Vin – 12v. + or you can use connecting plug(after uploading program)
IR Vcc – 5v Arduino
IR Gnd -Arduino Gnd
Motor driver Vcc – 12v.+
Motor driver Gnd – 12v.-
Gnd of Arduino & Motor driver must be made common
IR 1 o/p – pin 6
IR 2 o/p – pin 7
Motor Driver IN1 – pin 8
Motor Driver IN2 – pin 9
Motor Driver IN3 – pin 10
Motor Driver IN4 – pin 11
Motor 1 – O/P-1 & O/P-2 of Motor Driver
Motor 2 – O/P-3 & O/P-4 of Motor Driver
///////////////////////////////////////////////////////////////
For any queries, mail us at: support@niltech.in*/void setup() {

Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(12,OUTPUT); /* 4 output pins for 2 Motors*/
pinMode(6,INPUT);
pinMode(7,INPUT); /* 2 input pins for 2 IR sensors*/
}

void loop()

{

int x = digitalRead(6); /* Storing state of IR 1 at pin 6 in a variable ‘x’*/
int y = digitalRead(7); /* Storing state of IR 1 at pin 7 in a variable ‘y’*/
if(x==HIGH && y == HIGH ) /* If both IR are high, only this condition will be executed*/
{

Serial.println("X");
digitalWrite(10,LOW);
digitalWrite(8,LOW);
digitalWrite(12,LOW);
digitalWrite(9,LOW); /* all terminals are low, stopping both motors*/
}

else

{ /* if both IRs are not high then these conditionswill be checked and executed*/

if (x==HIGH) /* if IR 1 is high*/
{
digitalWrite(10,LOW);

digitalWrite(12,HIGH);
delay(1);
digitalWrite(12,LOW); /* Motor 1 rotating in forward direction*/
delay(1); /* Delays can be modified to manipulate the speed of motor*/

}

if (x==LOW) /* if IR 2 is low*/
{
digitalWrite(10,HIGH);
delay(1);
digitalWrite(10,LOW); /* Motor 1 rotating in reverse direction*/
delay(1); /* Delays can be modified to manipulate the speed of motor*/

digitalWrite(12,LOW);

}

if (y==HIGH) /* if IR 2 is high*/
{
digitalWrite(8,LOW);digitalWrite(9,HIGH);
delay(1);
digitalWrite(9,LOW); /* Motor 2 rotating in forward direction*/
delay(1); /* Delays can be modified to manipulate thespeed of the motor*/

}

if (y==LOW ) /* if IR 2 is low*/
{
digitalWrite(8,HIGH);
delay(1);
digitalWrite(8,LOW); /* Motor 2 rotating in reverse direction */
delay(1); /* Delays can be modified to manipulate thespeed of the motor*/

digitalWrite(9,LOW);
}

}

}
