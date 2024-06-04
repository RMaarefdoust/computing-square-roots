#include <iostream>
#include <cmath>
#include <limits>

// Bakhshali method
template<typename Real>
Real bakhshaliSqrt(Real number, Real tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    if (number == 0) {
        return 0;
    }

    // Initial guess
    Real guess = number / 2.0;
    Real difference, nextGuess;
    int iterations = 0;

    do {
        Real guessSquared = guess * guess;
        Real a = (number - guessSquared) / (2.0 * guess);
        Real guessPlusA = guess + a;
        nextGuess = guessPlusA - (a * a) / (2.0 * guessPlusA);
        difference = std::abs(nextGuess - guess);
        guess = nextGuess;
        iterations++;
    } while (difference > tolerance * (nextGuess + guess) && iterations < maxIterations);

    return nextGuess;
}

int main() {
    using Real = double;
    Real number;
    std::cout << "Enter a number to find the square root of: ";
    std::cin >> number;

    Real sqrtResult = bakhshaliSqrt(number);
    if (sqrtResult != -1) {
        std::cout << "The approximate square root of " << number << " is " << sqrtResult << std::endl;
    }

    return 0;
}
