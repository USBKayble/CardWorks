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
 * - ` (backtick): Clear (AC)
 * - ; (semicolon): Backspace (DEL)
 * - q: Square root
 * - s: Sine
 * - c: Cosine
 * - t: Tangent
 * - l: Natural logarithm (ln)
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
