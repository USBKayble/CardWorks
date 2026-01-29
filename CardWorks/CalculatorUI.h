#ifndef CALCULATOR_UI_H
#define CALCULATOR_UI_H

#include <M5Cardputer.h>
#include "Calculator.h"

// UI Layout constants
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 135
#define DISPLAY_HEIGHT 40
#define BUTTON_HEIGHT 18
#define BUTTON_MARGIN 2

// Colors (RGB565)
#define COLOR_BG 0x0000        // Black
#define COLOR_DISPLAY_BG 0xFFFF // White
#define COLOR_DISPLAY_TEXT 0x0000 // Black
#define COLOR_BUTTON_BG 0x4208  // Dark gray
#define COLOR_BUTTON_TEXT 0xFFFF // White
#define COLOR_FUNCTION_BG 0x7BEF // Light gray
#define COLOR_OPERATOR_BG 0xFD20 // Orange
#define COLOR_ERROR 0xF800      // Red

class CalculatorUI {
public:
    CalculatorUI(Calculator* calc);
    
    void begin();
    void update();
    void draw();
    
private:
    Calculator* calculator;
    bool needsRedraw;
    String lastDisplay;
    
    // Drawing functions
    void drawDisplay();
    void drawStatusBar();
    
    // Input handling
    void handleKeyboard();
};

#endif
