#include "CalculatorUI.h"

CalculatorUI::CalculatorUI(Calculator* calc) {
    calculator = calc;
    needsRedraw = true;
    lastDisplay = "";
    currentKey = 0;
}

void CalculatorUI::begin() {
    M5Cardputer.begin();
    M5Cardputer.Display.setRotation(1);
    M5Cardputer.Display.fillScreen(COLOR_BG);
    M5Cardputer.Display.setTextSize(1);
    needsRedraw = true;
}

void CalculatorUI::update() {
    M5Cardputer.update();
    handleKeyboard();
    
    String currentDisplay = calculator->getDisplay();
    if (currentDisplay != lastDisplay || needsRedraw) {
        draw();
        lastDisplay = currentDisplay;
        needsRedraw = false;
    }
}

void CalculatorUI::draw() {
    drawDisplay();
    drawStatusBar();
}

void CalculatorUI::drawDisplay() {
    // Clear display area
    M5Cardputer.Display.fillRect(0, 15, SCREEN_WIDTH, DISPLAY_HEIGHT, COLOR_DISPLAY_BG);
    
    // Draw expression if available
    String expr = calculator->getExpression();
    if (expr.length() > 0 && expr != calculator->getDisplay()) {
        M5Cardputer.Display.setTextColor(0x7BEF); // Gray for expression
        M5Cardputer.Display.setTextSize(1);
        M5Cardputer.Display.setCursor(5, 20);
        
        // Truncate if too long
        if (expr.length() > 38) {
            M5Cardputer.Display.print(expr.substring(expr.length() - 38));
        } else {
            M5Cardputer.Display.print(expr);
        }
    }
    
    // Draw result/current value
    M5Cardputer.Display.setTextColor(COLOR_DISPLAY_TEXT);
    String display = calculator->getDisplay();
    
    // Determine text size based on length
    int textSize = 2;
    if (display.length() > 12) textSize = 1;
    
    M5Cardputer.Display.setTextSize(textSize);
    
    int yPos = 35;
    if (textSize == 1) yPos = 40;
    
    M5Cardputer.Display.setCursor(5, yPos);
    
    // Truncate if still too long
    int maxLen = textSize == 2 ? 12 : 38;
    if (display.length() > maxLen) {
        M5Cardputer.Display.print(display.substring(display.length() - maxLen));
    } else {
        M5Cardputer.Display.print(display);
    }
    
    // Draw error message if present
    if (calculator->hasError()) {
        M5Cardputer.Display.setTextColor(COLOR_ERROR);
        M5Cardputer.Display.setTextSize(1);
        M5Cardputer.Display.setCursor(5, 45);
        M5Cardputer.Display.print(calculator->getErrorMessage());
    }
}

void CalculatorUI::drawStatusBar() {
    // Draw mode indicator
    M5Cardputer.Display.fillRect(0, 0, SCREEN_WIDTH, 14, 0x2104); // Dark blue
    M5Cardputer.Display.setTextColor(COLOR_BUTTON_TEXT);
    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.setCursor(5, 3);
    
    switch (calculator->getMode()) {
        case MODE_NORMAL:
            M5Cardputer.Display.print("NUMWORKS CALC");
            break;
        case MODE_SCIENTIFIC:
            M5Cardputer.Display.print("SCIENTIFIC");
            break;
        case MODE_PROGRAMMING:
            M5Cardputer.Display.print("PROGRAMMER");
            break;
    }
    
    // Draw help text
    M5Cardputer.Display.setCursor(180, 3);
    M5Cardputer.Display.print("AC:DEL");
}

void CalculatorUI::handleKeyboard() {
    if (M5Cardputer.Keyboard.isChange()) {
        if (M5Cardputer.Keyboard.isPressed()) {
            Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();
            
            // Handle special keys
            for (auto key : status.word) {
                if (key == '`') {
                    calculator->clear();
                    needsRedraw = true;
                }
                else if (key == ';') {
                    calculator->backspace();
                    needsRedraw = true;
                }
                else if (key == '\n' || key == '=') {
                    calculator->calculate();
                    needsRedraw = true;
                }
                else if (key == 'q' || key == 'Q') {
                    calculator->inputFunction("sqrt");
                    needsRedraw = true;
                }
                else if (key == 's' || key == 'S') {
                    calculator->inputFunction("sin");
                    needsRedraw = true;
                }
                else if (key == 'c' || key == 'C') {
                    calculator->inputFunction("cos");
                    needsRedraw = true;
                }
                else if (key == 't' || key == 'T') {
                    calculator->inputFunction("tan");
                    needsRedraw = true;
                }
                else if (key == 'l' || key == 'L') {
                    calculator->inputFunction("ln");
                    needsRedraw = true;
                }
                else if (key >= '0' && key <= '9') {
                    calculator->input(key);
                    needsRedraw = true;
                }
                else if (key == '+' || key == '-' || key == '*' || key == '/' || 
                         key == '.' || key == '(' || key == ')' || key == '^') {
                    calculator->input(key);
                    needsRedraw = true;
                }
            }
        }
    }
}

void CalculatorUI::drawButton(int x, int y, int w, int h, const String& label, uint16_t bgColor) {
    M5Cardputer.Display.fillRect(x, y, w, h, bgColor);
    M5Cardputer.Display.drawRect(x, y, w, h, COLOR_BUTTON_TEXT);
    
    M5Cardputer.Display.setTextColor(COLOR_BUTTON_TEXT);
    M5Cardputer.Display.setTextSize(1);
    
    int textX = x + (w - label.length() * 6) / 2;
    int textY = y + (h - 8) / 2;
    M5Cardputer.Display.setCursor(textX, textY);
    M5Cardputer.Display.print(label);
}
