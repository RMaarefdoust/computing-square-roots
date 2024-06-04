// Heron's method
#include <iostream>
#include <cmath>
#include <limits>

// Heron's method
template<typename Real>
Real heronSqrt(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    if (number == 0) {
        return 0;
    }

    Real guess = number *0.5;
    Real nextGuess = (guess + number / guess) * 0.5;
    int iterations = 0;

    while (std::abs(nextGuess - guess) > tolerance * (nextGuess + guess) && iterations < maxIterations) {
        guess = nextGuess;
        Real newGuess = number / guess;
        nextGuess = (guess + newGuess) * 0.5;
        iterations++;
    }

    // Using the final value to compensate for potential precision errors
    Real correction = number / nextGuess;
    nextGuess = (nextGuess + correction) * 0.5;

    return nextGuess;
}

int main() {
    using Real = double;
    Real number;
    std::cout << "Enter a number to find the square root of: ";
    std::cin >> number;

    Real sqrtResult = heronSqrt(number);
    if (sqrtResult != -1) {
        std::cout << "The approximate square root of " << number << " is " << sqrtResult << std::endl;
    }

    return 0;
}
