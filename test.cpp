// Edited in feature-math branch
#include "expression_parser.h"
#include <iostream>
#include "calculator.h"

int main() {
    std::cout << "Add: " << add(3, 4) << std::endl;
    std::cout << "Subtract: " << subtract(10, 5) << std::endl;
    std::cout << "Multiply: " << multiply(6, 7) << std::endl;
    std::cout << "Divide: " << divide(20, 4) << std::endl;
    std::cout << "Factorial: " << factorial(5) << std::endl;
    std::cout << "GCD: " << gcd(48, 18) << std::endl;
    std::cout << "LCM: " << lcm(12, 15) << std::endl;
    std::cout << "Random (1-10): " << randomInRange(1, 10) << std::endl;
    std::string expr = "3 + 4 * (2 - 1) / 5";
    std::cout << "Expression Result of '" << expr << "': " << evaluateExpression(expr) << std::endl;

    return 0;
}

