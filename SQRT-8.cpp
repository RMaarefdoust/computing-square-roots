#include <iostream>
#include <cmath>

// Function to approximate square root using Taylor series expansion
double taylorSqrt(double N, double d, int terms = 2) {
    double result = N;
    double term = 1.0;
    double power = 1.0;

    for (int n = 1; n <= terms; ++n) {
        term *= (-1) * (2 * n - 1) * d / (2 * n);
        power *= (2 * N * N);
        result += term / power;
    }

    return result;
}

int main() {
    double N, d;
    std::cout << "Enter N and d (N^2 + d is the number to find square root of): ";
    std::cin >> N >> d;

    double sqrtResult = taylorSqrt(N, d);
    std::cout << "The approximate square root of " << N * N + d << " is: " << sqrtResult << std::endl;

    return 0;
}
