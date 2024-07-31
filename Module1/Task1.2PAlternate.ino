#include <TimerOne.h>

// TINKERCAD DOES NOT HAVE THIS LIBRARY, AND I DO NOT HAVE THE LDR COMPONENT
// THEREFORE THIS IS AN ALTERNATE VERSION AND THE OTHER TASK1.2P WAS SUBMITTED

// initialise pins
int LDRPin = A0;     
int LEDPin = 11;  

// initialise sensor reading
int LDRValue = 0;

// setup
void setup()
{
  pinMode(LDRPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  
  Serial.begin(9600);
  
  // setup interrupt
  Timer1.initialize(100000); // 100ms
  Timer1.attachInterrupt(timerISR);
}

void loop()
{
}

// interrupt
void timerISR()
{
  // read sensor
  LDRValue = analogRead(LDRPin);
  
  // print sensor value
  Serial.println("Sensor Value: " + String(LDRValue));
  
  // map sensor value to LED
  analogWrite(LEDPin, map(LDRValue, 0, 1023, 0, 255));
}