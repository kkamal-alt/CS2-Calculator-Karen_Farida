#include "calculator.h"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) throw std::invalid_argument("Division by zero!");
    return static_cast<double>(a) / b;
}

long long factorial(int n) {
    if (n < 0) throw std::invalid_argument("Factorial of negative number!");
    long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return abs(a * b) / gcd(a, b);
}

int randomInRange(int min, int max) {
    if (min > max) throw std::invalid_argument("Invalid range!");
    std::srand(std::time(nullptr));
    return min + std::rand() % (max - min + 1);
}

