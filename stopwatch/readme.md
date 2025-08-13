# 4-Digit 7-Segment Counter with Button Control

This Arduino project controls a **4-digit 7-segment display** to count numbers, toggle pause/resume using a button, and reset with a long press.  
It uses **multiplexing** to drive the display and supports displaying digits 0–9 with a decimal point.

---

## Features
- **Automatic counting** starting from zero.
- **Pause/Resume** the counter with a short button press.
- **Reset to zero** with a long button press (visual blinking on reset).
- Displays **4 digits** with proper multiplexing.
- Includes **debouncing** for stable button detection.

---

## Hardware Requirements
- Arduino Uno / Nano / Mega
- Common-cathode **4-digit 7-segment display**
- Push button
- Resistors (for button and display segments)
- Jumper wires
- Breadboard

---

## Pin Configuration

| Arduino Pin | Connected To             |
|-------------|--------------------------|
| 2           | Digit 1 (d1)              |
| 3           | Digit 2 (d2)              |
| 4           | Digit 3 (d3)              |
| 5           | Digit 4 (d4)              |
| 6           | Segment A                 |
| 7           | Segment B                 |
| 8           | Segment C                 |
| 9           | Segment D                 |
| 10          | Segment E                 |
| 11          | Segment F                 |
| 12          | Segment G                 |
| 13          | Decimal Point (.)         |
| A0          | Push Button (INPUT_PULLUP)|

---

## How It Works
1. **Display Multiplexing**  
   The Arduino quickly switches between each digit (d1–d4) and sets the corresponding segments to show the correct number.  
   This happens so fast that it looks like all digits are on at once.

2. **Button Control**  
   - **Short Press**: Toggles counting on/off.  
   - **Long Press (~1000 cycles)**: Resets the count and blinks the display as feedback.

3. **Debouncing**  
   The `debounce()` function ensures the button press is read correctly without false triggers.

---

## Code Structure
- **setup()**: Initializes pins and sets default states.
- **loop()**: Handles counting, button reading, and display updates.
- **pickDigit()**: Selects which digit to light up.
- **pickNumber()**: Lights the correct segments for a given number.
- **clearleds()**: Turns off all segments.
- **Digit Functions**: `zero()` to `nine()` define which segments are lit for each number.

---

## How to Use
1. Wire up the components according to the **Pin Configuration** table.
2. Upload the code to your Arduino using the Arduino IDE.
3. The counter will start automatically.
4. Use the button:
   - **Press once** to pause/resume counting.
   - **Hold for reset** — display will blink before resetting.

---

## Future Improvements
- Add **countdown mode**.
- Display **custom messages**.
- Adjustable counting speed with another button or potentiometer.

---

## Author
- **Your Name**
- [LinkedIn Profile](https://www.linkedin.com/)  
- [GitHub Profile](https://github.com/)

