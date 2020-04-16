#include <Servo.h>

int IN3= 6;
int IN4 = 7;
int vspeed = 5;
int velocidade=0;
int tosend;


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


Servo servox;

void setup() 
{   
    Serial.begin(9600);
 
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    
    pinMode(vspeed,OUTPUT);
    
    servox.attach(3);
    servox.write(90);
    inputString.reserve(200);
    
}

void loop() 
{     
  if (stringComplete) 
  {
    Serial.println(inputString);
    testa();
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
    
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '#') {
      stringComplete = true;
    }
  }
}

void testa()
{
   if (inputString == "N#")
   {
      digitalWrite(IN4,HIGH); 
      digitalWrite(IN3,LOW);
      servox.write(90);     
   }
   if (inputString == "S#")
   { 
      digitalWrite(IN4,LOW); 
      digitalWrite(IN3,HIGH); 
      servox.write(90);
   }
   if (inputString == "L#")
   {
      servox.write(175); 
   }
   if (inputString == "O#")
   {
      servox.write(5); 
   }
   if (inputString == "A#")
   {
      servox.write(50); 
   }
   if (inputString == "B#")
   {
      servox.write(140); 
   }
   if (inputString == "X#")
   {
    velocidade = 0;
   }
   if (inputString == "Y#")
   {
    velocidade = 100;
   }
   if (inputString == "Z#")
   {
    velocidade = 180;
   }
   if (inputString == "W#")
   {
    velocidade = 255;
   }
   analogWrite(vspeed,velocidade);    
   
}


