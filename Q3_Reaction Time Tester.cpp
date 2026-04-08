const int LED_PIN = 8;
const int BUTTON_PIN = 2;

bool ledOn = false;
bool waitingForPress = false;

unsigned long startTime = 0;
unsigned long randomTime = 0;

//Best score 
unsigned long bestTime = 999999;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("-----------REACTION TESTER-----------/n");
  Serial.println("Wait for the LED...\nGet Ready...");
  randomSeed(analogRead(A0)); // Gives random time for the LED to turn ON using the noise from the pin A0
  resetRound();
}

void loop() {
  unsigned long currentMillis = millis();
  if (!ledOn && currentMillis >= randomTime) {
    digitalWrite(LED_PIN, HIGH);

    ledOn = true;
    waitingForPress = true;
    startTime = millis();

    Serial.println(">>>>>>>> PRESS NOW <<<<<<<<");
  }


  if (waitingForPress && digitalRead(BUTTON_PIN) == LOW) {
    unsigned long reactionTime = millis() - startTime;
    digitalWrite(LED_PIN, LOW);
    waitingForPress = false;

    Serial.print("Reaction Time: ");
    Serial.print(reactionTime);
    Serial.println(" ms");

    // Best score calculator
    if (reactionTime < bestTime) {
      bestTime = reactionTime;
      Serial.print("NEW PERSONAL BEST!:");
      Serial.print(bestTime);
      Serial.println(" ms\n");}

    delay(3000); // Give player time to read the score
    resetRound();
  }
}

//resets the timer for the next test
void resetRound() {
  digitalWrite(LED_PIN, LOW);
  ledOn = false;
  waitingForPress = false;

  Serial.println("-----------------------");
  Serial.println("\nGet Ready...");
}