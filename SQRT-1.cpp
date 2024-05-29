//Heron's method
#include <iostream>
#include <cmath>

// Heron's method
template<typename Real>
Real heronSqrt(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    Real guess = number / 2.0;
    Real nextGuess = (guess + number / guess) / 2.0;
    int iterations = 0;

    while (std::abs(nextGuess - guess) > tolerance && iterations < maxIterations) {
        guess = nextGuess;
        nextGuess = (guess + number / guess) / 2.0;
        iterations++;
    }

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
