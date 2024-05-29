#include <iostream>
#include <cmath>

// Bakhshali method
double bakhshaliSqrt(double number, double tolerance = 1e-7, int maxIterations = 1000) {
    if (number < 0) {
        std::cerr << "Error: Negative input to sqrt function." << std::endl;
        return -1;
    }

    // Initial guess
    double guess = number / 2.0;
    double difference, nextGuess;
    int iterations = 0;

    do {
        double a = (number - guess * guess) / (2.0 * guess);
        nextGuess = guess + a - (a * a) / (2.0 * (guess + a));
        difference = std::abs(nextGuess - guess);
        guess = nextGuess;
        iterations++;
    } while (difference > tolerance && iterations < maxIterations);

    return nextGuess;
}

int main() {
    double number;
    std::cout << "Enter a number to find the square root of: ";
    std::cin >> number;

    double sqrtResult = bakhshaliSqrt(number);
    if (sqrtResult != -1) {
        std::cout << "The approximate square root of " << number << " is " << sqrtResult << std::endl;
    }

    return 0;
}
