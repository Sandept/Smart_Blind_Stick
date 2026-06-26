# 🧑‍🦯 Smart Blind Stick (Arduino UNO)

[![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](#)
[![C++](https://img.shields.io/badge/-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](#)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](#)

## 📖 Overview

The **Smart Blind Stick** is an active Electronic Travel Aid (ETA) designed to upgrade a traditional passive walking cane into a smart, obstacle-detecting device. Powered by an Arduino UNO, it utilizes ultrasonic echolocation to sense immediate obstacles in a user's path, providing real-time, graduated multi-sensory feedback (haptic and acoustic). 

This project aims to provide an affordable, highly reliable, and zero-configuration safety tool for the visually impaired, allowing for confident and independent mobility.

---

## ✨ Features

- **Instant Echolocation Feedback:** Processes distance calculations in microseconds with zero-lag response.
- **Graduated Acoustic Alerts:** A piezo buzzer increases its beep rate as obstacles get closer (dynamic mapping between 11 cm to 100 cm).
- **Haptic Warning System:** A vibration motor activates in the critical zone (<= 10 cm) to provide physical "STOP" feedback.
- **Reduced Haptic Fatigue:** The vibration motor remains inactive during safe walking, activating only for close-range emergencies.
- **Zero-Configuration Accessibility:** Simple toggle switch operation. No Bluetooth, apps, or calibration required.

---

## 🛠️ Hardware Requirements

| Component | Description |
| :--- | :--- |
| **Arduino UNO** | The central processing microcontroller running the C++ logic. |
| **HC-SR04 Ultrasonic Sensor** | Primary obstacle detection eye (fires 40 kHz sound waves). |
| **Water Sensor Module** | Detects wet floors/puddles to prevent slips. |
| **Piezo Buzzer** | Emits high-frequency acoustic warnings. |
| **Flat Vibration Motor** | Delivers haptic feedback to the user's palm. |
| **9V Battery & Clip** | Portable power supply with SPST Rocker Switch. |
| **Jumper Wires & Breadboard** | For circuit routing and prototyping. |

---

## 🔌 Circuit Connections

| Component | Pin / Terminal | Arduino UNO Pin |
| :--- | :--- | :--- |
| **HC-SR04 Sensor** | VCC | 5V |
| | GND | GND |
| | TRIG | Digital Pin 8 |
| | ECHO | Digital Pin 9 |
| **Piezo Buzzer** | Positive (+) | Digital Pin 6 |
| | Negative (-) | GND |
| **Vibration Motor** | Positive (+) | Digital Pin 2 |
| | Negative (-) | GND |
| **Power Supply** | Battery Positive | Vin (via Rocker Switch) |
| | Battery Negative | GND |

---

## 🚀 Working Principle

1. **Detection:** The HC-SR04 sends a 10µs pulse, triggering an 8-cycle ultrasonic burst. The Arduino calculates the returning echo's duration.
2. **Calculation:** `Distance = (Echo Duration * 0.034) / 2` (converted to centimeters).
3. **Action:**
   - **> 100 cm:** Path clear. Buzzer OFF, Vibrator OFF.
   - **11 cm - 100 cm:** Approaching object. Buzzer beeps (interval scales dynamically from 500ms down to 50ms).
   - **<= 10 cm:** Critical stop. Vibrator ON.

---

## 💻 Source Code

The embedded logic code is written in C++ for the Arduino IDE without relying on heavy external libraries to ensure fast, predictable execution.