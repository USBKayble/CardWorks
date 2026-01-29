# CardWorks Development Guide

## Development Setup

### Prerequisites
- PlatformIO Core or PlatformIO IDE
- M5 Stack Cardputer hardware
- USB-C cable for programming

### Building the Project

```bash
# Build the project
pio run

# Upload to device
pio run -t upload

# Monitor serial output
pio device monitor
```

## Code Structure

### Calculator Core (`Calculator.cpp`)

The calculator uses a Shunting Yard algorithm for expression evaluation:

1. **Expression Parsing**: Converts infix notation to postfix
2. **Operator Precedence**: Handles order of operations correctly
3. **Function Application**: Processes mathematical functions
4. **Error Handling**: Validates operations and catches errors

#### Key Methods:

- `input(char c)`: Handles character input
- `calculate()`: Evaluates the current expression
- `evaluate(String expr)`: Core evaluation engine
- `applyOperator()`: Applies binary operators
- `applyFunction()`: Applies mathematical functions

### UI Layer (`CalculatorUI.cpp`)

The UI handles display rendering and input processing:

1. **Display Management**: Updates screen efficiently
2. **Keyboard Input**: Processes key presses
3. **Visual Feedback**: Shows expressions and results
4. **Status Display**: Shows mode and help text

#### Display Layout:

```
┌─────────────────────────────────────┐
│ NUMWORKS CALC              AC:DEL   │ Status Bar
├─────────────────────────────────────┤
│                                     │
│ 2+2*3                               │ Expression
│                                     │
│          8                          │ Result
│                                     │
└─────────────────────────────────────┘
```

## Adding New Features

### Adding a New Function

1. Update `Calculator.h` to declare the function (if needed)
2. Add the function to `applyFunction()` in `Calculator.cpp`
3. Add the function name to `isFunction()` check
4. Add keyboard mapping in `CalculatorUI::handleKeyboard()`

Example - Adding arcsin:

```cpp
// In Calculator.cpp - applyFunction()
if (func == "asin") return asin(value);

// In Calculator.cpp - isFunction()
return token == "sin" || token == "cos" || token == "asin" || ...;

// In CalculatorUI.cpp - handleKeyboard()
else if (key == 'a' || key == 'A') {
    calculator->inputFunction("asin");
    needsRedraw = true;
}
```

### Adding a New Mode

1. Add mode to `CalcMode` enum in `Calculator.h`
2. Update mode display in `CalculatorUI::drawStatusBar()`
3. Add mode-specific behavior as needed

## Testing

### Manual Testing Checklist

- [ ] Basic arithmetic operations (+, -, *, /)
- [ ] Exponentiation (^)
- [ ] Parentheses and order of operations
- [ ] Trigonometric functions (sin, cos, tan)
- [ ] Square root
- [ ] Natural logarithm
- [ ] Decimal numbers
- [ ] Error handling (division by zero, etc.)
- [ ] Clear and backspace functions
- [ ] Display overflow handling

### Testing on Hardware

```bash
# Build and upload
pio run -t upload

# Monitor serial output for debugging
pio device monitor -b 115200
```

## Debugging

### Serial Output

The calculator outputs debug information to Serial at 115200 baud:

```cpp
Serial.begin(115200);
Serial.println("Debug message");
```

### Common Issues

**Display not updating:**
- Check `needsRedraw` flag is set after input
- Verify `update()` is called in main loop

**Calculation errors:**
- Check expression parsing in `evaluate()`
- Verify operator precedence
- Test with simple expressions first

**Keyboard not responding:**
- Verify `M5Cardputer.update()` is called
- Check `isChange()` and `isPressed()` conditions
- Test individual keys

## Performance Optimization

### Display Updates
- Only redraw when display changes
- Use dirty rectangle updates for partial redraws
- Cache rendered elements when possible

### Calculation
- Optimize expression parsing for long expressions
- Consider caching frequently used values
- Profile with Serial timing output

## Contributing Guidelines

1. Follow existing code style
2. Test on actual hardware
3. Document new features
4. Keep changes minimal and focused
5. Update README with new functionality

## Resources

- [M5Cardputer Documentation](https://docs.m5stack.com/en/core/Cardputer)
- [ESP32-S3 Technical Reference](https://www.espressif.com/sites/default/files/documentation/esp32-s3_technical_reference_manual_en.pdf)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Numworks Calculator](https://www.numworks.com/)
