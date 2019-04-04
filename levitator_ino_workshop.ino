//=========================================================|
//     Ekobots Innovation Ltda - www.ekobots.com.br        |
//        Juan Sirgado y Antico - www.jsya.com.br          |
//---------------------------------------------------------|
//        Program Magnetic Levitator - 2016/02/06          |
//               All rights reserved 2016                  |
//=========================================================|
int anaPin = 1;   // Arduino Analogic Pin 1;
int digPin = 5;   // Arduino Digital  Pin 5;
int subPin = 7;   // Arduino Digital  Pin 7;
int addPin = 8;   // Arduino Digital  Pin 8;
//
int     anaVal = 0;   // Analogic Read(Hall Sensor) Value;
boolean digVal = 0;   // Digital Write(Electromagnet) Value;
//
int levVal = ; //Input levitation value from sensor here

//---------------------------------------------------------|
void setup()
{
   // Levitator initialization Begin; 
   Serial.begin(57600);
   Serial.println("Levitator by JSyA");
   Serial.println("Starting...");
   // Digital Pins Work Mode Setup;
   pinMode(digPin, OUTPUT);
   pinMode(subPin, INPUT_PULLUP);
   pinMode(addPin, INPUT_PULLUP);
   // Levitator initialization End; 
   Serial.println("Started.");
}
//---------------------------------------------------------|
void loop() 
{
  //int current_time = micros();
  
   // Hall Sensor Read (Magnetic Field Intensity);
   
   anaVal = analogRead(anaPin);
   
   
   value_log(); //Printing values on serial port for debugging
   
   if (anaVal < levVal) 
   {
      digVal = LOW;
   }
   
   else // if (anaVal > levVal) 
   {
      digVal = HIGH;
   }
   //
   // Turn ON/OFF The Electromagnet;
   // With Base on Sensor Value and the Levitation Point;
   
   digitalWrite(digPin, digVal);
   
   //int last_time = micros();
   //int tim = last_time - current_time; //Measuring Time Difference of a single loop
   //Serial.println("");
   //Serial.print("Time: ");
   //Serial.print(tim);
   //Serial.println("");
}
//---------------------------------------------------------|
void value_log()
// Analogic/Digital/Levitation Values Print;
{
   // Show the Hall Sensor Value;
   Serial.print("anaVal=[");
   Serial.print(anaVal); 
   Serial.print("]-");
   // Show the Electromagnet state On=1/Off=0;
   Serial.print("digVal=[");
   Serial.print(digVal);
   Serial.print("]-");
   // Show the Levitation Point Value;
   Serial.print("levVal=[");
   Serial.print(levVal);
   Serial.println("];");
}
//=========================================================|
