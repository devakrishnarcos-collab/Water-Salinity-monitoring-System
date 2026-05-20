# Water Salinity Monitoring System
 
A low-cost, real-time water salinity monitoring system designed for agriculture, aquaculture, and water management applications. This project uses an ESP32 microcontroller with a TDS (Total Dissolved Solids) sensor to measure and monitor water salinity levels.
 
## Project Overview
 
High salinity in irrigation water is a major cause of reduced agricultural productivity and crop failure. This system provides farmers and water management professionals with an affordable, continuous monitoring solution to detect harmful salinity levels early and prevent crop damage.
 
**Key Features:**
- Real-time salinity measurement using TDS sensor
- LCD display (16×2 I2C) for immediate feedback
- Buzzer alert system for threshold exceedance
- Low-cost and portable design
- Easy to use and field-deployable
- ontinuous monitoring without interruption

## Hardware Components
 
| Component | Specification | Purpose |
|-----------|---------------|---------|
| **ESP32 Microcontroller** | Dual-core, 240 MHz | Central processing unit |
| **TDS Sensor** | Analog output (0-5V) | Measure water salinity |
| **LCD Display** | 16×2 with I2C module | Display salinity values |
| **Buzzer** | Piezoelectric alarm | Alert mechanism |
| **Power Supply** | 5V regulated | System power |
 
### Component Connections
```
TDS Sensor    → GPIO34 (Analog Input)
LCD SDA       → GPIO21 (I2C Data)
LCD SCL       → GPIO22 (I2C Clock)
Buzzer        → GPIO25 (Digital Output)
```
 
## System Architecture
 
The system follows a modular architecture with four main components:
 
```
Water Source
    ↓
TDS Sensor (measures conductivity)
    ↓
ESP32 Microcontroller (processes data via ADC)
    ├→ LCD Display (real-time display via I2C)
    └→ Buzzer (alert via GPIO)
```
 
### Block Diagram
```
┌─────────────┐
│Water Source │
└──────┬──────┘
       │
       ↓
  ┌─────────┐     Analog Signal      ┌──────────────┐
  │TDS       │──────────────────────→│ ESP32 ADC    │
  │Sensor    │                       │              │
  └─────────┘                        └──┬───────┬──┘
                                        │       │
                          I2C Signal    │       │   Alert Signal
                                    ┌───▼─┐ ┌──▼──┐
                                    │LCD  │ │Buzzer│
                                    │     │ │      │
                                    └─────┘ └──────┘
```
 
## Installation & Setup
 
