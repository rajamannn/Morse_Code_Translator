# 📡 Morse Code Translator (Simulation → Hardware)

A complete **Morse Code Translator System** developed from **virtual simulation to real hardware implementation**.  
This project encodes and decodes Morse code (dots & dashes) and generates **real-time visual and audio output** using LEDs and a buzzer.

---

## 🚀 Project Overview

This project demonstrates the full engineering cycle:

**Idea → Simulation → Validation → Hardware → Real-Time Communication**

The system was first designed and tested in **Wokwi Simulator**, where Morse encoding/decoding logic, signal timing, and debugging were verified.  
After successful simulation, the same design was implemented on a **physical hardware board**, producing accurate Morse signals using LEDs and buzzer.

---

## ✨ Features

- Morse Code Encoding & Decoding  
- Real-time Signal Processing  
- Visual Output using LEDs  
- Audio Output using Buzzer  
- Push Button Morse Input  
- Simulation to Hardware Transition  
- Accurate Signal Timing  

---

## 🧰 Components Used

- Microcontroller Board (Arduino / ESP / Compatible)
- LED (for Morse visual output)
- Buzzer (for Morse audio signal)
- Push Button (input)
- Resistors
- Breadboard
- Connecting Wires

---

## 💻 Tools & Technologies

- Wokwi Simulator (Circuit Design & Testing)
- Embedded C / Microcontroller Programming
- Hardware Circuit Implementation
- Signal Encoding & Decoding Logic
- Real-time Debugging & Testing

---

## ⚙️ Working Principle

1. User inputs Morse signals using a push button (short press = dot, long press = dash).
2. Microcontroller processes the timing and converts signals into Morse format.
3. The decoded signal is translated into meaningful output.
4. LEDs blink according to Morse pattern.
5. Buzzer generates corresponding audio signal.
6. Output matches simulation behavior in real time.

---

## 🔌 Circuit Connections (Example)

| Component | Microcontroller Pin |
|----------|--------------------|
| LED      | D13 (or any digital pin) |
| Buzzer   | D12 |
| Button   | D2 (with pull-down resistor) |

*(Modify according to your setup)*

---

## 📂 Project Structure

