# CardWorks Examples and Features

## Basic Calculator Operations

### Simple Arithmetic

```
Input: 2+2
Result: 4

Input: 15-7
Result: 8

Input: 6*7
Result: 42

Input: 100/4
Result: 25
```

### Decimal Numbers

```
Input: 3.14*2
Result: 6.28

Input: 10.5+2.3
Result: 12.8

Input: 1.5/0.5
Result: 3
```

### Order of Operations

The calculator correctly follows order of operations (PEMDAS):

```
Input: 2+3*4
Result: 14  (not 20)

Input: (2+3)*4
Result: 20

Input: 10-2*3
Result: 4  (not 24)
```

## Scientific Functions

### Exponentiation

```
Input: 2^8
Result: 256

Input: 10^2
Result: 100

Input: 3^3
Result: 27

Input: 2^(3+1)
Result: 16
```

### Square Root

Press `q` to insert sqrt function:

```
Input: q9
(Shows: sqrt(9)
Result: 3

Input: q16
Result: 4

Input: q2
Result: 1.414213...
```

### Trigonometric Functions

Press the letter key to insert the function:

**Sine (s):**
```
Input: s0
(Shows: sin(0))
Result: 0

Input: s1.5708
(Shows: sin(1.5708) - approximately π/2)
Result: 1
```

**Cosine (c):**
```
Input: c0
Result: 1

Input: c3.14159
(Shows: cos(3.14159) - approximately π)
Result: -1
```

**Tangent (t):**
```
Input: t0
Result: 0

Input: t0.7854
(Shows: tan(0.7854) - approximately π/4)
Result: 1
```

**Inverse Functions (with Shift):**
```
Input: Shift+s0.5
(Shows: asin(0.5))
Result: 0.5236 (approximately π/6)

Input: Shift+c0.5
(Shows: acos(0.5))
Result: 1.047 (approximately π/3)

Input: Shift+t1
(Shows: atan(1))
Result: 0.7854 (approximately π/4)
```

### Logarithms

**Natural Logarithm (l):**
```
Input: l2.71828
(Shows: ln(2.71828) - approximately e)
Result: 1

Input: l10
Result: 2.302585...
```

**Logarithm Base 10 (Shift+L):**
```
Input: Shift+l100
(Shows: log(100))
Result: 2

Input: Shift+l1000
(Shows: log(1000))
Result: 3
```

## Using Mathematical Constants

### Pi (π)

**Method 1: TAB key**
```
Press TAB
Display: π
```

**Method 2: Shift+P**
```
Press Shift+P
Display: π
```

**Example:**
```
Input: TAB*2^2
(Shows: π*2^2)
Result: 12.566... (area of circle with radius 2)
```

### Euler's Number (e)

**Press Shift+E:**
```
Press Shift+E
Display: e
```

**Example:**
```
Input: Shift+e^2
(Shows: e^2)
Result: 7.389... (e squared)
```

## Memory Functions

### Storing Values

**Store to Memory (Fn+/ or down arrow):**
```
Step 1: 5*5 [Enter] → 25
Step 2: Press Fn+/ → Memory stores 25
```

### Recalling Values

**Recall from Memory (Fn+; or up arrow):**
```
Step 1: Press Fn+; → Displays stored value
Step 2: +10 [Enter] → Adds 10 to recalled value
```

### Memory Example

```
Calculate: (5+3) and then multiply by stored value
Step 1: 100 [Enter]
Step 2: Press Fn+/ (store 100)
Step 3: 5+3 [Enter] → 8
Step 4: * [then] Fn+; → multiplies by 100
Step 5: [Enter] → 800
```

## Complex Expressions

### Nested Operations

```
Input: (2+3)*(4+5)
Result: 45

Input: 2*(3+4*(5+6))
Result: 94

Input: ((2+3)*4)+5
Result: 25
```

### Mixed Functions

```
Input: 2+q9
(Shows: 2+sqrt(9))
Result: 5

Input: s0+c0
(Shows: sin(0)+cos(0))
Result: 1

Input: 2^3+4*5
Result: 28
```

### Real-World Calculations

**Area of a circle (πr²):**
```
For radius = 5:
Input: 3.14159*5^2
Result: 78.53975
```

**Pythagorean theorem (c = √(a²+b²)):**
```
For a=3, b=4:
Input: q(3^2+4^2)
(Shows: sqrt(3^2+4^2))
Result: 5
```

**Compound interest:**
```
For principal=1000, rate=0.05, time=3:
Input: 1000*(1.05^3)
Result: 1157.625
```

