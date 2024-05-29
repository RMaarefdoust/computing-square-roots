#include <iostream>
#include <cmath>
#include <iomanip>

// Function to calculate the square root using the Newton-Raphson method
template<typename Real>
std::pair<Real, int> newtonRaphsonSqrt(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return {-1, -1};
    }

    Real x0 = number / 2.0;  // Initial guess
    Real x1 = (x0 + number / x0) / 2.0;  // Improved guess using the Newton-Raphson formula
    int iterations = 0;

    while (std::abs(x1 - x0) > tolerance && iterations < maxIterations) {
        x0 = x1;
        x1 = (x0 + number / x0) / 2.0;
        iterations++;
    }

    return {x1, iterations};
}

int main() {
	using Real = double;
    Real number;
    std::cout << "Enter a number to find the square root of: ";
    std::cin >> number;

    auto [sqrtResult, iterations] = newtonRaphsonSqrt(number);
    if (sqrtResult != -1) {
        std::cout << "The approximate square root of " << number << " is " 
                  << std::fixed << std::setprecision(10) << sqrtResult 
                  << " (found in " << iterations << " iterations)" << std::endl;
    }

    return 0;
}