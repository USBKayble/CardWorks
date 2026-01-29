#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <Arduino.h>
#include <vector>
#include <string>

// Calculator modes
enum CalcMode {
    MODE_NORMAL,
    MODE_SCIENTIFIC,
    MODE_PROGRAMMING
};

// Calculator state
class Calculator {
public:
    Calculator();
    
    // Core operations
    void input(char c);
    void inputFunction(const String& func);
    void clear();
    void clearEntry();
    void backspace();
    void calculate();
    
    // Display
    String getDisplay() const;
    String getExpression() const;
    bool hasError() const { return error; }
    String getErrorMessage() const { return errorMsg; }
    
    // Mode control
    void setMode(CalcMode mode);
    CalcMode getMode() const { return currentMode; }
    
    // Memory operations
    void memoryStore();
    void memoryRecall();
    void memoryClear();
    void memoryAdd();
    
private:
    String expression;
    String display;
    String errorMsg;
    double memory;
    CalcMode currentMode;
    bool error;
    bool newNumber;
    
    // Evaluation
    double evaluate(const String& expr);
    double applyOperator(double a, double b, char op);
    double applyFunction(const String& func, double value);
    int precedence(char op);
    bool isOperator(char c);
    bool isFunction(const String& token);
};

#endif
