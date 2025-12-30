# DS18B20 Temperature Sensor with Arduino

This project demonstrates how to interface the **DS18B20 digital temperature sensor** with an **Arduino** using the **OneWire** and **DallasTemperature** libraries.

The code scans all connected DS18B20 sensors, prints their **unique device IDs**, and reads the **temperature values in Celsius** through the Serial Monitor.

---

## 📌 Features
- Scan multiple DS18B20 sensors on a single data pin  
- Display unique 8-byte sensor ID (address)  
- Read real-time temperature values in °C  
- Simple and beginner-friendly Arduino code  

---

## 🧰 Hardware Required
- Arduino Uno / Nano / ESP32  
- DS18B20 Temperature Sensor(s)  
- 4.7kΩ Pull-up Resistor  
- Breadboard  
- Jumper Wires  

---

## 🔌 Circuit Connection
| DS18B20 Pin | Arduino |
|------------|---------|
| VCC        | 5V / 3.3V |
| GND        | GND |
| DATA       | Digital Pin 11 |

📌 **Note:** Connect a 4.7kΩ resistor between **VCC** and **DATA** pins.

---

## 📚 Libraries Used
Install the following libraries from Arduino Library Manager:
- **OneWire**
- **DallasTemperature**

---

## ▶️ How It Works
1. The Arduino scans for all connected DS18B20 sensors  
2. Each sensor’s unique ID is printed to the Serial Monitor  
3. Temperature values are read and displayed in Celsius  
4. Data updates every second  

---

## 🖥️ Output Example
Sensor 0 ID: {0x28, 0xFF, 0xA3, 0x91, 0x64, 0x16, 0x03, 0x5C} | Temperature: 27.5 °C
