#include "Calculator.h"
#include <cmath>
#include <stack>

Calculator::Calculator() {
    expression = "";
    display = "0";
    memory = 0.0;
    currentMode = MODE_NORMAL;
    error = false;
    newNumber = true;
}

void Calculator::input(char c) {
    error = false;
    errorMsg = "";
    
    if (newNumber && (isdigit(c) || c == '.')) {
        expression = "";
        newNumber = false;
    }
    
    if (c == '=' || c == '\n') {
        calculate();
        return;
    }
    
    expression += c;
    display = expression;
}

void Calculator::inputFunction(const String& func) {
    error = false;
    errorMsg = "";
    
    if (expression.length() > 0 || display != "0") {
        expression += func + "(";
        display = expression;
    }
}

void Calculator::clear() {
    expression = "";
    display = "0";
    error = false;
    errorMsg = "";
    newNumber = true;
}

void Calculator::clearEntry() {
    if (expression.length() > 0) {
        expression = "";
        display = "0";
    }
}

void Calculator::backspace() {
    if (expression.length() > 0) {
        expression.remove(expression.length() - 1);
        display = expression.length() > 0 ? expression : "0";
    }
}

void Calculator::calculate() {
    if (expression.length() == 0) {
        return;
    }
    
    try {
        double result = evaluate(expression);
        
        if (std::isnan(result) || std::isinf(result)) {
            error = true;
            errorMsg = "Math Error";
            display = "Error";
        } else {
            char buffer[32];
            // Format result intelligently
            if (fabs(result) < 0.0001 || fabs(result) > 9999999) {
                snprintf(buffer, sizeof(buffer), "%.6e", result);
            } else {
                snprintf(buffer, sizeof(buffer), "%.8g", result);
            }
            display = String(buffer);
            expression = display;
            newNumber = true;
        }
    } catch (...) {
        error = true;
        errorMsg = "Syntax Error";
        display = "Error";
    }
}

String Calculator::getDisplay() const {
    return display;
}

String Calculator::getExpression() const {
    return expression;
}

void Calculator::setMode(CalcMode mode) {
    currentMode = mode;
}

void Calculator::memoryStore() {
    if (!error && display.length() > 0) {
        memory = display.toDouble();
    }
}

void Calculator::memoryRecall() {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.8g", memory);
    expression = String(buffer);
    display = expression;
    newNumber = true;
}

void Calculator::memoryClear() {
    memory = 0.0;
}

void Calculator::memoryAdd() {
    if (!error && display.length() > 0) {
        memory += display.toDouble();
    }
}

// Simple expression evaluator using Shunting Yard algorithm
double Calculator::evaluate(const String& expr) {
    std::stack<double> values;
    std::stack<char> ops;
    
    String cleanExpr = expr;
    cleanExpr.replace("π", String(M_PI, 10));
    cleanExpr.replace("e", String(M_E, 10));
    
    for (int i = 0; i < cleanExpr.length(); i++) {
        if (cleanExpr[i] == ' ') continue;
        
        // Handle numbers
        if (isdigit(cleanExpr[i]) || cleanExpr[i] == '.') {
            String numStr = "";
            while (i < cleanExpr.length() && 
                   (isdigit(cleanExpr[i]) || cleanExpr[i] == '.')) {
                numStr += cleanExpr[i++];
            }
            i--;
            values.push(numStr.toDouble());
        }
        // Handle opening parenthesis
        else if (cleanExpr[i] == '(') {
            ops.push(cleanExpr[i]);
        }
        // Handle closing parenthesis
        else if (cleanExpr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            if (!ops.empty()) ops.pop(); // Remove '('
        }
        // Handle operators
        else if (isOperator(cleanExpr[i])) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(cleanExpr[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.push(cleanExpr[i]);
        }
    }
    
    // Apply remaining operators
    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperator(a, b, op));
    }
    
    return values.empty() ? 0.0 : values.top();
}

double Calculator::applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : NAN;
        case '^': return pow(a, b);
        default: return 0;
    }
}

double Calculator::applyFunction(const String& func, double value) {
    if (func == "sin") return sin(value);
    if (func == "cos") return cos(value);
    if (func == "tan") return tan(value);
    if (func == "sqrt") return sqrt(value);
    if (func == "ln") return log(value);
    if (func == "log") return log10(value);
    if (func == "abs") return fabs(value);
    return value;
}

int Calculator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool Calculator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Calculator::isFunction(const String& token) {
    return token == "sin" || token == "cos" || token == "tan" || 
           token == "sqrt" || token == "ln" || token == "log" || token == "abs";
}
