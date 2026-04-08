// Automatic Night Lamp (using LDR) - MaRS Electronics Task 1

const int ldrPin = A0;  
const int ledPin = 13;   
const int threshold = 400; // Light level below which the lamp turns on

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // For monitoring light values
}

void loop() {
  int lightLevel = analogRead(ldrPin); 
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  if (lightLevel < threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}