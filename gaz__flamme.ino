

#include <Servo.h>
  #include <LiquidCrystal.h> // includes the LiquidCrystal Library 


Servo myservo;
int GAS  =2;
int flame =9;
const int buzzer =7;
int pin=3;
int delai=50;
int GAZ;
int FLA;

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
void setup() {
  // put your setup code here, to run once:
   lcd.begin(16,2); 
  pinMode(buzzer, OUTPUT); // Set buzzer as an output
 
  
Serial.begin(9600);
pinMode (flame,INPUT);
pinMode (GAS,INPUT );
pinMode (pin,OUTPUT);
myservo.attach(5);
 myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
GAZ =digitalRead(GAS);
FLA=digitalRead (flame);
if (GAZ!=LOW or FLA!=LOW)
{
  tone (buzzer,HIGH);
  Serial.println ("detection");
  digitalWrite (pin,HIGH);
  delay (delai);
  digitalWrite (pin , LOW );
 delay (delai);
    myservo.write(180);
}
else {
  noTone (buzzer);
  Serial.println ("No Gas NO Flame");
  digitalWrite (pin,HIGH);
    myservo.write(0);
}}
