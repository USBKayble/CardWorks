# CardWorks Quick Reference

## Physical Buttons

The M5 Stack Cardputer has several physical buttons that are optimized for calculator use:

| Button | Function | Description |
|--------|----------|-------------|
| **ESC** | Clear All (AC) | Clears everything, start fresh |
| **DEL** | Backspace | Delete last character |
| **Enter** | Calculate (=) | Evaluate expression and show result |
| **TAB** | Insert π | Insert pi constant (3.14159...) |
| **Shift** | Modifier | Access advanced functions |
| **Fn** | Function Modifier | Access arrow keys and memory |

## Keyboard Layout

```
┌──────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  `   │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │
│      │     │     │     │     │     │Sh:^ │     │     │     │     │     │     │
├──────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘
│    Q    │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  (  │  )  │
│   √     │     │Sh:e │     │ tan │     │     │     │     │Sh:π │     │     │
│         │     │     │     │Sh:  │     │     │     │     │     │     │     │
│         │     │     │     │atan │     │     │     │     │     │     │     │
├─────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴──┐
│     A     │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │Enter │
│    abs    │ sin │     │     │     │     │     │     │  ln │Fn:↑ │     │  =   │
│           │Sh:  │     │     │     │     │     │     │Sh:  │     │     │      │
│           │asin │     │     │     │     │     │     │ log │     │     │      │
├───────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──────┤
│      Z       │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  Shift  │
│              │     │ cos │     │     │     │     │Fn:← │Fn:→ │Fn:↓ │         │
│              │     │Sh:  │     │     │     │     │     │     │     │         │
│              │     │acos │     │     │     │     │     │     │     │         │
└──────────────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────────┘
```

Legend:
- **Sh:** = Shift key modifier
- **Fn:** = Function key modifier  
- **↑↓←→** = Arrow key functions

## Function Keys

### Basic Functions

| Key | Function | Usage |
|-----|----------|-------|
| Q | sqrt (Square Root) | `q9` → `sqrt(9)` = 3 |
| S | sin (Sine) | `s0` → `sin(0)` = 0 |
| C | cos (Cosine) | `c0` → `cos(0)` = 1 |
| T | tan (Tangent) | `t0` → `tan(0)` = 0 |
| L | ln (Natural Log) | `l2.71828` → `ln(e)` = 1 |
| A | abs (Absolute Value) | `a-5` → `abs(-5)` = 5 |

### Advanced Functions (with Shift)

| Key Combo | Function | Usage |
|-----------|----------|-------|
| Shift+S | asin (Arcsine) | `Shift+s0.5` → `asin(0.5)` |
| Shift+C | acos (Arccosine) | `Shift+c0.5` → `acos(0.5)` |
| Shift+T | atan (Arctangent) | `Shift+t1` → `atan(1)` = π/4 |
| Shift+L | log (Log base 10) | `Shift+l100` → `log(100)` = 2 |
| Shift+E | Insert e | Inserts Euler's number (2.71828...) |
| Shift+P | Insert π | Inserts pi (3.14159...) |
| Shift+6 | ^ (Power) | Alternative to ^ key |

## Operators

| Key | Operator | Example |
|-----|----------|---------|
| + | Addition | `2+3` = 5 |
| - | Subtraction | `5-2` = 3 |
| * | Multiplication | `4*5` = 20 |
| / | Division | `10/2` = 5 |
| ^ | Exponentiation | `2^3` = 8 |
| . | Decimal Point | `3.14` |
| ( | Open Parenthesis | `(2+3)*4` |
| ) | Close Parenthesis | `(2+3)*4` |

## Special Keys

### Primary Controls

| Key/Button | Function | Description |
|------------|----------|-------------|
| ESC | AC (All Clear) | Clear everything |
| DEL | Backspace | Delete last character |
| Enter | Calculate | Evaluate expression |
| TAB | Insert π | Insert pi constant |

### Alternative Controls

| Key | Function | Description |
|-----|----------|-------------|
| ` (backtick) | AC (All Clear) | Alternative to ESC |
| ; (semicolon) | Backspace | Alternative to DEL (when not using Fn) |

