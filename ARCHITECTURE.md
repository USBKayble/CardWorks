# CardWorks Architecture Diagram

## System Architecture

```
┌─────────────────────────────────────────────────────────────────┐
│                     M5 Stack Cardputer                          │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────────────┐  │
│  │   Display    │  │   Keyboard   │  │  Physical Buttons    │  │
│  │  240 x 135   │  │   QWERTY     │  │ ESC DEL Enter TAB    │  │
│  │     TFT      │  │   + Shift/Fn │  │  Shift Fn Modifiers  │  │
│  └──────┬───────┘  └──────┬───────┘  └──────────┬───────────┘  │
│         │                 │                      │              │
│         │                 │                      │              │
└─────────┼─────────────────┼──────────────────────┼──────────────┘
          │                 │                      │
          │                 │                      │
┌─────────▼─────────────────▼──────────────────────▼──────────────┐
│                    CardWorks Application                         │
│  ┌──────────────────────────────────────────────────────────┐   │
│  │                       main.cpp                            │   │
│  │  • Initialization                                         │   │
│  │  • Main event loop                                        │   │
│  │  • Component coordination                                 │   │
│  └────┬────────────────────────────────────────────┬─────────┘   │
│       │                                            │             │
│       ▼                                            ▼             │
│  ┌────────────────────┐                   ┌──────────────────┐  │
│  │  CalculatorUI.cpp  │◄─────────────────►│  Calculator.cpp  │  │
│  │                    │                   │                  │  │
│  │ • Display render   │                   │ • Expression     │  │
│  │ • Keyboard input   │                   │   evaluation     │  │
│  │ • Button handler   │                   │ • Math functions │  │
│  │ • Status bar       │                   │ • Operators      │  │
│  │ • Screen update    │                   │ • Error handling │  │
│  │                    │                   │ • Memory ops     │  │
│  └────────────────────┘                   └──────────────────┘  │
│                                                                  │
└──────────────────────────────────────────────────────────────────┘
```

## Data Flow

```
User Input (Keyboard/Buttons)
         │
         ▼
┌─────────────────────┐
│  CalculatorUI       │
│  handleKeyboard()   │
└──────────┬──────────┘
           │
           ▼
    ┌─────────────┐
    │   Process   │
    │   Input     │
    └──────┬──────┘
           │
           ├─────► Number/Operator ──► calculator->input(char)
           │
           ├─────► Function Key ─────► calculator->inputFunction(String)
           │
           ├─────► Calculate (Enter) ─► calculator->calculate()
           │
           ├─────► Clear (ESC) ───────► calculator->clear()
           │
           └─────► Backspace (DEL) ───► calculator->backspace()
                   
                   
           ┌──────────────┐
           │  Calculator  │
           │  Processing  │
           └──────┬───────┘
                  │
                  ▼
         ┌────────────────┐
         │   Expression   │
         │   Evaluator    │
         │  (Shunting     │
         │   Yard Algo)   │
         └────────┬───────┘
                  │
                  ▼
            ┌──────────┐
            │  Result  │
            └────┬─────┘
                 │
                 ▼
         ┌───────────────┐
         │  CalculatorUI │
         │     draw()    │
         └───────┬───────┘
                 │
                 ▼
         ┌───────────────┐
         │   Display     │
         │   Updated     │
         └───────────────┘
```

## Expression Evaluation Flow

```
Input: "2+3*sqrt(9)"
         │
         ▼
┌─────────────────────┐
│  Tokenization       │
│  [2][+][3][*]       │
│  [sqrt][9]          │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Function           │
│  Evaluation         │
│  sqrt(9) → 3        │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Operator           │
│  Precedence         │
│  * before +         │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│  Calculation        │
│  3*3 = 9            │
│  2+9 = 11           │
└──────────┬──────────┘
           │
           ▼
      Result: 11
```

## Keyboard Mapping Architecture

```
┌──────────────────────────────────────────┐
│         Physical Input Layer             │
├──────────────────────────────────────────┤
│  Hardware Buttons:                       │
│  • ESC → Clear All                       │
│  • DEL → Backspace                       │
│  • Enter → Calculate                     │
│  • TAB → Insert π                        │
├──────────────────────────────────────────┤
│  Modifier Keys:                          │
│  • Shift → Advanced functions            │
│  • Fn → Arrow keys & Memory              │
├──────────────────────────────────────────┤
│  Letter Keys:                            │
│  • Q → sqrt                              │
│  • S → sin  (Shift+S → asin)            │
│  • C → cos  (Shift+C → acos)            │
│  • T → tan  (Shift+T → atan)            │
│  • L → ln   (Shift+L → log)             │
│  • A → abs                               │
│  • E → (Shift+E → insert e)             │
│  • P → (Shift+P → insert π)             │
└──────────────────────────────────────────┘
           │
           ▼
┌──────────────────────────────────────────┐
│      Input Processing Layer              │
├──────────────────────────────────────────┤
│  handleKeyboard()                        │
│  • Detects key state changes             │
│  • Processes modifier combinations       │
│  • Routes to appropriate handler         │
└──────────────────────────────────────────┘
           │
           ▼
┌──────────────────────────────────────────┐
│       Calculator Logic Layer             │
├──────────────────────────────────────────┤
│  Calculator methods:                     │
│  • input(char) - Add to expression       │
│  • inputFunction(String) - Add function  │
│  • calculate() - Evaluate                │
│  • clear() - Reset                       │
│  • backspace() - Delete char             │
│  • memoryStore/Recall() - Memory ops     │
└──────────────────────────────────────────┘
```

