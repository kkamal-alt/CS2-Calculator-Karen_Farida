#include "expression_parser.h"
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <cmath>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero!");
            return a / b;
        default: throw std::runtime_error("Invalid operator!");
    }
}

double evaluateExpression(const std::string& expr) {
    std::stack<double> values;
    std::stack<char> ops;

    for (size_t i = 0; i < expr.length(); i++) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            double val = 0;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--; // adjust position
        } else if (expr[i] == '(') {
            ops.push(expr[i]);
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            if (!ops.empty()) ops.pop(); // remove '('
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

