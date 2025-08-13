# Arduino & ESP8266 Projects Collection

This repository contains a collection of **Arduino** and **ESP8266** projects developed for learning, experimentation, and authorized testing.  
Each project is self-contained with its own code, description, and setup instructions.

---

## 📂 Projects Included

### 1️⃣ ESP8266 WiFi Network Tool

⚠️ **Disclaimer:** This project is for **educational and authorized security testing purposes only**.  
Do **NOT** use it on networks you do not own or have permission to test.

**Features:**
- Scans nearby Wi-Fi networks (up to 16 results)
- Displays **SSID**, **BSSID**, and **Channel**
- Select a network from a web interface
- Start/Stop:
  - **Evil Twin** test hotspot
  - **Deauthentication** (authorized lab tests only)
- Displays success message when correct password is detected (for test scenarios)

**Requirements:**
- Hardware: ESP8266 board (NodeMCU, Wemos D1 Mini, etc.)
- Software: Arduino IDE + ESP8266 board package

**How it works:**
1. ESP8266 connects to your configured Wi-Fi network.
2. Serves a local web page for scanning and selecting networks.
3. Offers test options for AP cloning and client disconnection.

---

### 2️⃣ Arduino Stopwatch

A simple and precise **digital stopwatch** built on Arduino.  
It measures elapsed time in **minutes, seconds, and milliseconds**, and can be reset via a push button.

**Features:**
- Start, Stop, and Reset functions
- Millisecond precision
- Uses push buttons for control
- Displays time on:
  - Serial Monitor
  - Or optional **7-segment display / LCD module**

**Requirements:**
- Hardware: Arduino Uno/Nano/Pro Mini or compatible board
- Optional: LCD or 7-segment display module
- Push button(s) for control

**How it works:**
1. Press **Start** → Timer begins counting.
2. Press **Stop** → Timer pauses, value is retained.
3. Press **Reset** → Timer resets to `00:00:000`.

---

## ⚙️ Installation (for all projects)

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Clone this repository:
   ```bash
   git clone https://github.com/MustafaAhmed789-coder/Arduino-Projects.git
   cd arduino-projects

## 🌐 Connect with Me
GitHub: https://www.github.com/MustafaAhmed789-coder

LinkedIn: https://www.linkedin.com/in/mustafa-ahmed-32b6501b6
