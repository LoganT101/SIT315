// THIS IS NOT THE ONLY VERSION OF TASK 1.2P
// THERE IS ANOTHER THAT USES A LIBRARY TINKERCAD DOES NOT HAVE WITH BETTER INTERRUPTS
// DUE TO NOT HAVING THE PHYSICAL COMPONENTS I CANNOT SUBMIT IT AS I CANNOT DEMONSTRATE IT WORKS
// https://github.com/LoganT101/SIT315/tree/main OTHER VERSION FOUND IN REPO UNDER MODULE 1

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
  
  // setup timer interrupt
  startTimer();
}

void loop()
{
}

// setup timer
void startTimer() {
  noInterrupts();
  // configure timer
  TCCR1A = 0; // clear control registers
  TCCR1B = 0;
  TCNT1 = 0; // initialise counter

  // set compare match register for 1Hz
  OCR1A = 15624; // (16*10^6) / (1024*1) - 1 (must be <65536)

  // enable CTC
  TCCR1B |= (1 << WGM12);

  // set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);

  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}

// interrupt
ISR(TIMER1_COMPA_vect) {
  // read sensor
  LDRValue = analogRead(LDRPin);
  
  // print sensor value
  Serial.println("Sensor Value: " + String(LDRValue));
  
  // map sensor value to LED
  analogWrite(LEDPin, map(LDRValue, 0, 1023, 0, 255));
}