### Arrow Keys (with Fn modifier)

| Key Combo | Function | Description |
|-----------|----------|-------------|
| Fn+, | ← Left Arrow | Backspace |
| Fn+. | → Right Arrow | Reserved for future use |
| Fn+; | ↑ Up Arrow | Memory Recall (MR) |
| Fn+/ | ↓ Down Arrow | Memory Store (MS) |

## Order of Operations

1. **P**arentheses: `()`
2. **E**xponents: `^`
3. **M**ultiplication and **D**ivision: `*`, `/` (left to right)
4. **A**ddition and **S**ubtraction: `+`, `-` (left to right)

## Common Calculations

### Area Formulas
```
Circle:     3.14159*r^2
Rectangle:  length*width
Triangle:   0.5*base*height
```

### Volume Formulas
```
Cube:       side^3
Sphere:     4/3*3.14159*r^3
Cylinder:   3.14159*r^2*h
```

### Physics
```
Speed:          distance/time
Acceleration:   (final_v-initial_v)/time
Force:          mass*acceleration
Energy:         0.5*mass*velocity^2
```

## Constants

| Constant | Value | How to Enter |
|----------|-------|--------------|
| π (pi) | 3.14159... | Type `3.14159` |
| e (Euler) | 2.71828... | Type `2.71828` |

## Tips

1. **Clear vs Delete:**
   - ` (backtick): Clear everything
   - ; (semicolon): Delete last character

2. **Parentheses:**
   - Always balance your parentheses
   - Use them to control order of operations

3. **Functions:**
   - Type the letter key, then the number
   - Example: `q16` becomes `sqrt(16)`

4. **Chaining:**
   - After a result, continue calculating
   - Previous result stays in expression

5. **Errors:**
   - Math Error: Invalid operation (√-1, 1/0)
   - Syntax Error: Malformed expression

## Display Guide

```
┌───────────────────────────────────────┐
│ NUMWORKS CALC          AC:DEL         │ ← Status bar
├───────────────────────────────────────┤
│                                       │
│ 2+3*4                                 │ ← Expression
│                                       │
│          14                           │ ← Result
│                                       │
└───────────────────────────────────────┘
```

## Quick Examples

| Want to calculate | Type | Result |
|------------------|------|--------|
| 7 × 8 | `7*8` [Enter] | 56 |
| 100 ÷ 4 | `100/4` [Enter] | 25 |
| 2⁸ | `2^8` [Enter] | 256 |
| √25 | `q25` [Enter] | 5 |
| sin(0) | `s0` [Enter] | 0 |
| (5+3) × 2 | `(5+3)*2` [Enter] | 16 |

## Troubleshooting

| Problem | Solution |
|---------|----------|
| Screen is frozen | Press reset button on device |
| Keys not working | Check if keys are stuck |
| Wrong result | Check order of operations |
| Error message | Clear with ` and try again |
| Display too small | Result auto-sizes for length |

## Status Indicators

| Display | Meaning |
|---------|---------|
| NUMWORKS CALC | Standard calculator mode |
| SCIENTIFIC | Scientific calculator mode |
| Error | Invalid calculation |
| Math Error | Mathematical impossibility |
| Syntax Error | Invalid expression format |

## Supported Functions

- [x] Basic arithmetic (+, -, *, /, ^)
- [x] Trigonometric (sin, cos, tan)
- [x] Logarithmic (ln, log)
- [x] Square root (sqrt)
- [x] Absolute value (abs)
- [x] Parentheses for grouping
- [x] Decimal numbers
- [x] Scientific notation
- [ ] Graphing (future)
- [ ] Programming mode (future)
- [ ] Matrix operations (future)

## Getting Help

- Documentation: README.md
- Examples: EXAMPLES.md
- Build Guide: BUILD.md
- Technical Details: TECHNICAL.md
- Development: DEVELOPMENT.md

## Version

CardWorks v1.0 - Initial Numworks port to M5 Stack Cardputer
