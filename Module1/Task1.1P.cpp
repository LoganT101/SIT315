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
}

void loop()
{
  // read sensor
  LDRValue = analogRead(LDRPin);
  
  // print sensor value
  Serial.println("Sensor Value: " + String(LDRValue));
  
  // map sensor value to LED
  analogWrite(LEDPin, map(LDRValue, 0, 1023, 0, 255));
  delay(100); 
}