### Prerequisites
- Arduino IDE (v1.8.0 or higher)
- ESP32 board support installed in Arduino IDE
- USB cable for programming
### Step 1: Install Arduino IDE
Download from [arduino.cc](https://www.arduino.cc/en/software)
 
### Step 2: Add ESP32 Board Support
1. Open Arduino IDE
2. Go to **File → Preferences**
3. Add this URL to "Additional Boards Manager URLs":
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Go to **Tools → Board Manager** and search for "ESP32"
5. Install the ESP32 board package
### Step 3: Install Required Libraries
1. Go to **Sketch → Include Library → Manage Libraries**
2. Search and install:
   - `Wire.h` (usually pre-installed)
   - `LiquidCrystal_I2C` by Frank de Brabander
### Step 4: Upload Code
1. Select **Tools → Board → ESP32 Dev Module**
2. Select the correct COM port
3. Open the project sketch and upload
   
##  Usage
 
### Basic Operation
1. **Power ON** the system
2. **Immerse** the TDS sensor in water to be tested
3. **View** real-time salinity readings on the LCD display
4. **Alert** - Buzzer activates if salinity exceeds 1.15 ppt (adjustable)

## Pin Configuration
 
| Component | ESP32 Pin | Pin Type | Function |
|-----------|-----------|----------|----------|
| TDS Sensor | GPIO34 | Analog Input | Read salinity signal |
| LCD SDA | GPIO21 | I2C Data | LCD communication |
| LCD SCL | GPIO22 | I2C Clock | LCD synchronization |
| Buzzer | GPIO25 | Digital Output | Alert activation |
 
## How It Works

### System Flow
```
1. Initialize ESP32, LCD, and Buzzer
   ↓
2. Read analog voltage from TDS sensor
   ↓
3. Convert analog to digital value (0-4095)
   ↓
4. Calculate salinity in ppt using calibration formula
   ↓
5. Display value on LCD
   ↓
6. Check if salinity exceeds threshold
   ├─ YES → Activate buzzer and display warning
   └─ NO → Continue normal monitoring
   ↓
7. Repeat continuously
```
 
### Salinity Calculation
The system converts the TDS sensor output to salinity using:
```
Salinity (ppt) = Electrical Conductivity (EC) × Calibration Factor
```
 
**Calibration:** The TDS sensor requires calibration for optimal accuracy. This depends on your specific sensor model and water conditions.
 
## Performance Results
 
### System Performance
- **Accuracy**: Approximately ±5% (depends on sensor calibration)
- **Response Time**: Real-time updates (< 1 second)
- **Operating Duration**: Continuous without interruption
- **Stability**: Tested under extended operation
### Stress Testing Results
| Test Condition | Result |
|---|---|
| Continuous operation (8+ hours) | Stable |
| Variable salinity input |  Accurate response |
| Repeated measurements |  Consistent results |
| Multiple threshold triggers |  Reliable alerts |
 
### Comparison with Design Expectations
| Expected | Actual | Status |
|----------|--------|--------|
| Measure salinity |  Successfully measured | PASS |
| Display on LCD |  Display working correctly | PASS |
| Alert for high salinity |  Buzzer activates properly | PASS |
| Continuous monitoring |  System operated continuously | PASS |
 
## Calibration Guide
 
For accurate salinity measurements:
 
1. **Prepare calibration solutions** with known salinity values
2. **Immerse TDS sensor** in each solution
3. **Record ADC readings** from serial monitor
4. **Create a calibration curve** (ADC vs. Salinity)
5. **Update the calibration formula** in code accordingly
   
## Challenges & Solutions
 
| Challenge | Solution |
|-----------|----------|
| Sensor accuracy affected by temperature | Use temperature-compensated readings |
| Signal noise from unstable power | Use regulated power supply |
| Sensor degradation in saline water | Regular cleaning and maintenance |
| Environmental interference (algae, dirt) | Clean sensor probe regularly |
 
## Applications
 
- **Agriculture**: Monitor irrigation water quality
- **Aquaculture**: Maintain proper salinity for aquatic life
- **Water Treatment**: Monitor water quality in treatment plants
- **Environmental Monitoring**: Track coastal water salinity changes
  
## Future Enhancements
 
- [ ] **IoT Integration**: Cloud-based remote monitoring
- [ ] **Mobile App**: Real-time alerts on smartphone
- [ ] **Data Logging**: Store historical salinity data
- [ ] **Additional Sensors**: pH, temperature, turbidity sensors
- [ ] **Solar Power**: Off-grid operation capability
- [ ] **Web Dashboard**: Real-time data visualization
- [ ] **Machine Learning**: Predictive analysis for crop damage

## Project Structure
 
```
water-salinity-monitoring/
│
├── README.md                 # This file
├── LICENSE                   # Project license
├── CODE_OF_CONDUCT.md        # Community guidelines
│
├── firmware/
│   └── salinity_monitor.ino  # Main Arduino sketch
│
├── documentation/
│   ├── circuit_diagram.pdf
│   ├── hardware_setup.md
│   └── calibration_guide.md
│
├── hardware/
│   ├── components_list.md
│   └── assembly_guide.md
│
└── results/
    ├── performance_data.txt
    └── test_reports.md
```
 
## References
 
- Espressif Systems. (2020). [ESP32 Technical Reference Manual](https://www.espressif.com)
- DFRobot. (2018). [Analog TDS Sensor Meter Documentation](https://www.dfrobot.com)
- Arduino. (2023). [Arduino IDE Documentation](https://www.arduino.cc)
- [LiquidCrystal_I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)
  
## Troubleshooting
 
### LCD Not Displaying Anything
- Check I2C connections (SDA: GPIO21, SCL: GPIO22)
- Verify I2C address of LCD module (default: 0x27)
- Ensure LCD library is properly installed
### Buzzer Not Working
- Verify GPIO25 connection
- Check if buzzer is activated in code
- Test with a simple digitalWrite(buzzer_pin, HIGH)
### Inaccurate Readings
- Calibrate TDS sensor with known solutions
- Ensure sensor probe is clean
- Check power supply stability
- Verify ADC pin connection
### Serial Monitor Shows No Output
- Select correct baud rate (usually 115200)
- Check USB driver installation
- Verify COM port selection
- Ensure code includes Serial.begin(115200)
