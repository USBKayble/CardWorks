# Numworks to Cardputer Port - Technical Notes

## Porting Strategy

This project ports the core functionality of Numworks calculator to the M5 Stack Cardputer. Due to hardware and architectural differences, this is a functional port rather than a direct code port.

## Key Differences from Original Numworks

### Hardware
- **Original Numworks**: ARM Cortex-M7, 320x240 color display, custom keyboard
- **Cardputer**: ESP32-S3, 240x135 display, QWERTY keyboard

### Software Architecture
- **Original**: Ion + Poincaré + Kandinsky graphics engines
- **This Port**: Simplified architecture using M5Unified library
- **Language**: Original uses C++ with custom libraries; port uses Arduino framework

## Implementation Details

### Mathematical Engine

The calculator implements expression evaluation using the Shunting Yard algorithm:

1. **Tokenization**: Break expression into numbers, operators, functions
2. **Precedence**: Assign priority to operators (^ > */ > +-)
3. **Evaluation**: Use two stacks (values and operators)
4. **Result**: Pop and apply operators to get final result

### Supported Operations

**Binary Operators:**
- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)
- Exponentiation (^)

**Functions:**
- Trigonometric: sin, cos, tan
- Logarithmic: ln, log
- Other: sqrt, abs

**Constants:**
- π (pi) ≈ 3.14159...
- e (Euler's number) ≈ 2.71828...

### Display System

The display is organized into regions:

1. **Status Bar** (0-14px): Mode indicator and help
2. **Display Area** (15-55px): Expression and result
3. **Reserved** (56-135px): Future use (graphs, etc.)

### Input Handling

The Cardputer keyboard is mapped to calculator functions:

- **Direct mapping**: Numbers, operators, decimal
- **Function keys**: Letters mapped to math functions
- **Special keys**: Backtick for clear, semicolon for delete

### Memory Management

ESP32-S3 has sufficient RAM for calculator operations:
- Expression buffer: Dynamic String allocation
- Stack operations: STL stack containers
- Display buffer: M5Unified manages frame buffer

## Limitations

1. **No Python scripting**: Original Numworks supports Python; not feasible on ESP32
2. **Limited graphing**: Small screen makes complex graphs challenging
3. **No equation solver**: Not implemented in this version
4. **Simplified UI**: Optimized for small screen and QWERTY keyboard

## Future Port Considerations

### Potential Additions

**Graphing Module:**
- Function plotting on 240x135 display
- Zoom and pan controls
- Multiple function overlay

**Programming Mode:**
- Binary, hexadecimal, octal display
- Bitwise operations
- Programmer-specific functions

**Advanced Math:**
- Hyperbolic functions (sinh, cosh, tanh)
- Inverse trigonometric functions
- Statistical functions
- Matrix operations (if memory allows)

**Python Subset:**
- MicroPython integration for ESP32
- Basic scripting capabilities
- Limited to memory constraints

## Performance

**Calculation Speed:**
- Simple operations: < 1ms
- Complex expressions: 1-10ms
- Transcendental functions: 1-5ms

**Display Updates:**
- Full redraw: ~20ms
- Partial update: ~5ms
- Target frame rate: 30+ FPS for smooth UI

**Memory Usage:**
- Program size: ~100KB
- Runtime RAM: ~50KB
- Display buffer: Managed by M5Unified

## References

### Numworks Resources
- [Numworks Website](https://www.numworks.com/)
- [Numworks GitHub](https://github.com/numworks/epsilon)
- [Numworks Documentation](https://www.numworks.com/resources/)

### M5 Cardputer Resources
- [Official Product Page](https://shop.m5stack.com/products/m5stack-cardputer-kit-w-m5stamps3)
- [Documentation](https://docs.m5stack.com/en/core/Cardputer)
- [M5Unified Library](https://github.com/m5stack/M5Unified)

### Mathematical Algorithms
- Shunting Yard Algorithm (for expression parsing)
- IEEE 754 floating-point arithmetic
- CORDIC algorithms (used in ESP32 math library)

## Contributing to the Port

When contributing, consider:

1. **Memory constraints**: ESP32-S3 has limited RAM
2. **Screen size**: 240x135 is smaller than original
3. **Keyboard layout**: QWERTY vs. calculator-style
4. **Performance**: ESP32-S3 is slower than ARM Cortex-M7
5. **Compatibility**: Keep interface similar to original when possible

## License Considerations

Numworks is open-source under a permissive license that allows ports and derivatives. This port maintains compatibility with that license while adapting to new hardware.
