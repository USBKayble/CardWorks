# CardWorks - Numworks Calculator for M5 Stack Cardputer

A port of the Numworks calculator system to the M5 Stack Cardputer, providing a powerful scientific calculator in your pocket.

## Features

- **Scientific Calculator**: Full support for advanced mathematical operations
- **Basic Arithmetic**: Addition, subtraction, multiplication, division, exponentiation
- **Trigonometric Functions**: sin, cos, tan, asin, acos, atan
- **Logarithmic Functions**: ln (natural log), log (base 10)
- **Mathematical Functions**: Square root, absolute value
- **Mathematical Constants**: π (pi), e (Euler's number)
- **Expression Evaluation**: Support for complex expressions with parentheses
- **Memory Functions**: Store, recall, clear, and add to memory
- **Physical Button Support**: ESC, DEL, Enter, TAB, Shift, Fn, arrow keys
- **Real-time Display**: Shows both expression and result
- **Error Handling**: Clear error messages for invalid operations

## Hardware Requirements

- M5 Stack Cardputer (ESP32-S3 based)
- Built-in 240x135 TFT Display
- Built-in QWERTY Keyboard

## Building and Flashing

### Using PlatformIO (Recommended)

1. Install [PlatformIO](https://platformio.org/)
2. Clone this repository:
   ```bash
   git clone https://github.com/USBKayble/CardWorks.git
   cd CardWorks
   ```
3. Build and upload:
   ```bash
   pio run -t upload
   ```

### Using Arduino IDE

1. Install the Arduino IDE
2. Install the M5Cardputer board support
3. Install required libraries:
   - M5Cardputer (v1.0.0+)
   - M5Unified (v0.1.16+)
4. Open `src/main.cpp` in Arduino IDE
5. Select "M5Cardputer" as the board
6. Click Upload

## Usage

### Key Mappings

#### Physical Buttons

| Button | Function | Description |
|--------|----------|-------------|
| ESC | Clear All (AC) | Clear everything and start over |
| DEL | Backspace | Delete last character |
| Enter/OK | Calculate | Evaluate the expression |
| TAB | Insert π | Insert pi constant (3.14159...) |

#### Number and Basic Operators

| Key | Function |
|-----|----------|
| 0-9 | Enter digits |
| +, -, *, / | Basic operators |
| ^ | Exponentiation |
| . | Decimal point |
| (, ) | Parentheses |

#### Function Keys (Letters)

| Key | Function | With Shift |
|-----|----------|------------|
| Q | √ (Square root) | - |
| S | sin (Sine) | asin (Arcsine) |
| C | cos (Cosine) | acos (Arccosine) |
| T | tan (Tangent) | atan (Arctangent) |
| L | ln (Natural log) | log (Log base 10) |
| A | abs (Absolute value) | - |
| E | - | Insert e constant |
| P | - | Insert π constant |

#### Arrow Keys (with Fn modifier)

| Key Combo | Function |
|-----------|----------|
| Fn + , | Left arrow (Backspace) |
| Fn + . | Right arrow (reserved) |
| Fn + ; | Up arrow (Memory Recall) |
| Fn + / | Down arrow (Memory Store) |

#### Alternative Keys

| Key | Function |
|-----|----------|
| ` (backtick) | Clear all (alternative to ESC) |
| ; (semicolon) | Backspace (alternative to DEL) |

### Examples

**Basic Arithmetic:**
- `2+2` = 4
- `10*5` = 50
- `100/4` = 25

**Scientific:**
- `2^8` = 256
- `q9` → `sqrt(9)` = 3
- `s0` → `sin(0)` = 0

**Complex Expressions:**
- `(2+3)*(4+5)` = 45
- `2^(3+1)` = 16

## Project Structure

```
CardWorks/
├── src/
│   ├── main.cpp           # Main application entry point
│   ├── Calculator.h       # Calculator core logic header
│   ├── Calculator.cpp     # Calculator implementation
│   ├── CalculatorUI.h     # UI handler header
│   └── CalculatorUI.cpp   # UI implementation
├── platformio.ini         # PlatformIO configuration
├── .gitignore            # Git ignore rules
└── README.md             # This file
```

## Architecture

The calculator is built with a clean separation of concerns:

1. **Calculator Core** (`Calculator.cpp`): Implements the mathematical engine
   - Expression parsing and evaluation
   - Mathematical operations and functions
   - Error handling
   - Memory functions

2. **UI Layer** (`CalculatorUI.cpp`): Handles display and input
   - Display rendering
   - Keyboard input processing
   - Visual feedback
   - Status display

3. **Main Application** (`main.cpp`): Coordinates components
   - Initialization
   - Main event loop
   - System setup

## Credits

- Based on the [Numworks](https://www.numworks.com/) open-source calculator
- Built for the [M5 Stack Cardputer](https://shop.m5stack.com/products/m5stack-cardputer-kit-w-m5stamps3)
- Developed by USBKayble

## License

This project is open source. The Numworks calculator is licensed under a permissive license allowing ports and derivatives.

## Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest features
- Submit pull requests

## Future Enhancements

Potential features for future releases:
- Graphing capabilities
- Advanced scientific functions (hyperbolic, etc.)
- Programming mode (binary, hex, oct)
- Variable storage
- History/recall of previous calculations
- Python scripting support (like original Numworks)
- Equation solver
- Matrix operations
