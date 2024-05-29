#include <iostream>
#include <cmath>

// Heron's method with estimation function as parameter
double heronSqrt(double number, double (*estimate)(double), double tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    double guess = estimate(number); // Use estimation function to get initial guess
    double nextGuess = (guess + number / guess) / 2.0;
    int iterations = 0;

    while (std::abs(nextGuess - guess) > tolerance && iterations < maxIterations) {
        guess = nextGuess;
        nextGuess = (guess + number / guess) / 2.0;
        iterations++;
    }

    return nextGuess;
}

// Scalar estimation methods
double decimalScalarEstimate(double S) {
    // Implement Decimal Scalar estimation method
    // Example: Take the average of S and 1
    return (S + 1) / 2.0;
}

double linearEstimate(double S) {
    // Implement Linear estimation method
    // Example: Take S / 2
    return S / 2.0;
}

// Hyperbolic estimation method
double hyperbolicEstimate(double S) {
    // Implement Hyperbolic estimation method
    // Example: Hyperbolic estimate formula
    double a = S / 100;
    return ((-190 / (a + 20)) + 10) * 10;
}

// Binary estimation method
double binaryEstimate(double S) {
    // Implement Binary estimation method
    // Example: Binary estimate formula
    double a = S / 100;
    return (0.5 + 0.5 * a) * sqrt(2);
}

int main() {
    double number;
    std::cout << "Enter a number to find the square root of: ";
    std::cin >> number;

    // Perform Heron's method with different estimation methods
    double sqrtResultDecimalScalar = heronSqrt(number, decimalScalarEstimate);
    double sqrtResultLinear = heronSqrt(number, linearEstimate);
    double sqrtResultHyperbolic = heronSqrt(number, hyperbolicEstimate);
    double sqrtResultBinary = heronSqrt(number, binaryEstimate);

    // Output the results
    std::cout << "Decimal Scalar estimate result: " << sqrtResultDecimalScalar << std::endl;
    std::cout << "Linear estimate result: " << sqrtResultLinear << std::endl;
    std::cout << "Hyperbolic estimate result: " << sqrtResultHyperbolic << std::endl;
    std::cout << "Binary estimate result: " << sqrtResultBinary << std::endl;

    return 0;
}
