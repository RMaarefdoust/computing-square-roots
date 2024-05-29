#include <iostream>
#include <iomanip>
#include <cmath>

// Function to calculate the reciprocal square root using Newton-Raphson method
double reciprocalSqrt(double number, double tolerance = 1e-7, int maxIterations = 1000) {
    if (number <= 0) {
        std::cerr << "Error: Non-positive input to reciprocal square root function." << std::endl;
        return -1;
    }

    double y = 1.0 / sqrt(number); // Initial guess can be the reciprocal of the square root calculated using std::sqrt
    int iterations = 0;

    while (iterations < maxIterations) {
        double yNew = y * (1.5 - 0.5 * number * y * y);
        if (std::abs(yNew - y) < tolerance) {
            break;
        }
        y = yNew;
        iterations++;
    }

    return y;
}

int main() {
    double number;
    std::cout << "Enter a number to find the reciprocal square root of: ";
    std::cin >> number;

    double reciprocalSqrtResult = reciprocalSqrt(number);
    if (reciprocalSqrtResult != -1) {
        std::cout << "The approximate reciprocal square root of " << number << " is " 
                  << std::fixed << std::setprecision(10) << reciprocalSqrtResult << std::endl;
        std::cout << "The approximate square root of " << number << " is " 
                  << std::fixed << std::setprecision(10) << 1.0 / reciprocalSqrtResult << std::endl;
    }

    return 0;
}