## Display Layout

```
┌─────────────────────────────────────────────┐
│ SCIENTIFIC              ESC=AC TAB=π        │ ← Status Bar (14px)
├─────────────────────────────────────────────┤
│                                             │
│  2+3*sqrt(9)                                │ ← Expression (small)
│                                             │
│                     11                      │ ← Result (large)
│                                             │
├─────────────────────────────────────────────┤
│                                             │
│         (Reserved for future use)           │
│       Could be used for graphing            │
│                                             │
│                                             │
│                                             │
└─────────────────────────────────────────────┘
  240px width × 135px height
```

## Component Interaction

```
┌──────────────┐         ┌──────────────┐
│ CalculatorUI │◄───────►│  Calculator  │
└──────┬───────┘         └──────┬───────┘
       │                        │
       │ update()               │ evaluate()
       │ draw()                 │ applyOperator()
       │ handleKeyboard()       │ applyFunction()
       │                        │ 
       │                        │
       ▼                        ▼
┌──────────────┐         ┌──────────────┐
│   Display    │         │   Math       │
│   Drawing    │         │   Engine     │
│              │         │              │
│ • Status Bar │         │ • Parser     │
│ • Expression │         │ • Evaluator  │
│ • Result     │         │ • Functions  │
│ • Errors     │         │ • Memory     │
└──────────────┘         └──────────────┘
```

## Memory Management

```
Stack Allocated (Static):
┌─────────────────────┐
│  Calculator         │
│  calculator;        │
└─────────────────────┘

┌─────────────────────┐
│  CalculatorUI       │
│  ui(&calculator);   │
└─────────────────────┘

Dynamic (STL):
┌─────────────────────┐
│  std::stack<double> │ ← Values stack (evaluation)
└─────────────────────┘

┌─────────────────────┐
│  std::stack<char>   │ ← Operators stack (evaluation)
└─────────────────────┘

String Buffers:
┌─────────────────────┐
│  expression         │ ← User input expression
└─────────────────────┘

┌─────────────────────┐
│  display            │ ← Display text
└─────────────────────┘
```

## Build System Architecture

```
┌─────────────────────────────────────────────┐
│            Source Code                      │
│  • src/Calculator.cpp                       │
│  • src/Calculator.h                         │
│  • src/CalculatorUI.cpp                     │
│  • src/CalculatorUI.h                       │
│  • src/main.cpp                             │
│  • CardWorks/CardWorks.ino (Arduino)        │
└────────────┬────────────────────────────────┘
             │
       ┌─────┴─────┐
       │           │
       ▼           ▼
┌──────────┐  ┌──────────┐
│PlatformIO│  │ Arduino  │
│   .ini   │  │   IDE    │
└────┬─────┘  └────┬─────┘
     │             │
     │             │
     ▼             ▼
┌─────────────────────────┐
│   ESP32 Toolchain       │
│   • Compiler (GCC)      │
│   • Linker              │
│   • Libraries           │
│     - M5Cardputer       │
│     - M5Unified         │
│     - Arduino Core      │
└────────┬────────────────┘
         │
         ▼
┌─────────────────────────┐
│   Firmware Binary       │
│   CardWorks.bin         │
└────────┬────────────────┘
         │
         ▼
┌─────────────────────────┐
│  M5 Stack Cardputer     │
│  ESP32-S3 Flash         │
└─────────────────────────┘
```

## Error Handling Flow

```
User Input
    │
    ▼
┌─────────────┐
│  Validate   │
│   Input     │
└──────┬──────┘
       │
   ┌───┴───┐
   │       │
   ▼       ▼
Valid   Invalid
   │       │
   │       └──► Set error flag
   │            Display error message
   │
   ▼
┌──────────────┐
│  Evaluate    │
│  Expression  │
└──────┬───────┘
       │
   ┌───┴───┐
   │       │
   ▼       ▼
Success  Error
   │       │
   │       ├──► Division by zero
   │       ├──► Invalid operation
   │       ├──► Stack underflow
   │       └──► Math error (√-1)
   │
   ▼
Display
Result
```

This architecture ensures:
- Clean separation of concerns
- Efficient processing
- Responsive user interface
- Robust error handling
- Easy maintenance and extension
