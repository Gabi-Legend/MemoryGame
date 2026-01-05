# Arduino Memory Game

A simple memory game built with Arduino featuring 3 LEDs and 3 buttons.

## How to Play

1. Watch the LED sequence carefully
2. Repeat the sequence by pressing the corresponding buttons
3. If correct, all LEDs flash and a new sequence begins
4. If wrong, LEDs flash rapidly and the game restarts

## Hardware Required

- Arduino board
- 3 LEDs
- 3 Push buttons
- 3 Resistors (220Ω for LEDs)
- 3 Resistors (10kΩ for buttons, optional if using INPUT_PULLUP)
- Breadboard and jumper wires

## Circuit

**LEDs:**
- LED 1 → Pin 4
- LED 2 → Pin 3
- LED 3 → Pin 2

**Buttons:**
- Button 1 → Pin 13
- Button 2 → Pin 12
- Button 3 → Pin 11

## Installation

1. Clone this repository
2. Open the `.ino` file in Arduino IDE
3. Connect your Arduino board
4. Upload the code
