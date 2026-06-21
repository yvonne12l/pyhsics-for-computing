# 🔬 Physics for Computing

## 🌐 Internet of Things (IoT) Overview

## 👥 Group Members

| No. | Name                | Registration Number   |
|-----|----------------------|-----------------------|
1.BSCCS/2025/62426 Ezekiel Deng
2.BSCCS/2025/59799 Filsan Farah
3.BSCCS/2025/59872  Jacinta Mwende
4.BSCCS/2025/59368 Joan Mulei
5.BSCCS/2025/59424 Yvonne Mureithi 
6.BSCCS/2025/62462 Hunorason Butuli
7.BSCCS/2025/50654 Isaa Bashar
8.BSCCS/2023/72634 Sean Kirubi


The **Internet of Things (IoT)** refers to a network of physical objects embedded with electronics, software, and connectivity features enabling them to collect data from their environment and exchange information over the internet.  

IoT integrates sensors, microcontrollers, communication technologies, cloud platforms, and actuators to create interconnected systems capable of sensing real-world conditions and responding autonomously.

### 💡 Explored IoT Projects
1. **Smart Soil Moisture Monitor**  
2. **Motion-Activated Security Light**

---

## ⚙️ Common Materials Used

### 🧠 Arduino
**Arduino** is an open-source computing platform based on a simple microcontroller board. It is used for constructing and programming electronic devices. Arduino can take inputs and control outputs for various electronic applications using **C or C++** in the Arduino IDE.

**Main Components:**
- **USB Port** – Uploads programs to Arduino and provides power.  
- **Power Input** – Connects an external power adapter.  
- **Power Supply Pins** – Provide stable voltage to power external components.  
- **Digital Output Pins** – Handle digital I/O tasks (LEDs, switches, buzzers, etc.).  
- **Analog Input Pins** – Read voltage from sensors (light, moisture, etc.).  
- **ATmel Microcontroller** – The “brain” that runs the program and controls logic.  
- **In-Circuit Serial Programming (ICSP)** – Allows direct programming of the microcontroller.

---

### 🧩 Breadboard
A **breadboard** is a reusable, solderless platform used for prototyping electronic circuits. It allows quick testing and easy modification of circuits.

**Key Sections:**
- **Terminal Strips** – Main component area with horizontally connected holes.  
- **Power Rails (Bus Strips)** – Distribute power, marked with **+ (red)** and **– (blue)**.  
- **Center Divider** – Separates the two halves of the board; often used for IC placement.

---

## 🌱 Smart Soil Moisture Monitor

![Soil moisture sensor](https://github.com/user-attachments/assets/4f3f91eb-229a-4998-871d-596b5d8e20e9)

### 🔍 Working Principle
A **resistive soil moisture sensor** was used. It measures soil moisture based on **electrical conductivity** — moist soil conducts electricity better due to water and dissolved ions.

When inserted into the soil:
- **Moist soil** → lower resistance → more current flow → high output.  
- **Dry soil** → higher resistance → less current flow → low output.  

The sensor outputs an **analog voltage** proportional to the soil’s resistance, which the Arduino interprets to determine soil moisture levels.

### 🧰 Materials
1. Arduino Uno  
2. Soil Moisture Sensor  
3. LED  
4. Buzzer  
5. Jumper Wires  

### 🧾 Procedure
1. In Tinkercad, drag **Arduino**, **Soil Moisture Sensor**, and **LED**.  
2. Connect sensor **A0** and LED **D13**.  
3. Write code: read analog value → if below threshold, LED ON & buzzer sounds.  
4. Test by adjusting moisture slider in simulation.  
5. For hardware: insert sensor in soil and power via USB or 9V battery.

---

### 🔌 Circuit Connections

| Component | Pin  | Arduino Connection | Function |
|------------|------|--------------------|-----------|
| Soil Moisture Sensor | VCC | 5V | Provides operating voltage |
| Soil Moisture Sensor | GND | GND | Completes electrical circuit |
| Soil Moisture Sensor | AO | A0 | Sends analog signal to Arduino |
| Buzzer & LED | Digital Pins | Shared GND | Alerts when soil is dry |

When the soil is dry, resistance is high and the Arduino outputs HIGH (5V), triggering the **LED** and **buzzer**. When moist, the output is LOW and the alert turns off.

---

### 💻 Code

```cpp
// Pin definitions
const int sensorPin = A0;   // Soil moisture sensor analog output
const int ledPin = 12;      // LED
const int buzzerPin = 6;    // Buzzer

int threshold = 100; // Dryness threshold

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(1000);
}
```
---

## 💡 Motion-Activated Security Light

![PIR motion sensor](https://github.com/user-attachments/assets/062d6b7c-c94c-44b0-8fc3-b768319f33ae)

### 🧩 Concept
The **Motion-Activated Security Light** uses a **Passive Infrared (PIR) sensor** to detect motion by sensing changes in infrared (IR) radiation emitted by objects in its field of view.  
When a warm body (like a person or animal) moves, it causes a change in IR levels, which the sensor detects and triggers the light to turn ON.  
If no motion is detected, the light remains OFF.

**How it works:**
- The **PIR sensor** has a **Fresnel lens** that focuses IR radiation onto a **pyroelectric material**.  
- The material generates a small voltage when exposed to IR radiation.  
- In a stable environment, both halves of the sensor receive equal IR radiation (no signal).  
- When a warm object moves, one half receives more IR, creating a voltage difference that the Arduino interprets as **motion detected**.

---

### 🧰 Materials
1. PIR Motion Sensor  
2. LED or Bulb (via Relay)  
3. Arduino Uno  
4. Jumper Wires  
5. Breadboard  

---

### 🧪 Procedure
1. In **Tinkercad**, add **Arduino Uno**, **PIR sensor**, and **LED**.  
2. Connect:
   - PIR **VCC** → 5V  
   - PIR **GND** → GND  
   - PIR **OUT** → Digital Pin **7**  
   - LED **Anode** → Digital Pin **13**, **Cathode** → GND (via resistor)  
3. Upload the code (below).  
4. Simulate by toggling the PIR sensor to imitate movement.  
5. For real hardware, replace the LED with an **AC bulb controlled via a relay**.

---

### 🔌 Circuit Overview
| Component | Pin | Connection to Arduino | Function |
|------------|-----|-----------------------|-----------|
| PIR Sensor | VCC | 5V | Supplies power to the sensor |
| PIR Sensor | GND | GND | Common ground connection |
| PIR Sensor | OUT | D7 | Sends HIGH signal when motion detected |
| LED | Anode | D13 | Turns ON when motion detected |
| LED | Cathode | GND | Completes circuit through resistor |

---

### 💻 Code

```cpp
int led = 13;
int pir = 7;
int pirData;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
}

void loop() {
  pirData = digitalRead(pir);
  if (pirData == HIGH) {
    digitalWrite(led, HIGH);  // Turn ON light when motion detected
  } else {
    digitalWrite(led, LOW);   // Turn OFF light when no motion
  }
  delay(10); // Short delay for stability
}
