# Chrono-BETA ⏱️

A multi-sensor optoelectronic chronometer with laser triggering and real-time data logging. Designed for precise timing in races using Arduino UNO, KY-008 laser modules, and visual indicators.

## Features
- Laser-triggered timing system
- Visual feedback with LEDs (Ready, Counting, Stopped)
- Real-time data shown on 16x2 I2C LCD
- Built with ATMEGA328 (Arduino UNO compatible)

## Hardware Used
- Arduino UNO (CH340 compatible)
- KY-008 Laser Module
- 16x2 I2C LCD Display
- Red, Yellow, Green LEDs
- 200Ω resistors (x3)
- Breadboard + jumper wires

## How it Works
1. System waits in **Ready** state (green LED).
2. First laser interruption: **Timing starts** (yellow LED).
3. Second interruption: **Timer stops** and result is shown (red LED).

## Wiring Diagram
Coming soon: `Images/assembled_setup.jpg`# Chrono-Beta
