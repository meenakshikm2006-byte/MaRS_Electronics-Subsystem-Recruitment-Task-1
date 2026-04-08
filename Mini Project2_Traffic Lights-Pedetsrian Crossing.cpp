const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int buttonPin = 2;

unsigned long previousMillis = 0;
int state = 0; //0=Green,1=Yellow,2=Red

bool pedestrianRequest = false;

const int greenTime = 5000;
const int yellowTime = 2000;
const int redTime = 5000;

void setup() 
{
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(greenLED, HIGH);//first green led lights up
}

void loop()
{
  unsigned long currentMillis = millis();
  if (state == 0 && digitalRead(buttonPin) == LOW) {
    pedestrianRequest = true;
  }

  switch (state)
  {
    case 0:
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);

      if (currentMillis - previousMillis >= greenTime || pedestrianRequest) {
        previousMillis = currentMillis;
        state = 1;
      }
      break;
    case 1:
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);

      if (currentMillis - previousMillis >= yellowTime) {
        previousMillis = currentMillis;
        state = 2;
      }
      break;
    case 2:
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);

      if (currentMillis - previousMillis >= redTime) {
        previousMillis = currentMillis;
        state = 0;
        pedestrianRequest = false;//resets
      }
      break;
  }
}