## Keyboard Shortcuts

### Essential Physical Buttons

| Button | Action | Example |
|--------|--------|---------|
| ESC | Clear all (AC) | Clears everything |
| DEL | Delete last character | Remove mistake |
| Enter | Calculate result | Get answer |
| TAB | Insert π | Quick pi insertion |

### Modifier Keys

**Shift Key Functions:**
- Shift+S: Arcsine (asin)
- Shift+C: Arccosine (acos)  
- Shift+T: Arctangent (atan)
- Shift+L: Log base 10
- Shift+E: Insert e constant
- Shift+P: Insert π constant

**Fn Key Functions (Arrow Keys):**
- Fn+, (←): Backspace
- Fn+; (↑): Memory Recall
- Fn+/ (↓): Memory Store

### Number Entry

```
Input: 123.456
Display: 123.456

Input: 0.001
Display: 0.001

Input: 999999
Display: 999999
```

### Operator Keys

```
Input: 5+3
Display: Shows expression
Press Enter
Result: 8

Input: 10*3
Press Enter
Result: 30
```

## Tips and Tricks

### 1. Physical Buttons for Speed

Use the hardware buttons for faster operation:
- **ESC** for quick clear (faster than backtick)
- **DEL** for backspace (faster than semicolon)
- **TAB** for instant π insertion
- **Enter** button for calculate

### 2. Shift Key for Advanced Functions

Hold Shift while pressing function keys:
- Shift+S/C/T for inverse trig functions
- Shift+L for log base 10 instead of ln
- Shift+E/P for mathematical constants

### 3. Fn Key for Memory and Navigation

Use Fn key combinations:
- Fn+; (up): Recall stored value
- Fn+/ (down): Store current result
- Fn+, (left): Alternative backspace

### 4. Chaining Calculations

After getting a result, you can continue calculating:

```
Step 1: 5+5 = 10
Step 2: +10 = 20
Step 3: *2 = 40
```

### 5. Using Parentheses

Always use parentheses for clarity:

```
Good: (2+3)*(4+5)
Bad: 2+3*4+5  (might be confusing)
```

### 6. Scientific Notation

Very large or very small numbers display in scientific notation:

```
Input: 10^9
Result: 1.0e9  (1 billion)

Input: 10^-6
Result: 1.0e-6  (0.000001)
```

### 7. Function Composition

You can nest functions:

```
Input: qs16
(Shows: sqrt(sin(16)))
Result: (calculated value)
```

### 8. Quick Constants

- Press TAB for π anytime
- Press Shift+E for e anytime
- No need to type out long decimal values

### 9. Memory for Complex Calculations

Store intermediate results:
```
1. Calculate part 1, press Fn+/ to store
2. Calculate part 2
3. Press Fn+; to recall part 1
4. Combine them
```

## Error Handling

### Division by Zero

```
Input: 5/0
Result: Error
Message: Math Error
```

### Invalid Operations

```
Input: q-1
(Shows: sqrt(-1))
Result: Error
(Square root of negative number)
```

### Syntax Errors

```
Input: 2++3
Result: Error
Message: Syntax Error
```

## Display Features

### Expression Display

The calculator shows both your input expression and the result:

```
Top line: 2+3*4     (your expression)
Bottom line: 14     (calculated result)
```

### Auto-sizing Text

Long numbers automatically resize to fit:

```
Short: 42          (large text)
Long: 123456789    (smaller text)
Very long: 1.23e9  (scientific notation)
```

### Status Bar

Top of screen shows:
- Current mode (NUMWORKS CALC, SCIENTIFIC, PROGRAMMER)
- Help text (AC:DEL)

## Advanced Examples

### Engineering Calculations

**Ohm's Law (V = IR):**
```
V = 12V, R = 100Ω
Input: 12/100
Result: 0.12A
```

**Power calculation (P = V²/R):**
```
V = 5V, R = 10Ω
Input: 5^2/10
Result: 2.5W
```

### Physics

**Kinetic energy (KE = ½mv²):**
```
m = 2kg, v = 10m/s
Input: 0.5*2*10^2
Result: 100J
```

### Geometry

**Volume of sphere (V = 4/3πr³):**
```
r = 3
Input: 4/3*3.14159*3^3
Result: 113.097...
```

## Coming Soon

Features planned for future versions:
- Graphing functions
- Matrix operations  
- Equation solver
- Unit conversions
- History/recall
- Custom functions
- Python scripting (MicroPython)
