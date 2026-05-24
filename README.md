# ESP-IDF Projects Repository

A centralized repository for all ESP-IDF based development projects, peripheral interfacing examples, and upcoming Embedded AI/TinyML implementations using ESP32 platforms.

This repository contains modular examples and reusable components for working with various ESP32 peripherals including SD cards, OLED displays, Wi-Fi, microphones, speakers, and audio interfaces. The repository will continue to expand with future embedded systems, IoT, Edge AI, and TinyML projects.

---

# Repository Contents

## Current Projects

### 1. SD Card Interface

Features:

* FATFS integration
* File read/write operations
* SDMMC/SPI communication
* ESP-IDF compatible implementation

---

### 2. OLED Display (0.96")

Features:

* SSD1306 OLED driver implementation
* Text rendering
* Display initialization and control
* I2C communication support

---

### 3. OLED Display (1.3")

Features:

* 1.3-inch OLED interfacing examples
* Graphics and display handling
* ESP-IDF compatible driver implementation
* Display rendering examples

---

### 4. I2S Recorder

Features:

* I2S microphone input
* Audio recording to SD card
* Speaker output support
* WAV/audio data handling
* Real-time audio capture

Integrated peripherals:

* SD Card
* I2S Microphone
* I2S Speaker

---

### 5. WiFi Scanner

Features:

* Nearby Wi-Fi network scanning
* RSSI monitoring
* SSID detection
* ESP32 station mode examples
* Wireless connectivity testing

---

# Upcoming Projects

* TinyML deployment on ESP32
* Audio classification using Edge AI
* ESP32-P4 AI acceleration experiments
* TensorFlow Lite Micro integration
* ESP-DL implementations
* Real-time audio inference
* Embedded cybersecurity projects
* IoT automation systems
* Sensor interfacing and monitoring
* FreeRTOS multitasking examples
* Audio event detection systems
* Edge AI optimization experiments

---

# Supported Platforms

* ESP32
* ESP32-S3
* ESP32-P4
* ESP-IDF framework

---

# Technologies Used

* Embedded C/C++
* ESP-IDF
* FreeRTOS
* I2S
* SPI
* SDMMC
* Wi-Fi
* FATFS
* Edge AI / TinyML

---

# Repository Structure

```text
ESP/
│
├── sdcard/
├── oled/
├── oled_1_3/
├── i2s_recorder/
├── wifi_scan/
└── upcoming_projects/
```

---

# Build and Flash

## Configure ESP-IDF Environment

```bash
idf.py set-target esp32p4
```

## Build Project

```bash
idf.py build
```

## Flash Firmware

```bash
idf.py flash
```

## Open Serial Monitor

```bash
idf.py monitor
```

---

# Getting Started

## Clone Repository

```bash
git clone https://github.com/jagan007G/ESP.git
```

## Open Project Folder

```bash
cd ESP
```

## Build Any Project

```bash
cd project_folder_name
idf.py build
```

---

# Notes

* Each project is self-contained and can be built independently.
* Build files and temporary artifacts are excluded using `.gitignore`.
* Future updates will include complete documentation and wiring diagrams for each project.
* The repository will continuously expand with new ESP-IDF examples and Edge AI projects.

---

# Purpose of This Repository

This repository serves as:

* an ESP-IDF learning workspace
* an embedded systems experimentation platform
* a TinyML and Edge AI development repository
* a collection of reusable ESP32 peripheral examples
* a base for future IoT and AI-enabled em
