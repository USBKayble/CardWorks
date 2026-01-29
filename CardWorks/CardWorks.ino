/*
 * CardWorks - Numworks Calculator Port for M5 Stack Cardputer
 * 
 * This is a port of the Numworks calculator system to the M5 Stack Cardputer.
 * It provides a scientific calculator with support for basic arithmetic,
 * trigonometric functions, logarithms, and more.
 * 
 * Hardware: M5 Stack Cardputer (ESP32-S3)
 * Display: 240x135 TFT
 * Input: Built-in QWERTY keyboard
 * 
 * Key Mappings:
 * - Numbers (0-9): Enter digits
 * - Operators (+, -, *, /, ^): Mathematical operations
 * - Enter/Return: Calculate result
 * - ESC: Clear all (AC)
 * - DEL: Backspace/Delete
 * - TAB: Insert π (pi)
 * - Shift+P: Insert π (pi)
 * - Shift+E: Insert e (Euler's number)
 * - q: Square root
 * - s: Sine / Shift+S: Arcsine
 * - c: Cosine / Shift+C: Arccosine
 * - t: Tangent / Shift+T: Arctangent
 * - l: Natural logarithm / Shift+L: Log base 10
 * - a: Absolute value
 * - Fn+; (up arrow): Memory recall
 * - Fn+/ (down arrow): Memory store
 * - Fn+, (left arrow): Backspace
 * - ., (, ): Decimal point and parentheses
 * 
 * Based on the Numworks calculator open-source project.
 */

#include <M5Cardputer.h>
#include "Calculator.h"
#include "CalculatorUI.h"

Calculator calculator;
CalculatorUI ui(&calculator);

void setup() {
    // Initialize Serial for debugging
    Serial.begin(115200);
    Serial.println("CardWorks - Numworks Calculator for Cardputer");
    Serial.println("Initializing...");
    
    // Initialize calculator
    calculator.setMode(MODE_SCIENTIFIC);
    
    // Initialize UI
    ui.begin();
    
    Serial.println("Initialization complete!");
    Serial.println("Ready to calculate!");
}

void loop() {
    ui.update();
    delay(10); // Small delay to prevent excessive updates
}
