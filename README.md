# proximity-based-alarm
# Proximity Alarm System

A distance-based alert system using an HC-SR04 ultrasonic sensor, 
3 LEDs, and a buzzer. Objects are detected across 3 distance zones, 
each triggering a different LED. When an object gets too close, 
a buzzer sounds.

## How It Works
The HC-SR04 sends out an ultrasonic pulse and measures how long 
it takes to bounce back. This gives the distance to the nearest 
object. Based on that distance, different LEDs light up and a 
buzzer activates at close range.

## Distance Zones
| Zone | Distance | Response |
|------|----------|----------|
| Far | 20–30 cm | Blue LED |
| Medium | 10–20 cm | Red LED |
| Close | 0–10 cm | Green LED + Buzzer |

## Components
- Arduino
- HC-SR04 Ultrasonic Sensor
- 3 LEDs (Red, Green, Blue)
- Buzzer
- Resistors

## Setup
Connect components as follows:
- TRIG → Pin 9
- ECHO → Pin 10
- Green LED → Pin 6
- Red LED → Pin 5
- Blue LED → Pin 3
- Buzzer → Pin 11

Upload `proximity_alarm.ino` to your Arduino. Done! 
