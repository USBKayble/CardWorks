# Building CardWorks

## Option 1: PlatformIO (Recommended)

PlatformIO provides the easiest way to build and flash the firmware.

### Installation

```bash
# Install PlatformIO Core
pip install platformio

# Or use the PlatformIO IDE
# Download from https://platformio.org/platformio-ide
```

### Building

```bash
# Clone the repository
git clone https://github.com/USBKayble/CardWorks.git
cd CardWorks

# Build the project
pio run

# Upload to device
pio run -t upload

# Monitor serial output
pio device monitor -b 115200
```

## Option 2: Arduino IDE

### Prerequisites

1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Add ESP32 board support:
   - Open Arduino IDE
   - Go to File → Preferences
   - Add this URL to "Additional Board Manager URLs":
     ```
     https://espressif.github.io/arduino-esp32/package_esp32_index.json
     ```
   - Go to Tools → Board → Boards Manager
   - Search for "esp32" and install

3. Install M5Stack libraries:
   - Go to Sketch → Include Library → Manage Libraries
   - Search and install:
     - M5Cardputer (version 1.0.0 or higher)
     - M5Unified (version 0.1.16 or higher)

### Building

1. Open `CardWorks/CardWorks.ino` in Arduino IDE
2. Select board: Tools → Board → ESP32 Arduino → M5Stack-STAMPS3
3. Configure board settings:
   - Upload Speed: 1500000
   - Flash Mode: QIO
   - Flash Size: 4MB (32Mb)
   - Partition Scheme: Default 4MB with spiffs
   - Core Debug Level: None
   - PSRAM: Enabled
4. Connect M5 Stack Cardputer via USB-C
5. Select the correct port: Tools → Port → (your device)
6. Click Upload button

## Option 3: Command Line (arduino-cli)

```bash
# Install arduino-cli
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

# Install ESP32 core
arduino-cli core install esp32:esp32

# Install libraries
arduino-cli lib install "M5Cardputer"
arduino-cli lib install "M5Unified"

# Compile
arduino-cli compile --fqbn esp32:esp32:m5stack-stamps3 CardWorks

# Upload
arduino-cli upload -p /dev/ttyACM0 --fqbn esp32:esp32:m5stack-stamps3 CardWorks
```

## Troubleshooting

### Build Errors

**"M5Cardputer.h not found"**
- Install the M5Cardputer library
- Restart Arduino IDE

**"espressif32 platform not found" (PlatformIO)**
- Check internet connection
- Try: `pio platform install espressif32`

**"PSRAM not found"**
- Ensure PSRAM is enabled in board settings
- M5Stack-STAMPS3 has 8MB PSRAM

### Upload Errors

**"Failed to connect to ESP32"**
- Press and hold the reset button while uploading
- Check USB cable (must be data cable, not charge-only)
- Install CH9102 USB driver if needed

**"Port not found"**
- Check device connection
- Linux: Add user to dialout group: `sudo usermod -a -G dialout $USER`
- Windows: Install CP210x USB driver

### Runtime Errors

**"Blank screen"**
- Check power supply (USB should provide enough)
- Verify libraries are correctly installed
- Check serial monitor for error messages

**"Keyboard not responding"**
- Restart device
- Check keyboard connection (internal on Cardputer)

## Development Build

For development with debugging enabled:

```bash
# PlatformIO
pio run -e m5stack-cardputer -v

# Monitor with debugging
pio device monitor -b 115200
```

Add to `platformio.ini` for debug build:
```ini
[env:m5stack-cardputer-debug]
platform = espressif32
board = m5stack-stamps3
framework = arduino
build_flags = 
    -DCORE_DEBUG_LEVEL=5
    -DDEBUG
monitor_speed = 115200
```

## Testing Build

To verify your build without hardware:

```bash
# Check compilation only
pio run -t check

# Static analysis
pio check
```
