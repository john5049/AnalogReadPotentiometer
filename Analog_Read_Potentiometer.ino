/*
  Analog_Read_Potentiometer

  Scales the LED brightness as potentiometer is increased using Pulse Width Modulation.
  Analog PWM values range from [0-64]

  C# GUI implementation of this can be found at:
  https://github.com/john5049/SerialRead


  created 4 Sep 2021
  by John Akridge
*/

// constants won't change. Used here to set a pin number:
const int ledPin =  3;// the number of the LED pin
const int analogPin = A0;

// Variables will change:
double analogReading = 0.0;
double lastReading = 0.0;

void setup() {
  // set the digital pin as output
  pinMode(ledPin, OUTPUT);
  // set the analog pin as input
  pinMode(analogPin, INPUT);
  // start broadcasting serial data at 9600 baud rate
  Serial.begin(9600);
  // write FF = 255 (full brightness) to LED
  analogWrite(ledPin, 255);
}

void loop() {

  // Take an analog reading from the analogPin (A0)
  analogReading = analogRead(analogPin);
  
  // Only write a new analog reading if the current value is different from the last
  if (analogReading != lastReading){
    
    // Broadcast the analog reading via serial bus
    Serial.print(analogReading);
    
    // Broadcast new line character
    Serial.print('\n');
    
    // Map the AnalogRead [0-256] to AnalogWrite [0 - 64] by scaling by 4.0
    analogWrite(ledPin, analogReading / 4.0);
    
    // Add 1/5 sec delay to make more observable by eye
    delay(200);
  }

  // Set lastReading var to analogReading for comparison on next loop iteration
  lastReading = analogReading;

  
}
