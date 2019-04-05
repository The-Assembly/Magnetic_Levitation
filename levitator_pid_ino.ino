//=========================================================|
//     The Assembly - Make Smart Things
//---------------------------------------------------------|
//      Program Magnetic Levitator PID 
//=========================================================|
int anaPin = 1;   // Arduino Analogic Pin 1
int digPin = 5;   // Arduino Digital  Pin 5
int subPin = 7;   // Arduino Digital  Pin 7
int addPin = 8;   // Arduino Digital  Pin 8
//
int anaVal = 0;   // Analogic Valie
int digVal = 0;   // Digital Value
//
int levVal = ; // Levitation Value
//---------------------------------------------------------|
// PID Values
float setpoint = 0;
float measured_value = 0;
float output = 0;
float integral = 0;
float derivative = 0;
float error = 0;
float previous_error = 0;
float dt = 0.1;
float Kp = ; //input PID values
float Ki = ;  
float Kd = ;  
//---------------------------------------------------------|
void setup()
{
   // Levitator initialization Begin; 
   Serial.begin(57600);
   //Serial.println("Levitator by JSyA");
   //Serial.println("Starting...");
   // Digital Pins Work Mode Setup;
   //TCCR0B = TCCR0B & B11111000 | B00000001; // for PWM frequency of 62500.00 Hz
   pinMode(digPin, OUTPUT);
   pinMode(addPin, INPUT_PULLUP);
   pinMode(subPin, INPUT_PULLUP);
   //
   setpoint = levVal;
   // Levitator initialization End; 
   //Serial.println("Started.");
}
//---------------------------------------------------------|
void loop() // PID
{
   // Hall Sensor Read (Magnetic Field Intensity);
   anaVal = analogRead(anaPin);
   // PID calculations
   measured_value = anaVal;
   error = levVal - measured_value;
   integral = integral + error * dt;
   derivative = (error - previous_error) / dt;
   output = (-Kp * error) + (-Ki * integral) + (-Kd * derivative);
   previous_error = error;
   // Final value setup
   digVal += output;
   // Check the value for levitation point;
   if (digVal < 0) digVal=0;
   if (digVal > 255) digVal=255;
   // Increase/Decrease the value for Electromagnet;
   // With Base on Sensor Value and the Levitation Point;
   
  analogWrite(digPin, digVal);
  //value_log(); // Show log values for debug;

}
//---------------------------------------------------------|

void value_log()
// Analogic/Digital/Levitation Values Print;
{
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
