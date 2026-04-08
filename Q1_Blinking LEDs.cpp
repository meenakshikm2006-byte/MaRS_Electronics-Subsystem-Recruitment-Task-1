#define LED_COUNT 3
const int ledPins[LED_COUNT] = {8, 9, 10}; // Array for LED Pins
const unsigned long intervals[LED_COUNT] = {500, 1000, 1500};// Array for intervals
// Arrays to track the last update time and current state for each LED
unsigned long previousMillis[LED_COUNT] = {0, 0, 0};
bool state[LED_COUNT]={false,false,false}; // 0 is LOW, 1 is HIGH

void setup() {
    int i;
    for (i = 0; i < LED_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    unsigned long currentMillis = millis();
    int j;
    for (j = 0; j < LED_COUNT; j++) {
        // Calculate the difference between current time and last blink time
        if (currentMillis - previousMillis[j] >= intervals[j]) {
            
            previousMillis[j] = currentMillis;
            state[j]=!state[j];
            digitalWrite(ledPins[j], state[j]);
        }
    }
}