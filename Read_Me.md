# Submission: MaRS Electronics Subsystem - Task 1 

## Section A: Tinkercad Simulations

### Question 1: Blinking LEDs
**Tinkercad Link:** [https://www.tinkercad.com/things/gXOJ3Pi8rQI-blinking-led/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=WMBTnm8B8Ad5NYecTYMijDYFm8nDB8FDscsqgJ8abfY] 
**Explanation:** In this circuit we use an Arduino UNO to make three LEDs blink simultanously at three differentnintervals
(500ms,1000ms & 1500ms). Instead of delay() function the function millis() is used since this prevents the Arduino from stopping
altogether to create the delay and hence makes sure that the LEDs blink simultaneously.Also it makes sure that the timings doesn't add up. 
It keeps track of the time the the LED Blinked and then the next blink time using millis() which gives the total time for which
the program ran. And then it calcultes  interval and checks the condition required for each lED and accordingly toggles the LED state.

**Code Logic**
Using arrays here to define the pins and their time intervals inorder to reduce code repetition. The variable previous millis is set to 0 
for each LED initially. The variable currenttime keeps track of the time the program has been running using millis(). In the setup function 
we set up each pin as output pins (here). Then in the loop function we check for the conditon (currenttime-prevtime>=interval) which if satisfied
toggles the LED state. The prevtime var is updated to current time in each pass. Finally digitalWrite function gives the output to each LED.


  
### Question 2: RGB LED
**Tinkercad Link:** [https://www.tinkercad.com/things/ffimGMyLDCv-rgb-led/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=LB7Sk-5fkTdQuwI-0GgwRFFzqLm9E_OwQ3xGNvT5Iug] 
**Explanation:** In this circuit we use a potentiometer to give analog input.The user provides analog input which is then read
by the Arduino and is mapped out to change the colour of the RGB LED. The same input value is also used to change the blink speed 
of a normal LED. Both these events occur simultaneously.

**Code Logic:** Due to the difference in the range of the potentiometer and the Arduino, the map function translates the input value
from the potentiometer (0-1023) to the Arduino (0-255). The setrgb function gives the value read from the potentiometer by the Arduino
into the respective pins of the RGB LED. ALso by using the millis() instead of delay() we make sure that the RGB LED changes colour
independent of the blink speed of the normal LED.


### Question 3: Reaction Time Tester
**Tinkercad Link:** [https://www.tinkercad.com/things/lAtGrrnC9mP-ldr-circuit/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=87KIOEp8QiyP5-ta-1sIZgZSO_rSSNhzW5ncxJEzPkU] 
**Explanation:**In this simulation the program measures the time interval between LED Blink and the push button press and dispalys the 
reaction time in the Serial Monitor. Here  the INPUT_PULLUP is used instead of INPUT_PULLDOWN method to minimise the use of external resistors
by using Arduino's inbuilt internal resistors. Code keeps track of start time and end timenusing the help of millis() function and then
resets the program after the output is displayed. 

**Code Logic:** We use INPUT_PULLUP method in designing the circuit with the button instead of the pulldown moethod. This reduces the number of 
external resisitors used. Also we keep track of the best time taken by the user after each test by ysung a variable besttime. The previous besttime 
is compared to the current reactiontime in each loop an daccordingly updated. The Serial.print and Serial.println functions are used to display the output
in the Serial Monitor. The random function gives random time for the LED to blink. Also the reset function makes sure that the LED state toggles back to off
state after each roundWe use delay function after each pass so that the user has enough time to read the displayed output.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------


## Section B: Mini Project

##(1) Automatic Night Lamp-LDR
**Tinkercad Link:** [https://www.tinkercad.com/things/3cTRLF3aBrt-ldr-circuit/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=m2iIiOibnCgEVp-Ol4MnEEmzOL70oJqaAtMZabcmR-g]

### Project Overview

**Explanation:** It uses a Light Dependent Resistor (LDR) to monitor ambient light levels.The LDR changes resistance with light. The Arduino has specific range of 
values for brightness and darkness. The program keeps track of this value and checks for the attainment of the threshold value. Once it reaches the Arduino 
automatically triggers the LED (the lamp). 

**Components Used:**
Arduino Uno: Acts as the central control unit to process analog data.
LDR (Photoresistor): The input sensor used to detect light intensity.
LED: The output controller that simulates the night lamp.
10kohm Resistor: Used in a voltage divider circuit with the LDR to provide a measurable voltage to the Arduino.
220ohm Resistor: Limits current to the LED to prevent damage.

**Code Logic:** The LDR pin is assigned to analog input pin A0 and and the LED pin to pin 13. The threshold value is set to 400. The if condition checks
if the light level goes below the threshold value and accordingly turns the LED ON. Otherwise it is kept in OFF state.

## (2) Traffic Lights-Pedestrian Crossing
**TinkerCAD Link:** [https://www.tinkercad.com/things/e2SqyFiTP6I/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=ffDIiQbtLwwUlXwv-V_MHYl5YnbMVDNdVMewjF8ysGo]
###Project Overview

**Explanation:*** This is a simulation of a traffic light system which chnages colour from green to yellow and then to red and back again to green as usual. 
This particular circuit allows a pedestrian to request crossing that is a change in the traffic lights to red. The request is taken only whenthe lights are green.
The button press speeds up the light change from green to red.

**Components Used:** 
Arduino UNO
3 LEDs( Red, Green ,Yellow)
Push Button
3 220 ohm resistors (In series with the LEDs)
BreadBoard

**Code Logic:** State varibale 0,1,2 are assigned for Green, Yellow and Red colours.For each state, other two LEDs are turned OFF.
The cycle starts with Green and goes on to Yellow and Red. The button press works only during Green. We use INPUT_PULLUP here to reduce
the number of external resistors used, hence making it less complex. MIllis() is used to add the non- blocking feature. After a request
is taken and the change happens from green to red, the state of the lights resets back to 0 (green).

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
