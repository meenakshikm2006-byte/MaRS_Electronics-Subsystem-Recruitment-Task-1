const int potPin = A0;      
const int NormalLed = 6;    
const int redPin = 11;      
const int greenPin = 10;    
const int bluePin = 9;      

// Variables for millis() blinking
unsigned long previousMillis = 0; 
int ledState = LOW;             

void setup() {
  pinMode(NormalLed, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

void loop() {
  int potValue = analogRead(potPin);  
  if (potValue < 341) { 
    int g = map(potValue, 0, 340, 0, 255);
    setRGB(255 - g, g, 0); 
  } 
  else if (potValue < 682) { 
    int b = map(potValue, 341, 681, 0, 255);
    setRGB(0, 255 - b, b);
  } 
  else { 
    int r = map(potValue, 682, 1023, 0, 255);
    setRGB(r, 0, 255 - r);
  }

  //Calculate Blink Speed from Potentiometer
  int blinkInterval = map(potValue, 0, 1023, 50, 1000);
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (unsigned long)blinkInterval) {
    //Saves the last time the LED blinked
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(NormalLed, ledState);
  }
}

void setRGB(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

